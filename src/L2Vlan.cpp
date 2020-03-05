#include "L2Vlan.hpp"

L2Vlan::L2Vlan()
{
	this->tpid = 0;
	this->vid = new L2Vid();
}
L2Vlan::~L2Vlan()
{
}
