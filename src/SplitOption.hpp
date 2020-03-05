#include "main.hpp"

class SplitOption {

public:
	std::string mode;
	std::string filesize;
	std::string seconds_per_file;
	std::string packets_per_file;

	SplitOption();
	~SplitOption();
};
