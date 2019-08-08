cmake_minimum_required(VERSION 3.12)
project(cmake_link_lib)

set(CMAKE_CXX_STANDARD 11)

add_executable(cmake_link_lib main.cpp)

include_directories(/usr/local/hiredis/)
include_directories(/usr/local/protobuf/include)
link_directories(/usr/local/hiredis/)
link_directories(/usr/local/protobuf/lib/)

target_link_libraries(cmake_link_lib /usr/local/hiredis/libhiredis.a)
target_link_libraries(cmake_link_lib /usr/local/protobuf/lib/libprotobuf.dylib)