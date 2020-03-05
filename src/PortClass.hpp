#include "main.hpp"

class PortClass {

public:
	PortClass();
	~PortClass();
	void ring_reset();

private:
	uint64_t wptr;
	uint64_t rptr;

	struct GlobalHeader {
		uint32_t magic_number;
		uint16_t version_major;
		uint16_t version_minor;
		uint32_t thiszone;
		uint32_t sigfigs;
		uint32_t snaplen;
		uint32_t network;
	};
	struct MetaHeader {
		uint8_t meta[16];
	};
	struct PacketHeader {
		uint32_t ts_sec;
		uint32_t ts_usec;
		uint32_t incl_len;
		uint32_t orig_len;
	};
};
















