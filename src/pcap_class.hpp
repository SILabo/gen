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
		std::cout << "PcapClass Function" << std::endl;
		std::lock_guard<std::mutex> lock(this->mu);
		std::cout << "Thread #" << 2 << ": on CPU " << sched_getcpu() << std::endl;

		while (1) {
			;
		}
	};

private:

	RawDataClass* raw;
	GenQueue* que;
	std::mutex mu;

};



}  // namespace egen

