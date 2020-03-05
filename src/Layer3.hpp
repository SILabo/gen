#include "L3Ipv4.hpp" 
#include "L3Ipv6.hpp" 

class Layer3 {

public:
	std::string tag;
	L3Ipv4 ipv4;
	L3Ipv6 ipv6;

	Layer3();
	~Layer3();
};

