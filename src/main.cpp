#include <iostream>
#include <thread>
#include <vector>
#include <mutex>
#include <chrono>
#include <unistd.h>
#include "thread.hpp"
#include "msg_class.hpp"
#include "port_class.hpp"
#include "pcap_class.hpp"
#include "gen_queue.hpp"
#include "recv_class.hpp"

using namespace egen;

int main()
{
	RawDataClass* raw;
	raw = new RawDataClass();

	GenQueue* que;
	que = new GenQueue(5, 4);

	//for test
	que->raw_push(raw,0);
	que->raw_push(raw,0);

	//-----------------------------------
	std::string name = "PortThread";
	size_t cpuId = 1;

	PortClass* port;
	port = new PortClass(raw, que);
	ThreadClass(name, port->func, cpuId);

	//-----------------------------------
	name = "PcapThread";
	cpuId = 3;

	PcapClass *pcap;
	pcap = new PcapClass(raw, que);
	ThreadClass(name, pcap->func, cpuId);

	//-----------------------------------
	name = "MsgThread";
	MsgClass* msg = new MsgClass(raw, que);
	ThreadClass(name, msg->func);

	RecvClass* rcv = new RecvClass();
	rcv->RecvFunc(msg);

	return 0;
}

