#include "BenchmarkType_subscriber.hpp"
#include <functional>
#include <chrono>
#include <future>
#include <cstdio>
#include "BenchmarkType.hpp"

const std::string BenchmarkTypeSubscriber::TOPIC_NAME = "L3";

BenchmarkTypeSubscriber::BenchmarkTypeSubscriber(DDS_DomainId_t domain_id, int thread_pool_size, int verbosity)
	: receiver_(dds::core::null)
{
	// Create a DomainParticipant with default Qos
	dds::domain::DomainParticipant participant(domain_id);

	// Create a Topic -- and automatically register the type
	dds::topic::Topic<BenchmarkMessageType> topic(participant, TOPIC_NAME);

	// Create a DataReader with default Qos (Subscriber created in-line)
	receiver_ = dds::sub::DataReader<BenchmarkMessageType>(dds::sub::Subscriber(participant), topic);

	// DataReader status condition: to process the reception of samples
	dds::core::cond::StatusCondition reader_status_condition(receiver_);
	reader_status_condition.enabled_statuses(dds::core::status::StatusMask::data_available());
	reader_status_condition->handler(DataAvailableHandler(*this));
	// Change insert to subscriber
	async_waitset_ = rti::core::cond::AsyncWaitSet(rti::core::cond::AsyncWaitSetProperty().thread_pool_size(thread_pool_size));
	async_waitset_.attach_condition(reader_status_condition);
	async_waitset_.start();

	totalDiff_ = 0;
	verbosity_ = verbosity;
	now_ = std::chrono::system_clock::now();
}

void BenchmarkTypeSubscriber::printResult()
{
	if (received_count() != 0)
	{
		std::cout << "latency average microsec = " << (totalDiff_ / received_count());
		std::cout << "  number of received messages = " << received_count();
		std::cout << "  number of received messages per seconds = " << (received_count() / getSecFromStart());
		std::cout << "  kilo bytes per seconds = " << (received_countBytes() / getSecFromStart())<<std::endl;
	}
}

void BenchmarkTypeSubscriber::process_received_samples()
{
	// Take all samples This will reset the StatusCondition
	dds::sub::LoanedSamples<BenchmarkMessageType> samples = receiver_.take();

	// Release status condition in case other threads can process outstanding
	// samples
	async_waitset_.unlock_condition(dds::core::cond::StatusCondition(receiver_));

	// Process sample
	for (dds::sub::LoanedSamples<BenchmarkMessageType>::iterator sample_it = samples.begin(); sample_it != samples.end(); sample_it++)
	{
		if (sample_it->info().valid())
		{
			std::chrono::time_point<std::chrono::system_clock> now = std::chrono::system_clock::now();
			auto duration = now.time_since_epoch();
			auto microseconds = std::chrono::duration_cast<std::chrono::microseconds>(duration);

			if (verbosity_ == 1)
			{
				std::cout << sample_it->data().seqNum() << " microsec diff  = " <<
					microseconds.count() - sample_it->data().sourceTimestampMicrosec() << std::endl;
			}

			totalDiff_ += (microseconds.count() - sample_it->data().sourceTimestampMicrosec());
		}
	}
}

int BenchmarkTypeSubscriber::received_count()
{
	return receiver_->datareader_protocol_status().received_sample_count().total();
}


double BenchmarkTypeSubscriber::received_countBytes()
{
	return receiver_->datareader_protocol_status().received_sample_bytes().total() / 1000;//K
}

double BenchmarkTypeSubscriber::getSecFromStart()
{
	std::chrono::time_point<std::chrono::system_clock> end = std::chrono::system_clock::now();
	double diff = std::chrono::duration_cast<std::chrono::seconds>(end - now_).count();
	return diff;
}

BenchmarkTypeSubscriber::~BenchmarkTypeSubscriber()
{
	async_waitset_.detach_condition(dds::core::cond::StatusCondition(receiver_));
}