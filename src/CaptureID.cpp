/**
 * File Name   : message_parser_json.hpp
 * Auther      : Shinji Ikuta
 * Copyright   : © 2020 Artiza Networks, Inc.
 * Description :
 * Email       : ikuta_shinji@artiza.co.jp
 */

#include "CaptureID.hpp"

CaptureID::CaptureID()
{
}
CaptureID::~CaptureID()
{
}
void CaptureID::SetCid(uint64_t cid)
{
	this->capture_id = cid;
}
void CaptureID::SetPid(uint32_t pid)
{
	this->port_id = pid;
}
uint64_t CaptureID::GetCid()
{
	return this->capture_id;
}
uint32_t CaptureID::GetPid()
{
	return this->port_id;
}
