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
	que->push(raw,0);
	que->push(raw,0);

	//-----------------------------------
	std::string name = "Port1Thread";
	size_t cpuId = 1;

	PortClass* port1;
	port1 = new PortClass(raw, que);
	ThreadClass(name, port1->func, cpuId);

	//-----------------------------------
	name = "Port2Thread";
	cpuId = 2;

	PortClass* port2;
	port2 = new PortClass(raw, que);
	ThreadClass(name, port2->func, cpuId);

	//-----------------------------------
	name = "Port3Thread";
	cpuId = 3;

	PortClass* port3;
	port3 = new PortClass(raw, que);
	ThreadClass(name, port3->func, cpuId);

	//-----------------------------------
	name = "Port4Thread";
	cpuId = 4;

	PortClass* port4;
	port4 = new PortClass(raw, que);
	ThreadClass(name, port4->func, cpuId);

	//-----------------------------------
	name = "PcapThread";
	cpuId = 5;

	PcapClass *pcap;
	pcap = new PcapClass(raw, que);
	ThreadClass(name, pcap->func, cpuId);

	//-----------------------------------
	name = "MsgThread";
	MsgClass* msg = new MsgClass(raw, que);
	ThreadClass(name, msg->func);

	sleep(10);

	std::cout << "PortThread #1:" << port1->get_cpuid() << std::endl;
	std::cout << "PortThread #2:" << port2->get_cpuid() << std::endl;
	std::cout << "PortThread #3:" << port3->get_cpuid() << std::endl;
	std::cout << "PortThread #4:" << port4->get_cpuid() << std::endl;

	std::cout << "PcapThread #1:" << pcap->get_cpuid() << std::endl;
	std::cout << "MsgThread  #1:" << msg->get_cpuid() << std::endl;

	RecvClass* rcv = new RecvClass();
	rcv->RecvFunc(msg);

	return 0;
}

