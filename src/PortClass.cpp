#include "PortClass.hpp"

constexpr auto max_size = (512 * 1024 * 1024 * 2);

namespace
{
    std::array<char, max_size> raw_buff1;
    std::array<char, max_size> raw_buff2;
    std::array<char, max_size> raw_buff3;
    std::array<char, max_size> raw_buff4;
}

PortClass::PortClass()
{
    wptr = 0;
    rptr = 0;
}
PortClass::~PortClass()
{
}
void PortClass::ring_reset()
{
    wptr = 0;
    rptr = 0;
}




