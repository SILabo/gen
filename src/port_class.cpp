/**
 * File Name   : port_class.cpp
 * Auther      : Shinji Ikuta
 * Copyright   : © 2020 Artiza Networks, Inc.
 * Description :
 * Email       : ikuta_shinji@artiza.co.jp
 */

#include "port_class.hpp"

namespace egen
{

PortClass::PortClass(RawDataClass* raw, GenQueue* que)
{
    this->raw = raw;
    this->que = que;

    this->port_cpuid = 0;
}

PortClass::~PortClass()
{
}

int PortClass::get_cpuid()
{
    return this->port_cpuid;
}

}  // namespace egen

