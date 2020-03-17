/**
 * File Name   : pcap_class.cpp
 * Auther      : Shinji Ikuta
 * Copyright   : © 2020 Artiza Networks, Inc.
 * Description :
 * Email       : ikuta_shinji@artiza.co.jp
 */
#pragma once

#include "thread.hpp"
#include "raw_data.hpp"
#include "gen_queue.hpp"
#include <sched.h>

namespace egen
{

class PcapClass
{
public:
	PcapClass(RawDataClass* raw, GenQueue* que);
	~PcapClass();

	std::function <void(void)> func = [&]()
	{
		std::lock_guard<std::mutex> lock(this->mu);
		this->pcap_cpuid = sched_getcpu();
#if 0
		// for Test
		std::cout << "PcapClass Function" << std::endl;
		std::cout << "Thread #" << 1 << ": on CPU " << this->pcap_cpuid << std::endl;
#endif

		while (1) {
			;
		}
	};
	int get_cpuid();

private:

	RawDataClass* raw;
	GenQueue* que;
	std::mutex mu;
	int pcap_cpuid;
};



}  // namespace egen

