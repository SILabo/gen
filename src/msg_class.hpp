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
		std::cout << "MsgClass Function" << std::endl;
		std::lock_guard<std::mutex> lock(this->mu);
		std::cout << "Thread #" << 3 << ": on CPU " << sched_getcpu() << std::endl;

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

