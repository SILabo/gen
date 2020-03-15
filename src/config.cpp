/**
 * File Name   : config.cpp
 * Auther      : Shinji Ikuta
 * Copyright   : © 2020 Artiza Networks, Inc.
 * Description :
 * Email       : ikuta_shinji@artiza.co.jp
 */

#include "config.hpp"

namespace egen
{
Config::Config(std::string fileName)
{
    this->fileName = fileName;
}

Conf Config::parseConfFile()
{
    std::ifstream ifs(this->fileName);
    nlohmann::json j;
    ifs >> j;

    return j;
}

uint16_t Config::getNumOfCpuIds(std::string threadType)
{
    auto conf = this->parseConfFile();
    return conf.at("cpu_affinity").at(threadType).size();
}

uint16_t Config::getCpuIds(std::string threadType, uint16_t idx)
{
    auto conf = this->parseConfFile();
    return conf.at("cpu_affinity").at(threadType)[idx].get<uint16_t>();
}

std::string Config::getDbConnectionName()
{
    auto conf = this->parseConfFile();
    return conf.at("db").at("connection").get<std::string>();
}

std::string Config::getDbConnectionHostName()
{
    auto conf = this->parseConfFile();
    return conf.at("db").at("host").get<std::string>();
}

std::string Config::getDbConnectionUserName()
{
    auto conf = this->parseConfFile();
    return conf.at("db").at("user").get<std::string>();
}

std::string Config::getDbConnectionPasswd()
{
    auto conf = this->parseConfFile();
    return conf.at("db").at("password").get<std::string>();
}

std::string Config::getDbConnectionPort()
{
    auto conf = this->parseConfFile();
    return conf.at("db").at("port").get<std::string>();
}

}  // namespace egen
