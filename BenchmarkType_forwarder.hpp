#pragma once

//#include <dds/sub/ddssub.hpp>
//#include <dds/core/ddscore.hpp>
//#include <rti/core/cond/AsyncWaitSet.hpp>
//#include <atomic>
//#include <dds/core/ddscore.hpp>
//#include <rti/zcopy/pub/ZcopyDataWriter.hpp>
//#include <rti/zcopy/sub/ZcopyDataReader.hpp>
//#include <dds/sub/ddssub.hpp>
//#include <dds/pub/ddspub.hpp>

#include "BenchmarkType.hpp"
#include <atomic>
#include <dds/core/ddscore.hpp>
#include <dds/sub/ddssub.hpp>

//class BenchmarkMessageType;
class Timer;

class BenchmarkType_forwarder
{
public:
	BenchmarkType_forwarder(DDS_DomainId_t domain_id, int thread_pool_size, std::string readFromTopic,
		std::string writeToTopic, int verbosity, int forwardersDepth);

	void process_received_samples();
	double received_count();
	void printResult();
	double getSecFromStart();
	double write_count();
	~BenchmarkType_forwarder();

public:
	 //Entities to receive data
	std::shared_ptr <dds::sub::DataReader<BenchmarkMessageType>> receiver_;
	std::shared_ptr <dds::pub::DataWriter<BenchmarkMessageType>> writer_;
	 //Reference to the AWS used for processing the events
	std::shared_ptr<rti::core::cond::AsyncWaitSet> async_waitset_;
private:
	std::atomic<int> verbosity_;
	std::atomic<unsigned long long> totalDiff_;
	std::chrono::time_point<std::chrono::system_clock> now_;
	int forwardersDepth_;
	std::atomic<u_long> receivedMessageCount_ = 0;

	Timer* timer_;
};

class DataAvailableHandler
{
public:
	/* Handles the reception of samples */
	void operator()()
	{
		subscriber_.process_received_samples();
	}

	DataAvailableHandler(BenchmarkType_forwarder &subscriber) : subscriber_(subscriber)
	{
	}

private:
	BenchmarkType_forwarder &subscriber_;
};
