/**
 * File Name   : message_parser_json.hpp
 * Auther      : Shinji Ikuta
 * Copyright   : © 2020 Artiza Networks, Inc.
 * Description :
 * Email       : ikuta_shinji@artiza.co.jp
 */
#pragma once

#include "main.hpp"

class L2Vid {

public:
	uint32_t start;
	uint32_t end;

	L2Vid();
	~L2Vid();
};

