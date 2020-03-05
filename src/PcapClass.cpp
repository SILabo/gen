#include "PcapClass.hpp"

constexpr auto max_size = (512 * 1024 * 1024 * 2);

namespace
{
    std::array<char, max_size> pcap_buff;
}

PcapClass::PcapClass()
{
}
PcapClass::~PcapClass()
{
}
