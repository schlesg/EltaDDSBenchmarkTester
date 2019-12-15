#include <algorithm>
#include <iostream>

#include <dds/sub/ddssub.hpp>
#include <dds/core/ddscore.hpp>
// Or simply include <dds/dds.hpp> 

#include "BenchmarkType.hpp"

class BenchmarkMessageTypeReaderListener : public dds::sub::NoOpDataReaderListener<BenchmarkMessageType> {
public:

	BenchmarkMessageTypeReaderListener() : count_(0)
	{
	}

	void on_data_available(dds::sub::DataReader<BenchmarkMessageType>& reader)
	{
		// Take all samples
		dds::sub::LoanedSamples<BenchmarkMessageType> samples = reader.take();

		for (dds::sub::LoanedSamples<BenchmarkMessageType>::iterator sample_it = samples.begin();
			sample_it != samples.end(); sample_it++) {

			if (sample_it->info().valid()) {
				count_++;
				//std::cout << sample_it->data() << std::endl;

				std::chrono::time_point<std::chrono::system_clock> now = std::chrono::system_clock::now();
				auto duration = now.time_since_epoch();

				//auto seconds = std::chrono::duration_cast<std::chrono::seconds>(duration);
				//duration -= seconds;
				//auto milliseconds = std::chrono::duration_cast<std::chrono::milliseconds>(duration);
				//duration -= milliseconds;
				auto microseconds = std::chrono::duration_cast<std::chrono::microseconds>(duration);
				//duration -= microseconds;
				//auto nanoseconds = std::chrono::duration_cast<std::chrono::nanoseconds>(duration);

				std::cout << sample_it->data().seqNum() << " microsec diff = " << microseconds.count() - sample_it->data().sourceTimestampMicrosec() << std::endl;
				//std::cout << sample_it->data().sourceTimestampMillisec() << ":" << sample_it->data().sourceTimestampMicrosec() << ":" << sample_it->data().sourceTimestampNanosec() << std::endl;
				//std::cout << milliseconds.count() << ":" << microseconds.count() << ":" << microseconds.count() << std::endl << std::endl;

				/*uint64_t sampleTime = sample_it->data().sourceTimestampNanosec();
				uint64_t now = std::chrono::duration_cast<std::chrono::nanoseconds> (std::chrono::high_resolution_clock::now().time_since_epoch()).count();

				std::cout << "SampleTime :" << sampleTime << std::endl;
				std::cout << "nowTime :" << now << std::endl;
				std::cout << "Time difference: " << (now - sampleTime) << " nanoseconds" << std::endl;*/
				
			}
		}
	}

	int count() const
	{
		return count_;
	}

private:
	int count_;
};

void subscriber_main(int sample_count)
{
	// Create a DomainParticipant with default Qos
	dds::domain::DomainParticipant participant(0);

	// Create a Topic -- and automatically register the type
	dds::topic::Topic<BenchmarkMessageType> topic(participant, "L1");

	// Create a DataReader with default Qos (Subscriber created in-line)
	BenchmarkMessageTypeReaderListener listener;
	dds::sub::DataReader<BenchmarkMessageType> reader(
		dds::sub::Subscriber(participant),
		topic,
		dds::core::QosProvider::Default().datareader_qos(),
		&listener,
		dds::core::status::StatusMask::data_available());

	while (listener.count() < sample_count || sample_count == 0) 
	{
		//std::cout << "BenchmarkMessageType subscriber sleeping for 4 sec..." << std::endl;

		rti::util::sleep(dds::core::Duration(4));
	}

	// Unset the listener to allow the reader destruction
	// (rti::core::ListenerBinder can do this automatically)
	reader.listener(NULL, dds::core::status::StatusMask::none());
}

int main(int argc, char *argv[])
{

	int sample_count = 0; // infinite loop

	if (argc >= 2) {
		sample_count = atoi(argv[2]);
	}

	// To turn on additional logging, include <rti/config/Logger.hpp> and
	// uncomment the following line:
	// rti::config::Logger::instance().verbosity(rti::config::Verbosity::STATUS_ALL);

	try
	{
		subscriber_main(sample_count);
	}
	catch (const std::exception& ex)
	{
		// This will catch DDS exceptions
		std::cerr << "Exception in subscriber_main(): " << ex.what() << std::endl;
		return -1;
	}

	// RTI Connext provides a finalize_participant_factory() method
	// if you want to release memory used by the participant factory singleton.
	// Uncomment the following line to release the singleton:
	//
	// dds::domain::DomainParticipant::finalize_participant_factory();

	return 0;
}

