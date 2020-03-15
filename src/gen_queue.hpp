/**
 * File Name   : message_parser_json.hpp
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
#include <vector>
#include <queue>
#include <mutex>
#include "raw_data.hpp"
#include "packet_class.hpp"

namespace egen
{

class GenQueue
{
public:

    GenQueue(int rawnum, int pktnum);
    ~GenQueue();

    void raw_push(RawDataClass* raw,  int idx);
    void pkt_push(PacketClass* pkt, int idx);
    void raw_pop(RawDataClass* raw,  int idx);
    void pkt_pop(PacketClass* pkt, int idx);
    size_t raw_size(RawDataClass* raw, int idx);
    size_t pkt_size(PacketClass* pkt, int idx);


private:
    static const int QUEUE_MAX = 32;

    int quenum;
    std::queue<RawDataClass*>* qraw[QUEUE_MAX];
    std::queue<PacketClass*>* qpkt[QUEUE_MAX];

    std::mutex mu;
};


}  // namespace egen

