/**
 * File Name   : message_parser_json.hpp
 * Auther      : Shinji Ikuta
 * Copyright   : © 2020 Artiza Networks, Inc.
 * Description :
 * Email       : ikuta_shinji@artiza.co.jp
 */
#pragma once

#include "Layer2.hpp" 
#include "Layer3.hpp" 
#include "Layer4.hpp" 

class Filter {

public:
	Layer2 l2;
	Layer3 l3;
	Layer4 l4;

	Filter();
	~Filter();
};

