/**
 * File Name   : thread.hpp
 * Auther      : Shinji Ikuta
 * Copyright   : © 2020 Artiza Networks, Inc.
 * Description :
 * Email       : ikuta_shinji@artiza.co.jp
 */
#pragma once


#include <iostream>
#include <thread>
#include <string>
#include <unistd.h>
#include <functional>
#include "pthread.h"

namespace egen
{

class ThreadClass
{
public:
	ThreadClass(std::string name, std::function <void(void)> func, size_t cpuId);
	ThreadClass(std::string name, std::function <void(void)> func);

private:
	void setAffinity(std::thread& thread, std::size_t cpuId);
	std::string name;
	std::thread thread;
	std::function< void(void) > func;
	size_t cpuId;
};

}  // namespace egen
