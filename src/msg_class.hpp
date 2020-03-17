/**
 * File Name   : msg_class.cpp
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

class MsgClass
{
public:

	MsgClass(RawDataClass* raw, GenQueue* que);
	~MsgClass();

	std::function <void(void)> func = [&]()
	{
		std::lock_guard<std::mutex> lock(this->mu);
		this->msg_cpuid = sched_getcpu();
#if 0
		// for Test
		std::cout << "Thread #" << 5 << ": on CPU " << this->msg_cpuid << std::endl;
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
	int msg_cpuid;

};


}  // namespace egen

