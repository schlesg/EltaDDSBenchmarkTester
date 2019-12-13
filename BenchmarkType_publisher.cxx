#include <iostream>
#include <dds/pub/ddspub.hpp>
#include <rti/util/util.hpp> // for sleep()
#include "BenchmarkType.hpp"

#include <chrono>
#include <thread>

void publisher_main(int buffer_count, int sample_count, int verbosity, int sleepMili)
{
	#pragma region Init DDS
    // Create a DomainParticipant with default Qos
    dds::domain::DomainParticipant participant (0);

    // Create a Topic -- and automatically register the type
    dds::topic::Topic<BenchmarkMessageType> topic (participant, "L1");

    // Create a DataWriter with default Qos (Publisher created in-line)
    dds::pub::DataWriter<BenchmarkMessageType> writer(dds::pub::Publisher(participant), topic);

    BenchmarkMessageType sample;
	#pragma endregion

	std::cout << std::chrono::duration_cast<std::chrono::seconds>(std::chrono::system_clock::now().time_since_epoch()).count() << std::endl;
	std::cout << std::chrono::duration_cast<std::chrono::nanoseconds>(std::chrono::system_clock::now().time_since_epoch()).count() << std::endl;
	std::this_thread::sleep_for(std::chrono::milliseconds(sleepMili));
	std::cout << std::chrono::duration_cast<std::chrono::nanoseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
	// resize the sample buffer
	sample.buffer().resize(buffer_count);

	std::cout << "Starting to write BenchmarkMessageType  " << std::endl;
    for (int count = 0; count < sample_count || sample_count == 0; count++) 
	{
		sample.seqNum() = count;
		sample.sourceTimestampSec() = std::chrono::duration_cast<std::chrono::seconds> (std::chrono::high_resolution_clock::now().time_since_epoch()).count();
		sample.sourceTimestampNanosec() = std::chrono::duration_cast<std::chrono::nanoseconds> (std::chrono::system_clock::now().time_since_epoch()).count();

		if(verbosity == 1)
			std::cout << "Writing BenchmarkMessageType, count " << count << std::endl; 

        writer.write(sample);

		std::this_thread::sleep_for(std::chrono::milliseconds(sleepMili));
    }
}

int main(int argc, char *argv[])
{
    int buffer_count = 0;
    int sample_count = 0; // infinite loop
	int verbosity = 0;
	int sleepMili = 1000;

    if (argc >= 2) {
		buffer_count = atoi(argv[1]);
    }
    if (argc >= 3) {
        sample_count = atoi(argv[2]);
    }
	if (argc >= 4) {
		verbosity = atoi(argv[3]);
	}
	if (argc >= 5) {
		sleepMili = atoi(argv[4]);
	}

    try 
	{
        publisher_main(buffer_count, sample_count, verbosity, sleepMili);
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

