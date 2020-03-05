#include <cstdint>
#include <string>

class Layer4 {

public:
	std::string tag;
	uint32_t udp_src_port;
	uint32_t udp_dst_port;
	uint32_t tcp_src_port;
	uint32_t tcp_dst_port;
	uint32_t sctp_src_port;
	uint32_t sctp_dst_port;

	Layer4();
	~Layer4();
};

