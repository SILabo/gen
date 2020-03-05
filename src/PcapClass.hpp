#include "TimeRange.hpp"
#include "SplitOption.hpp"


class PcapClass {

public:
	std::string pass;
	std::string base_filename;
	TimeRange range;
	std::string limit;
	SplitOption split_options;

	PcapClass();
	~PcapClass();
};

