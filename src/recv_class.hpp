/**
 * File Name   : recv_class.hpp
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
#include <sched.h>
#include "msg_class.hpp"

namespace egen
{

class RecvClass
{
public:
    RecvClass();
    ~RecvClass();

    void RecvFunc(MsgClass* msg);

private:
    std::mutex mu;

};


}  // namespace egen

