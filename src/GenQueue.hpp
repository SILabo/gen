/**
 * File Name   : message_parser_json.hpp
 * Auther      : Shinji Ikuta
 * Copyright   : © 2020 Artiza Networks, Inc.
 * Description :
 * Email       : ikuta_shinji@artiza.co.jp
 */
#pragma once

#include "main.hpp"
#include "RawData.hpp"

namespace
{
    using cmsg = std::vector<char*>;
    const uint32_t QueueMax = 4096;
}

class GenQueue
{
public:
    GenQueue() = default;
    ~GenQueue() = default;

#if 1
    std::queue<RawData*> mpq1;
    std::queue<RawData*> mpq2;
    std::queue<RawData*> mpq3;
    std::queue<RawData*> mpq4;
    std::queue<RawData*> mpq5;

    std::queue<cmsg> pcq1;
    std::queue<cmsg> pcq2;
    std::queue<cmsg> pcq3;
    std::queue<cmsg> pcq4;

    std::mutex mu;
#endif

    bool push(std::queue<RawData*> q, std::mutex* mu, RawData* raw);
    RawData* front(std::queue<RawData*> q, std::mutex* mu, RawData* raw);
    void pop(std::queue<RawData*> q, std::mutex mu, RawData* raw);


private:


};
