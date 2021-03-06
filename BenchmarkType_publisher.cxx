#include <iostream>
#include <dds/pub/ddspub.hpp>
#include <rti/util/util.hpp> // for sleep()
#include <dds/core/ddscore.hpp>
#include "BenchmarkType.hpp"
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

void publisher_main(int bufferSize, int pubRate, int verbosity, int domain_id)
{
#pragma region Init DDS
	// Create a DomainParticipant with default Qos
	dds::domain::DomainParticipant participant(domain_id);

	// Create a Topic -- and automatically register the type
	dds::topic::Topic<BenchmarkMessageType> topic(participant, "L1");

	BenchmarkMessageTypeWriterListener listener;

	// Create a DataWriter with default Qos (Publisher created in-line)
	dds::pub::DataWriter<BenchmarkMessageType> writer(dds::pub::Publisher(participant), topic, dds::core::QosProvider::Default().datawriter_qos(), &listener);

	BenchmarkMessageType sample;
	std::cout << "Publisher initialized with PubRate - " << pubRate<< "Hz ; bufferSize - " << bufferSize << " Bytes" << std::endl;
	while (!listener.isMatch())
	{
		std::this_thread::sleep_for(std::chrono::milliseconds(50));
	}
#pragma endregion

	// resize the sample buffer
	sample.buffer().resize(bufferSize);

	std::cout << "Starting to write... " << std::endl;

	double timeTosleepSec = 1.0 / pubRate;

	for (int count = 0; true; count++)
	{
		sample.seqNum() = count;

		std::chrono::time_point<std::chrono::system_clock> now = std::chrono::system_clock::now();
		auto duration = now.time_since_epoch();
		auto microseconds = std::chrono::duration_cast<std::chrono::microseconds>(duration);
		sample.sourceTimestampMicrosec() = microseconds.count();


		if (verbosity == 1)
			std::cout << "Writing BenchmarkMessageType, count " << count << std::endl;

		writer.write(sample);

		constexpr std::chrono::duration<double> MinSleepDuration(0);
		std::chrono::high_resolution_clock::time_point start = std::chrono::high_resolution_clock::now();
		while (std::chrono::duration<double>(std::chrono::high_resolution_clock::now() - start).count() < timeTosleepSec)
		{
		}
	}
}

void printUsage()
{
	const std::string USAGE(
		"BenchmarkType_publisher [options]\n"
		"Options:\n"
		"\t-d, -domainId: Domain ID (default 0)\n"
		"\t-b, -bufferLength: Size of buffer message to send (default 1000)\n"
		"\t-v, -verbosity: Print verbosity (0) without print (1) print (default 0)\n"
		"\t-r, -rate: Publisher massage rate "" (default 100)\n");
	std::cout << USAGE;

	srand(time(NULL));
}

int main(int argc, char const *argv[])
{
	int bufferSize = 10000;
	int verbosity = 0;
	int pubRate = 100;
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

		if (strcmp(argv[i], "-v") == 0 || strcmp(argv[i], "-verbosity") == 0)
		{
			if (i != argc - 1)
			{
				verbosity = atoi(argv[++i]);
			}
		}

		else if (strcmp(argv[i], "-b") == 0 || strcmp(argv[i], "-bufferLength") == 0)
		{
			if (i != argc - 1)
			{
				bufferSize = atoi(argv[++i]);
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
		publisher_main(bufferSize, pubRate, verbosity, domain_id);
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

