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
}

MsgClass::~MsgClass()
{
}



}  // namespace egen

