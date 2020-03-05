#pragma once

#include "main.hpp"
#include "MsgClass.hpp"

class RawData : public MsgClass {

public:
	RawData(uint64_t cap_num);
	~RawData();

};
