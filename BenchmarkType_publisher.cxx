#include <iostream>
#include <dds/pub/ddspub.hpp>
#include <rti/util/util.hpp> // for sleep()
#include "BenchmarkType.hpp"
#include <dds/core/ddscore.hpp>

#include <chrono>
#include <thread>

class BenchmarkMessageTypeWriterListener : public dds::pub::NoOpDataWriterListener<BenchmarkMessageType>
{
private:
	bool _isMatch;

public:

	BenchmarkMessageTypeWriterListener()
	{
		_isMatch = false;
	}

	void on_publication_matched(dds::pub::DataWriter<BenchmarkMessageType>& writer, const dds::core::status::PublicationMatchedStatus& status)
	{
		_isMatch = true;
	}

	bool isMatch()
	{
		return _isMatch;
	}
};

void publisher_main(int buffer_count, int pubRate, int verbosity)
{
#pragma region Init DDS
	// Create a DomainParticipant with default Qos
	dds::domain::DomainParticipant participant(0);

	// Create a Topic -- and automatically register the type
	dds::topic::Topic<BenchmarkMessageType> topic(participant, "L1");

	BenchmarkMessageTypeWriterListener listener;

	// Create a DataWriter with default Qos (Publisher created in-line)
	dds::pub::DataWriter<BenchmarkMessageType> writer(dds::pub::Publisher(participant), topic, dds::core::QosProvider::Default().datawriter_qos(), &listener);

	BenchmarkMessageType sample;

	while (!listener.isMatch())
	{
		std::this_thread::sleep_for(std::chrono::milliseconds(50));
	}
#pragma endregion

	// resize the sample buffer
	sample.buffer().resize(buffer_count);

	std::cout << "Starting to write BenchmarkMessageType  " << std::endl;

	for (int count = 0; true; count++)
	{
		sample.seqNum() = count;

		std::chrono::time_point<std::chrono::system_clock> now = std::chrono::system_clock::now();
		auto duration = now.time_since_epoch();
		auto microseconds = std::chrono::duration_cast<std::chrono::microseconds>(duration);
		sample.sourceTimestampMicrosec() = microseconds.count();


		if (verbosity == 0)
			std::cout << "Writing BenchmarkMessageType, count " << count << std::endl;

		writer.write(sample);

		std::this_thread::sleep_for(std::chrono::milliseconds(1000/pubRate));
	}
}

void printUsage()
{
	const std::string USAGE(
		"BenchmarkType_publisher [options]\n"
		"Options:\n"
		"\t-d, -domainId: Domain ID (default 0)\n"
		"\t-b, -bufferCount: Size of buffer message to send (default 0)\n"
		"\t-r, -rate: Publisher massage rate ""exiting (default 100)\n");

	srand(time(NULL));
}

int main(int argc, char *argv[])
{
	int buffer_count = 0;
	int verbosity = 0;
	int pubRate = 10;
	int domain_id = 0;

	for (int i = 0; i < argc; i++)
	{
		if (strcmp(argv[i], "-d") == 0 || strcmp(argv[i], "-domainId") == 0)
		{
			if (i != argc - 1)
			{
				domain_id = atoi(argv[++i]);
			}
		}

		else if (strcmp(argv[i], "-b") == 0 || strcmp(argv[i], "-bufferCount") == 0)
		{
			if (i != argc - 1)
			{
				buffer_count = atoi(argv[++i]);
			}
		}
		else if (strcmp(argv[i], "-r") == 0 || strcmp(argv[i], "-rate") == 0)
		{
			if (i != argc - 1)
			{
				pubRate = atoi(argv[++i]);
			}
		}
		else if (strcmp(argv[i], "-h") == 0 || strcmp(argv[i], "-help") == 0)
		{
			printUsage();
			return 0;
		}
	}

	try
	{
		publisher_main(buffer_count, pubRate, verbosity);
	}
	catch (const std::exception& ex)
	{
		// This will catch DDS exceptions
		std::cerr << "Exception in publisher_main(): " << ex.what() << std::endl;
		return -1;
	}

	dds::domain::DomainParticipant::finalize_participant_factory();

	return 0;
}

