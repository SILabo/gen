/**
 * File Name   : thread.cpp
 * Auther      : Shinji Ikuta
 * Copyright   : © 2020 Artiza Networks, Inc.
 * Description :
 * Email       : ikuta_shinji@artiza.co.jp
 */

#include <thread>
#include <string>
#include <unistd.h>
#include <functional>
#include "thread.hpp"

namespace egen
{


ThreadClass::ThreadClass(std::string name, std::function <void(void)> func , size_t cpuId)
{
	this->name = name;
	this->cpuId = cpuId;
	this->func = func;
	this->thread = std::thread([&] {pthread_setname_np(pthread_self(), this->name.c_str()); this->func(); });
	this->setAffinity(this->thread, this->cpuId);
	this->thread.detach();
}

ThreadClass::ThreadClass(std::string name, std::function <void(void)> func)
{
	this->name = name;
	this->cpuId = cpuId;
	this->func = func;
	this->thread = std::thread([&] {pthread_setname_np(pthread_self(), this->name.c_str()); this->func(); });
	this->thread.detach();
}

void ThreadClass::setAffinity(std::thread& thread, std::size_t cpuId)
{
	const unsigned int numOfCpus = std::thread::hardware_concurrency();
	cpu_set_t          mask;
	CPU_ZERO(&mask);
	CPU_SET(cpuId % numOfCpus, &mask);
	const int rc = pthread_setaffinity_np(thread.native_handle(), sizeof(cpu_set_t), &mask);
	if (rc != 0) {
		std::cerr << "Set cpu affinity" << std::endl;
	}
}


}  // namespace egen
