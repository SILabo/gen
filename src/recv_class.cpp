/**
 * File Name   : recv_class.cpp
 * Auther      : Shinji Ikuta
 * Copyright   : © 2020 Artiza Networks, Inc.
 * Description :
 * Email       : ikuta_shinji@artiza.co.jp
 */


#include "recv_class.hpp"


namespace egen
{


RecvClass::RecvClass()
{

}
RecvClass::~RecvClass()
{

}

void RecvClass::RecvFunc(MsgClass* msg)
{
    //std::cout << "RecvFunc" << std::endl;
    //std::lock_guard<std::mutex> lock(this->mu);
    //std::cout << "Thread #" << 4 << ": on CPU " << sched_getcpu() << std::endl;

    while (1)
    {
        //zeroMQ send & recv
        ;
    }
}


}  // namespace egen
