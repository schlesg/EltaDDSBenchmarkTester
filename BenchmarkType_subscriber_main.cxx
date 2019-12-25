#include <algorithm>
#include <iostream>
#include <dds/sub/ddssub.hpp>
#include <dds/core/ddscore.hpp>
#include <rti/core/cond/AsyncWaitSet.hpp>
#include "BenchmarkType_subscriber.hpp"

void printUsage()
{
	const std::string USAGE(
		"BenchmarkType_subscriber [options]\n"
		"Options:\n"
		"\t-d, -domainId: Domain ID (default 0)\n"
		"\t-p, -printRate: Print results rate in milliseconds(default 10000 milliseconds - 10 sec)\n"
		"\t-v, -verbosity: verbosity for print. (0) not print (1) print (default 0)\n"
		"\t-t, -threads: Number of threads used to process sample (default 1)\n");

	std::cout << USAGE;
	srand(time(NULL));
}

int main(int argc, char *argv[])
{
	int domain_id = 0;
	int thread_pool_size = 1;
	int printRate = 10000;
	int verbosity = 0;

	for (int i = 0; i < argc; i++)
	{
		if (strcmp(argv[i], "-d") == 0 || strcmp(argv[i], "-domainId") == 0)
		{
			if (i != argc - 1)
			{
				domain_id = atoi(argv[++i]);
			}
		}

		else if (strcmp(argv[i], "-t") == 0 || strcmp(argv[i], "-threads") == 0)
		{
			if (i != argc - 1)
			{
				thread_pool_size = atoi(argv[++i]);
			}
		}
		else if (strcmp(argv[i], "-p") == 0 || strcmp(argv[i], "-printRate") == 0)
		{
			if (i != argc - 1)
			{
				printRate = atoi(argv[++i]);
			}
		}

		else if (strcmp(argv[i], "-v") == 0 || strcmp(argv[i], "-verbosity") == 0)
		{
			if (i != argc - 1)
			{
				verbosity = atoi(argv[++i]);
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
		BenchmarkTypeSubscriber subscriber(domain_id, thread_pool_size, verbosity);
		subscriber.startTimer(printRate);

		while (true)
		{
			//rti::util::sleep(dds::core::Duration(printRate));		
		}
	}
	catch (const std::exception& ex)
	{
		// This will catch DDS exceptions
		std::cerr << "Exception in subscriber_main(): " << ex.what() << std::endl;
		return -1;
	}

	dds::domain::DomainParticipant::finalize_participant_factory();
	return 0;
}

