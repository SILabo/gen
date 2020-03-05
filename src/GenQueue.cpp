/**
 * File Name   : message_parser_json.hpp
 * Auther      : Shinji Ikuta
 * Copyright   : © 2020 Artiza Networks, Inc.
 * Description :
 * Email       : ikuta_shinji@artiza.co.jp
 */

#include "GenQueue.hpp"

bool GenQueue::push(std::queue<RawData*> q, std::mutex* mu, RawData* raw)
{
    bool ret = false;

    if ((uint32_t)q.size() < QueueMax-1)
    {
        q.push(raw);
        ret = 1;
    }
    else
    {
        std::cout << "queue full !!!" << std::endl;
    }
    mu->unlock();

    return ret;
}

RawData* GenQueue::front(std::queue<RawData*> q, std::mutex* mu, RawData* raw)
{
    RawData* r;

    mu->lock();
    r = q.front();
    mu->unlock();

    return r;
}

void GenQueue::pop(std::queue<RawData*> q, std::mutex mu, RawData* raw)
{
    int ret = 0;

    mu.lock();
    q.pop();
    mu.unlock();
}
