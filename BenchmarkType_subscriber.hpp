#include <dds/sub/ddssub.hpp>
#include <dds/core/ddscore.hpp>
#include <rti/core/cond/AsyncWaitSet.hpp>
#include <atomic>

class BenchmarkMessageType;
class Timer;

class BenchmarkTypeSubscriber
{
public:
	static const std::string TOPIC_NAME;

	BenchmarkTypeSubscriber(DDS_DomainId_t domain_id, int thread_pool_size, int verbosity);
	void process_received_samples();
	double received_count();
	void printResult();
	double getSecFromStart();
	double received_countBytes();
	void startTimer(int milli);
	void stopTimer();
	double calcSTD();
	~BenchmarkTypeSubscriber();

public:
	// Entities to receive data
	dds::sub::DataReader<BenchmarkMessageType> receiver_;
	// Reference to the AWS used for processing the events
	rti::core::cond::AsyncWaitSet async_waitset_;
	
private:
	std::atomic<unsigned long long> totalDiff_;
	std::atomic<int> verbosity_;
	std::chrono::time_point<std::chrono::system_clock> now_;
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

	DataAvailableHandler(BenchmarkTypeSubscriber &subscriber) : subscriber_(subscriber)
	{
	}

private:
	BenchmarkTypeSubscriber &subscriber_;
};
