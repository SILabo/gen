#include "RawData.hpp"

RawData::RawData(uint64_t cNum)
{
	user_id = 0;
	capture_ids = new std::vector<CaptureID>(cNum);
	output = new PcapClass();
	output->base_filename = "filename";
	output->range.start = "0";
	output->range.stop = "0";
	output->limit = "0";
	output->split_options.mode = "0";
	output->split_options.filesize = "0";
	output->split_options.seconds_per_file = "0";
	output->split_options.packets_per_file = "0";
	both_direction = false;

	//Filetr Layer2
	filters = new Filter();
	filters->l2.tag = "ether";
	filters->l2.vlan_tags.tpid = 0;
	filters->l2.vlan_tags.vid->start = 0;
	filters->l2.vlan_tags.vid->end = 0;

	//Filetr Layer3
	filters->l3.tag = "ipv4";
	filters->l3.ipv4.src_addr = "0.0.0.0";
	filters->l3.ipv4.dst_addr = "255.255.255.255";
	filters->l3.ipv6.src_addr = "::00";
	filters->l3.ipv6.dst_addr = "FF::FF";

	//Filetr Layer4
	filters->l4.tag = "udp";
	filters->l4.udp_src_port = 0;
	filters->l4.udp_dst_port = 0;
	filters->l4.tcp_src_port = 0;
	filters->l4.tcp_dst_port = 0;
	filters->l4.sctp_src_port = 0;
	filters->l4.sctp_dst_port = 0;
}


RawData::~RawData()
{
}
