#include <fstream>
#include <string>
#include "pktfil.hpp"

pktfil::pktfil()
{
	packet_num = 0;
	offset = 0;

}

pktfil::~pktfil()
{

}

bool pktfil::isGheader(uint8_t* ram1)
{
	bool judge =true;
	GlobalHeader* g;

	g = (GlobalHeader*)ram1 + this->offset;

	std::cout << "magic_number:" << g->magic_number << std::endl;
	std::cout << "version_major:" << g->version_major << std::endl;
	std::cout << "version_minor:" << g->version_minor << std::endl;
	std::cout << "thiszone:" << g->thiszone << std::endl;
	std::cout << "sigfigs:" << g->sigfigs << std::endl;
	std::cout << "snaplen:" << g->snaplen << std::endl;
	std::cout << "network:" << g->network << std::endl;

	this->offset += 24;

	return judge;
}

bool pktfil::get_meta(uint8_t* ram1)
{
	bool judge = true;
	uint8_t* g;

	g = ram1 + this->offset;
	memcpy(this->meta_buff, g, 16);
	this->offset += 16;

	return judge;
}

uint32_t pktfil::get_packet_size(uint8_t* ram1)
{
	PacketHeader* g;

	g = (PacketHeader*)(ram1 + this->offset);
	std::cout << "incl_len:" << g->incl_len << std::endl;

	return g->incl_len;
}

uint8_t* pktfil::isFilter(uint8_t* ram1, uint64_t sz, Filter* fil)
{
	uint8_t* judge = NULL;

	struct stPaket {
		PacketHeader ph;
		VlanHeader vlanh;
		Ipv4Header ipv4h;
		Ipv6Header ipv6h;
		L4Header l4h;
	}*pkthead;

	pkthead = (stPaket*)ram1;




	return judge;
}





