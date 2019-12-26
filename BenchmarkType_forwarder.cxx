#include <dds/pub/ddspub.hpp>
#include "BenchmarkType_forwarder.hpp"
#include "BenchmarkType.hpp"
#include "Timer.hpp"

BenchmarkType_forwarder::BenchmarkType_forwarder(DDS_DomainId_t domain_id, int thread_pool_size, std::string readFromTopic, std::string writeToTopic, int verbosity, int forwardersDepth)
	: receiver_(dds::core::null), verbosity_(verbosity), totalDiff_(0), now_(std::chrono::system_clock::now()), forwardersDepth_(forwardersDepth)
{
	// Create a DomainParticipant with default Qos
	dds::domain::DomainParticipant participant(domain_id);

	// Create a Topic -- and automatically register the type
	dds::topic::Topic<BenchmarkMessageType> topicFrom(participant, readFromTopic);
	dds::topic::Topic<BenchmarkMessageType> topicTo(participant, writeToTopic);

	// Create a DataReader with default Qos (Subscriber created in-line)
	receiver_ = dds::sub::DataReader<BenchmarkMessageType>(dds::sub::Subscriber(participant), topicFrom);

	// Create a DataWriter with default Qos (Publisher created in-line)
	writer_ = new dds::pub::DataWriter<BenchmarkMessageType>(dds::pub::Publisher(participant), topicTo, dds::core::QosProvider::Default().datawriter_qos());

	// DataReader status condition: to process the reception of samples
	dds::core::cond::StatusCondition reader_status_condition(receiver_);
	reader_status_condition.enabled_statuses(dds::core::status::StatusMask::data_available());
	reader_status_condition->handler(DataAvailableHandler(*this));
	async_waitset_ = rti::core::cond::AsyncWaitSet(rti::core::cond::AsyncWaitSetProperty().thread_pool_size(thread_pool_size));
	async_waitset_.attach_condition(reader_status_condition);
	async_waitset_.start();

	if (verbosity_ == 1)
	{
		// print every 10 sec
		timer_ = new Timer();
		timer_->start(10000, std::bind(&BenchmarkType_forwarder::printResult, this));
	}
}

void BenchmarkType_forwarder::process_received_samples()
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
			receivedMessageCount_ += 1;
			//TODO not fully thread safe
			//Only write a message each number of forwarders
			if ((receivedMessageCount_ % this->forwardersDepth_) == 0) {
				writer_->write(sample_it->data());
			}
		}
	}
}
BenchmarkType_forwarder::~BenchmarkType_forwarder()
{
	async_waitset_.detach_condition(dds::core::cond::StatusCondition(receiver_));
}

void BenchmarkType_forwarder::printResult()
{
	if (received_count() != 0)
	{
		std::cout << "latency(usec) = " << (totalDiff_ / received_count());
		//std::cout << "  number of received messages = " << received_count();
		std::cout << "  receivedMsg/sec = " << (received_count() / getSecFromStart());
		std::cout << "  pushedMsg/sec = " << (write_count() / getSecFromStart()) << std::endl;
	}
}
double BenchmarkType_forwarder::received_count()
{
	return receiver_->datareader_protocol_status().received_sample_count().total();
}

double BenchmarkType_forwarder::write_count()
{
	return (*writer_)->datawriter_protocol_status().pushed_sample_count().total();
}

double BenchmarkType_forwarder::getSecFromStart()
{
	std::chrono::time_point<std::chrono::system_clock> end = std::chrono::system_clock::now();
	double diff = std::chrono::duration_cast<std::chrono::seconds>(end - now_).count();
	return diff;
}