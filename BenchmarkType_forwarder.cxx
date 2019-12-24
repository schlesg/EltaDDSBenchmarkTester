#include <dds/pub/ddspub.hpp>
#include "BenchmarkType_forwarder.hpp"
#include "BenchmarkType.hpp"

BenchmarkType_forwarder::BenchmarkType_forwarder(DDS_DomainId_t domain_id, int thread_pool_size, std::string readFromTopic, std::string writeToTopic)
	: receiver_(dds::core::null)
{
	// Create a DomainParticipant with default Qos
	dds::domain::DomainParticipant participant(domain_id);

	// Create a Topic -- and automatically register the type
	dds::topic::Topic<BenchmarkMessageType> topicFrom(participant, readFromTopic);
	dds::topic::Topic<BenchmarkMessageType> topicTo(participant, writeToTopic);

	// Create a DataReader with default Qos (Subscriber created in-line)
	receiver_ = dds::sub::DataReader<BenchmarkMessageType>(dds::sub::Subscriber(participant),topicFrom);

	// Create a DataWriter with default Qos (Publisher created in-line)
	writer_ = new dds::pub::DataWriter<BenchmarkMessageType>(dds::pub::Publisher(participant), topicTo, dds::core::QosProvider::Default().datawriter_qos());

	// DataReader status condition: to process the reception of samples
	dds::core::cond::StatusCondition reader_status_condition(receiver_);
	reader_status_condition.enabled_statuses(dds::core::status::StatusMask::data_available());
	reader_status_condition->handler(DataAvailableHandler(*this));
	rti::core::cond::AsyncWaitSet async_waitset(rti::core::cond::AsyncWaitSetProperty().thread_pool_size(thread_pool_size));
	async_waitset_.attach_condition(reader_status_condition);
	async_waitset.start();
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
			writer_->write(sample_it->data());
		}
	}
}
BenchmarkType_forwarder::~BenchmarkType_forwarder()
{
	async_waitset_.detach_condition(dds::core::cond::StatusCondition(receiver_));
}