#include "main.hpp"
#include "PortClass.hpp"
#include "PcapClass.hpp"
#include "Filter.hpp"
#include "CaptureID.hpp"

struct MessageHeader {
	uint32_t message_id;
	uint32_t src_id;
	uint32_t dst_id;
	uint32_t seq_no;
	uint32_t ver_no;
} __attribute__((packed));
static_assert(sizeof(MessageHeader) == 20, "sizeof(MessageHeader) != 20");

class MsgClass {
public:
	uint64_t user_id;
	std::vector<CaptureID>* capture_ids;
	PcapClass* output;
	bool both_direction;
	Filter* filters;

	MsgClass();
	~MsgClass();
};
