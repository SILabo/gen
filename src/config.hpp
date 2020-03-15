/**
 * File Name   : config.hpp
 * Auther      : Shinji Ikuta
 * Copyright   : © 2020 Artiza Networks, Inc.
 * Description :
 * Email       : ikuta_shinji@artiza.co.jp
 */

#pragma once

#include <iostream>
#include <cstdint>
#include <fstream>
#include <string>
#include <vector>
#include "json.hpp"
#include "pthread.h"

namespace egen
{
using Conf = nlohmann::json;

class Config
{
   public:
    explicit Config(std::string fileName = "generator_config.json");
    uint16_t    getNumOfCpuIds(std::string threadType);
    uint16_t    getCpuIds(std::string threadType, uint16_t idx);
    std::string getDbConnectionName();
    std::string getDbConnectionHostName();
    std::string getDbConnectionUserName();
    std::string getDbConnectionPasswd();
    std::string getDbConnectionPort();

   private:
    std::string fileName;
    Conf        parseConfFile();
};
}  // namespace egen
