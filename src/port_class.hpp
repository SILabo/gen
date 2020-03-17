/**
 * File Name   : port_class.cpp
 * Auther      : Shinji Ikuta
 * Copyright   : © 2020 Artiza Networks, Inc.
 * Description :
 * Email       : ikuta_shinji@artiza.co.jp
 */
#pragma once

#include <queue>
#include "thread.hpp"
#include "raw_data.hpp"
#include "gen_queue.hpp"
#include <sched.h>

namespace egen
{

class PortClass
{
public:

	PortClass(RawDataClass* raw, GenQueue* que);
	~PortClass();

	std::function <void(void)> func = [&]()
	{
		//std::cout << "PortClass Function" << std::endl;

		std::lock_guard<std::mutex> lock(this->mu);
		this->port_cpuid = sched_getcpu();
#if 0
		// for Test
		std::cout << "Thread #" << this->port_cnt << ": on CPU " << this->port_cpuid[this->port_cnt] << std::endl;
#endif

		while (1) {
#if 1
			if (this->que->size(0, 0) != 0)
			{
				this->que->pop(0, 0);
			}
#else
			;
#endif
		}
    };

	int get_cpuid();

private:

	RawDataClass* raw;
	GenQueue* que;
	std::mutex mu;
	int port_cpuid;
};

}  // namespace egen

