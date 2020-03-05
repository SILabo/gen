#include <cstdint>
#include <fstream>
#include <iostream>
#include <limits>
#include <numeric>
#include <regex>
#include <string>
#include <vector>
#include "Filter.hpp"

enum {
    UDP_PROTOCOL = 0x11,
    TCP_PROTOCOL = 0x06,
    SCTP_PROTOCOL = 0x84,
};
struct GlobalHeader {
    uint32_t    magic_number;
    uint16_t    version_major;
    uint16_t    version_minor;
    int32_t     thiszone;
    uint32_t    sigfigs;
    uint32_t    snaplen;
    uint32_t    network;
};
static_assert(sizeof(GlobalHeader) == 24, "sizeof(GlobalHeader) != 24");

struct MetaHeader {
    uint8_t meta_bytes[16];      //!< MetaHeader bytes
};
static_assert(sizeof(MetaHeader) == 16, "sizeof(MetaHeader) != 16");

struct PacketHeader {
    uint32_t    ts_sec;
    int32_t     ts_usec;
    uint32_t    incl_len;
    uint32_t    orig_len;
};
static_assert(sizeof(PacketHeader) == 16, "sizeof(PacketHeader) != 16");

struct VlanHeader {
    uint16_t tpid_or_type;
    uint16_t tci;
} __attribute__((packed));
static_assert(sizeof(VlanHeader) == 4, "sizeof(VlanHeader) != 4");

struct Ipv4Addr {
    uint8_t addr_bytes[4];      //!< 32-bit ipv4 addr
} __attribute__((packed));
static_assert(sizeof(Ipv4Addr) == 4, "sizeof(Ipv4Addr) != 4");

struct Ipv4Header {
    uint8_t  ver_hl;            //!< protocol version, header length
    uint8_t  tos;               //!< type-of-service
    uint16_t total_len;         //!< packet total length
    uint16_t id;                //!< identification
    uint16_t flags_fragoff;     //!< flags, fragment offset
    uint8_t  ttl;               //!< time-to-live
    uint8_t  next_protocol;     //!< next protocol
    uint16_t checksum;          //!< checksum
    Ipv4Addr src;               //!< source address
    Ipv4Addr dest;              //!< destination address
    uint8_t  options[0];        //!< options, extension headers
} __attribute__((packed));
static_assert(sizeof(Ipv4Header) == 20, "sizeof(Ipv4Header) != 20");

struct Ipv6Addr {
    uint8_t addr_bytes[16];     //!< 128-bit ipv4 addr
} __attribute__((packed));
static_assert(sizeof(Ipv6Addr) == 16, "sizeof(Ipv6Addr) != 16");

struct Ipv6Header {
    uint32_t ver_tc_flow;       //!< version, traffic class, flow label
    uint16_t payload_len;       //!< payload length
    uint8_t  next_hdr;          //!< next header
    uint8_t  hop_limit;         //!< hop limit
    Ipv6Addr src;               //!< source address
    Ipv6Addr dest;              //!< destination address
} __attribute__((packed));
static_assert(sizeof(Ipv6Header) == 40, "sizeof(Ipv6Header) != 40");

struct L4Header {
    uint16_t port_src;
    uint16_t port_dst;
} __attribute__((packed));
static_assert(sizeof(L4Header) == 4, "sizeof(L4Header) != 4");

class pktfil {

public:

    pktfil();
	~pktfil();

    bool isGheader( uint8_t* ram1);
    bool get_meta(uint8_t* ram1);
    uint32_t get_packet_size(uint8_t* ram1);
    uint8_t* isFilter(uint8_t* ram1, uint64_t sz, Filter* fil);

private:
    uint64_t packet_num;
    uint64_t offset;
    uint8_t meta_buff[16];


};

