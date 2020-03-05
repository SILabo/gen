#include "L2Vid.hpp" 

class L2Vlan {

public:
	uint32_t tpid;
	L2Vid* vid;
	
	L2Vlan();
	~L2Vlan();
};

