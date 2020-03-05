/**
 * File Name   : message_parser_json.hpp
 * Auther      : Shinji Ikuta
 * Copyright   : © 2020 Artiza Networks, Inc.
 * Description :
 * Email       : ikuta_shinji@artiza.co.jp
 */

#pragma once

#include <iostream>
#include <thread>
#include <exception>
#include <atomic>
#include <csignal>
#include <cstdint>
#include <queue>
#include <array>
#include <cstring>
#include <mutex>
#include <cassert>
#include <fstream>
#include <sys/stat.h>
#include <zmq.hpp>
