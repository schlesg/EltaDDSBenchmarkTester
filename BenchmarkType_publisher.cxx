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

int main(int argc, char *argv[])
{
	int buffer_count = 0;
	int verbosity = 0;
	int pubRate = 100;

	if (argc >= 2) {
		buffer_count = atoi(argv[1]);
	}
	if (argc >= 3) {
		pubRate = atoi(argv[2]);
	}
	if (argc >= 4) {
		verbosity = atoi(argv[3]);
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

	// RTI Connext provides a finalize_participant_factory() method
	// if you want to release memory used by the participant factory singleton.
	// Uncomment the following line to release the singleton:
	//
	// dds::domain::DomainParticipant::finalize_participant_factory();

	return 0;
}

