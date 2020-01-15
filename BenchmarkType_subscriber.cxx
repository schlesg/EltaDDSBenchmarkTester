#include "BenchmarkType_subscriber.hpp"
#include <functional>
#include <chrono>
#include <future>
#include <cstdio>
#include <cmath>
#include "BenchmarkType.hpp"
#include "Timer.hpp"

const std::string BenchmarkTypeSubscriber::TOPIC_NAME = "L3";

BenchmarkTypeSubscriber::BenchmarkTypeSubscriber(DDS_DomainId_t domain_id, int thread_pool_size, int verbosity)
	: receiver_(dds::core::null), verbosity_(verbosity), totalDiff_(0), now_(std::chrono::system_clock::now())
{
	// Create a DomainParticipant with default Qos
	dds::domain::DomainParticipant participant(domain_id);

	// Create a Topic -- and automatically register the type
	dds::topic::Topic<BenchmarkMessageType> topic(participant, TOPIC_NAME);

	// Create a DataReader with default Qos (Subscriber created in-line)
	receiver_ = std::make_shared < dds::sub::DataReader<BenchmarkMessageType>>(dds::sub::Subscriber(participant), topic, dds::core::QosProvider::Default().datareader_qos());

	// DataReader status condition: to process the reception of samples
	dds::core::cond::StatusCondition reader_status_condition(*receiver_);
	reader_status_condition.enabled_statuses(dds::core::status::StatusMask::data_available());
	reader_status_condition->handler(DataAvailableHandler(*this));
	// Change insert to subscriber
	async_waitset_ = rti::core::cond::AsyncWaitSet(rti::core::cond::AsyncWaitSetProperty().thread_pool_size(thread_pool_size));
	async_waitset_.attach_condition(reader_status_condition);
	async_waitset_.start();
}
void BenchmarkTypeSubscriber::startTimer(int milli)
{
	timer_ = new Timer();
	timer_->start(milli, std::bind(&BenchmarkTypeSubscriber::printResult, this));
}
void BenchmarkTypeSubscriber::stopTimer()
{
	timer_->stop();
}
double BenchmarkTypeSubscriber::calcSTD()
{
	//double d = 1.0;
	//double length = received_count();
	//return sqrt((totalSquDiff_ -(totalDiff_ * totalDiff_) / length) *(d / (length - 1)));
	return 0;
}

void BenchmarkTypeSubscriber::printResult()
{
	if (received_count() != 0)
	{
		std::cout << "latency(usec) = " << (totalDiff_ / received_count());
		std::cout << " STD = " << calcSTD();
		//std::cout << "  number of received messages = " << received_count();
		std::cout << "  msg/sec = " << (received_count() / getSecFromStart());
		std::cout << "  kb/sec = " << (received_countBytes() / getSecFromStart()) << std::endl;
	}
}

void BenchmarkTypeSubscriber::process_received_samples()
{
	// Take all samples This will reset the StatusCondition
	auto samples = receiver_->take();

	// Release status condition in case other threads can process outstanding
	// samples
	async_waitset_.unlock_condition(dds::core::cond::StatusCondition(*receiver_));

	// Process sample
	for (auto& sample : samples) {
		if (sample->info().valid())
		{
			std::chrono::time_point<std::chrono::system_clock> now = std::chrono::system_clock::now();
			auto duration = now.time_since_epoch();
			auto microseconds = std::chrono::duration_cast<std::chrono::microseconds>(duration);

			if (verbosity_ == 1)
			{
				std::cout << sample.data().root().seqNum() << " microsec diff  = " <<
					microseconds.count() - sample->data().root().sourceTimestampMicrosec() << std::endl;
				std::cout << "received size" << sample->data().root().get_buffer_size() << std::endl;
			}

			totalDiff_ += (microseconds.count() - sample->data().root().sourceTimestampMicrosec());
		}
	}
}

double BenchmarkTypeSubscriber::received_count()
{
	return (*receiver_)->datareader_protocol_status().received_sample_count().total();
}


double BenchmarkTypeSubscriber::received_countBytes()
{
	return (*receiver_)->datareader_protocol_status().received_sample_bytes().total() / 1000;//K
}

double BenchmarkTypeSubscriber::getSecFromStart()
{
	std::chrono::time_point<std::chrono::system_clock> end = std::chrono::system_clock::now();
	double diff = std::chrono::duration_cast<std::chrono::seconds>(end - now_).count();
	return diff;
}

BenchmarkTypeSubscriber::~BenchmarkTypeSubscriber()
{
	async_waitset_.detach_condition(dds::core::cond::StatusCondition(*receiver_));
}