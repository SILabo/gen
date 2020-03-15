/**
 * File Name   : gen_queue.cpp
 * Auther      : Shinji Ikuta
 * Copyright   : © 2020 Artiza Networks, Inc.
 * Description :
 * Email       : ikuta_shinji@artiza.co.jp
 */

#include "gen_queue.hpp"


namespace egen
{


GenQueue::GenQueue(int rawnum, int pktnum)
{
    if ((rawnum + pktnum ) > QUEUE_MAX)
    {
        std::cerr << "vector number is out of range " << std::endl;
        return;
    }

    for (int i = 0; i < rawnum ; i++)
    {
        this->qraw[i] = new std::queue<RawDataClass*>;
    }
    for (int i = 0; i < pktnum ; i++)
    {
        this->qpkt[i] = new std::queue<PacketClass*>;
    }


}

GenQueue::~GenQueue()
{
}

void GenQueue::raw_push(RawDataClass* raw, int idx)
{
    this->mu.lock();
    this->qraw[idx]->push(raw);
    this->mu.unlock();
}
void GenQueue::pkt_push(PacketClass* pkt,int idx)
{
    this->mu.lock();
    this->qpkt[idx]->push(pkt);
    this->mu.unlock();
}

void GenQueue::raw_pop(RawDataClass* raw, int idx)
{
    this->mu.lock();
    this->qraw[idx]->pop();
    this->mu.unlock();
}
void GenQueue::pkt_pop(PacketClass* p, int idx)
{
    this->mu.lock();
    this->qpkt[idx]->pop();
    this->mu.unlock();
}
size_t GenQueue::raw_size(RawDataClass* raw, int idx)
{
    size_t sz;

    this->mu.lock();
    sz = this->qraw[idx]->size();
    this->mu.unlock();

    return sz;
}
size_t GenQueue::pkt_size(PacketClass* p, int idx)
{
    size_t sz;

    this->mu.lock();
    sz = this->qpkt[idx]->size();
    this->mu.unlock();

    return sz;
}


}  // namespace egen
