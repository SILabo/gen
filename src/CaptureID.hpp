/**
 * File Name   : message_parser_json.hpp
 * Auther      : Shinji Ikuta
 * Copyright   : © 2020 Artiza Networks, Inc.
 * Description :
 * Email       : ikuta_shinji@artiza.co.jp
 */
#pragma once


#include "main.hpp"

class CaptureID {

public:
	uint32_t port_id;
	uint64_t capture_id;

	CaptureID();
	~CaptureID();

	void SetCid(uint64_t cid);
	void SetPid(uint32_t pid);
	uint64_t GetCid();
	uint32_t GetPid();
};
