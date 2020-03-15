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
		std::cout << "PortClass Function" << std::endl;
		std::lock_guard<std::mutex> lock(this->mu);
		std::cout << "Thread #" << 1 << ": on CPU " << sched_getcpu() << std::endl;

		while (1) {
			if (this->que->raw_size(this->raw, 0) != 0)
			{
				this->que->raw_pop(this->raw, 0);
			}
		}
    };


private:

	RawDataClass* raw;
	GenQueue* que;
	std::mutex mu;
};

}  // namespace egen

