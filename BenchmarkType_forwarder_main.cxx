#include <algorithm>
#include <iostream>
#include <dds/sub/ddssub.hpp>
#include <dds/core/ddscore.hpp>
#include <rti/core/cond/AsyncWaitSet.hpp>
#include "BenchmarkType_forwarder.hpp"

void printUsage()
{
	const std::string USAGE(
		"BenchmarkType_publisher [options]\n"
		"Options:\n"
		"\t-c, -configurationTopic: (1) for write to topic L2 read from topic L1. (2) for write to topic L3 read from topic L2.(default 1) \n"
		"\t-v, -verbosity: Print verbosity (0) without print (1) print (default 0)\n"
		"\t-t, -threads: Number of threads used to process sample (default 1)\n"
		"\t-d, -domainId: DomainID (default 0)\n");

	std::cout << USAGE;
	srand(time(NULL));
}


int main(int argc, char const *argv[])
{
	std::string readFromTopic = "L1";
	std::string writeToTopic = "L2";
	int domain_id = 0;
	int verbosity = 0;
	int thread_pool_size = 1;
	int forwardersDepth = 1;

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

		else if (strcmp(argv[i], "-c") == 0 || strcmp(argv[i], "-configurationTopic") == 0)
		{
			if (i != argc - 1)
			{
				if (atoi(argv[++i]) == 2)
				{
					readFromTopic = "L2";
					writeToTopic = "L3";
				}

			}
		}

		if (strcmp(argv[i], "-f") == 0 || strcmp(argv[i], "-forwardersDepth") == 0)
		{
			if (i != argc - 1)
			{
				forwardersDepth = atoi(argv[++i]);
			}
		}

		else if (strcmp(argv[i], "-t") == 0 || strcmp(argv[i], "-threads") == 0)
		{
			if (i != argc - 1)
			{
				thread_pool_size = atoi(argv[++i]);
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
		BenchmarkType_forwarder forwarder(domain_id, thread_pool_size, readFromTopic, writeToTopic, verbosity, forwardersDepth);
		std::cout << "Forwarder initialized (" << readFromTopic << "-->" << writeToTopic << ") (#" << forwardersDepth << ")" << std::endl;

		while (true)
		{
			//rti::util::sleep(dds::core::Duration(1));
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
