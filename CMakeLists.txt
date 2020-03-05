cmake_minimum_required (VERSION 3.8)

project ("Generator")

set(CMAKE_CXX_STANDARD 17)

add_executable (Generator "./src/main.cpp" "./src/RawData.cpp" "./src/MsgClass.cpp" "./src/GenQueue.cpp" "./src/PcapClass.cpp" "./src/Filter.cpp" "./src/CaptureID.cpp" "./src/Layer2.cpp" "./src/Layer3.cpp" "./src/Layer4.cpp" "./src/L2Vid.cpp" "./src/L2Vlan.cpp" "./src/L3Ipv4.cpp" "./src/L3Ipv6.cpp" "./src/SplitOption.cpp" "./src/TimeRange.cpp"  "./src/PortClass.cpp" "./src/main.hpp" "./src/RawData.hpp" "./src/MsgClass.hpp" "./src/GenQueue.hpp" "./src/PcapClass.hpp" "./src/Filter.hpp" "./src/CaptureID.hpp" "./src/Layer2.hpp" "./src/Layer3.hpp" "./src/Layer4.hpp" "./src/L2Vid.hpp" "./src/L2Vlan.hpp" "./src/L3Ipv4.hpp" "./src/L3Ipv6.hpp" "./src/SplitOption.hpp" "./src/TimeRange.hpp" "./src/PortClass.hpp")
add_library (gen STATIC "./src/pktfil.cpp" "./src/pktfil.hpp" "./src/Filter.cpp" "./src/Filter.hpp" "./src/Layer2.cpp" "./src/Layer2.hpp" "./src/Layer3.cpp" "./src/Layer3.hpp" "./src/Layer4.cpp" "./src/Layer4.hpp" "./src/L2Vid.cpp" "./src/L2Vid.hpp" "./src/L2Vlan.cpp" "./src/L2Vlan.hpp" "./src/L3Ipv4.cpp" "./src/L3Ipv4.hpp" "./src/L3Ipv6.cpp" "./src/L3Ipv6.hpp")
include_directories(/home/ether/projects/Generator/src)		#インクルードディレクトリ指定 
include_directories(/usr/local/include)             		#インクルードディレクトリ指定 
link_directories(/home/ether/projects/Generator/lib)        #ライブラリディレクトリ指定 
link_directories(/usr/local/lib)                            #zmq
target_link_libraries(Generator pthread zmq gen)
