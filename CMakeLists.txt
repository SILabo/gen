# CMakeList.txt : gen_queue の CMake プロジェクト。ソースを含めて、次を定義します:
# プロジェクト専用ロジックはこちらです。
#
cmake_minimum_required (VERSION 3.8)

project ("gen_queue")

add_executable (gen_queue "main.cpp" "packet_class.cpp" "packet_class.hpp" "raw_data.cpp" "raw_data.hpp" "recv_class.cpp" "recv_class.hpp" "gen_queue.cpp" "gen_queue.hpp" "config.cpp" "config.hpp" "thread.cpp" "thread.hpp" "port_class.cpp" "port_class.hpp" "pcap_class.cpp" "pcap_class.hpp" "msg_class.cpp" "msg_class.hpp" "json.hpp")

include_directories(/usr/local/include)
link_directories(/usr/local/lib)
target_link_libraries(gen_queue pthread)
