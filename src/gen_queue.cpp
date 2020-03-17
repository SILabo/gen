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

void GenQueue::push(RawDataClass* raw, int idx)
{
    if (idx >= 0 && idx < 5)
    {
        this->mu.lock();
        this->qraw[idx]->push(raw);
        this->mu.unlock();
    }
    else
    {
        std::cerr << "out of range rawdata Index num" << std::endl;
    }
}

void GenQueue::push(PacketClass* pkt,int idx)
{
    if (idx >= 0 && idx < 4)
    {
        this->mu.lock();
        this->qpkt[idx]->push(pkt);
        this->mu.unlock();
    }
    else
    {
        std::cerr << "out of range packet Index num" << std::endl;
    }
}

void GenQueue::pop(int flags, int idx)
{
    if (flags == 0)
    {
        if (idx >= 0 && idx < 5)
        {
            this->mu.lock();
            this->qraw[idx]->pop();
            this->mu.unlock();
        }
        else
        {
            std::cerr << "out of range rawdata Index num" << std::endl;
        }
    }
    else
    {
        if (idx >= 0 && idx < 5)
        {
            this->mu.lock();
            this->qpkt[idx]->pop();
            this->mu.unlock();
        }
        else
        {
            std::cerr << "out of range packet Index num" << std::endl;
        }
    }

}

size_t GenQueue::size(int flags, int idx)
{
    size_t sz;

    if (flags == 0)
    {
        if (idx >= 0 && idx < 5)
        {
            this->mu.lock();
            sz = this->qraw[idx]->size();
            this->mu.unlock();
        }
        else
        {
            std::cerr << "out of rawdata range Index num" << std::endl;
            return 0;
        }
    }
    else
    {
        if (idx >= 0 && idx < 4)
        {
            this->mu.lock();
            sz = this->qpkt[idx]->size();
            this->mu.unlock();
        }
        else
        {
            std::cerr << "out of packet range Index num" << std::endl;
            return 0;
        }
    }

    return sz;
}


RawDataClass* GenQueue::raw_front(int idx)
{
    RawDataClass* raw;

    if (idx >= 0 && idx < 5)
    {
        this->mu.lock();
        raw = this->qraw[idx]->front();
        this->mu.unlock();
    }
    else
    {
        std::cerr << "out of rawdata range Index num" << std::endl;
        return 0;
    }

    return raw;
}

PacketClass* GenQueue::pkt_front(int idx)
{
    PacketClass* pkt;

    if (idx >= 0 && idx < 4)
    {
        this->mu.lock();
        pkt = this->qpkt[idx]->front();
        this->mu.unlock();
    }
    else
    {
        std::cerr << "out of packet range Index num" << std::endl;
        return 0;
    }

    return pkt;
}

}  // namespace egen
