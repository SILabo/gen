/**
 * File Name   : pcap_class.cpp
 * Auther      : Shinji Ikuta
 * Copyright   : © 2020 Artiza Networks, Inc.
 * Description :
 * Email       : ikuta_shinji@artiza.co.jp
 */

#include "pcap_class.hpp"
#include "raw_data.hpp"
#include "gen_queue.hpp"

namespace egen
{

    PcapClass::PcapClass(RawDataClass* raw, GenQueue* que)
    {
        this->raw = raw;
        this->que = que;
    }

    PcapClass::~PcapClass()
    {
    }


}  // namespace egen

