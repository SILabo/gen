#include <string>
#include "L2Vlan.hpp" 

class Layer2 {

public:
	std::string tag;
	L2Vlan vlan_tags;
	
	Layer2();
	~Layer2();
};

