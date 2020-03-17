/**
 * File Name   : msg_class.cpp
 * Auther      : Shinji Ikuta
 * Copyright   : © 2020 Artiza Networks, Inc.
 * Description :
 * Email       : ikuta_shinji@artiza.co.jp
 */

#include "msg_class.hpp"

namespace egen
{

MsgClass::MsgClass(RawDataClass* raw, GenQueue* que)
{
    this->raw = raw;
    this->que = que;
    this->msg_cpuid = 0;
}

MsgClass::~MsgClass()
{
}

int MsgClass::get_cpuid()
{
    return this->msg_cpuid;
}



}  // namespace egen

