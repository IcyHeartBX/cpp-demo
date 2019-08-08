cmake_minimum_required(VERSION 3.12)
project(c_socket_tcp_server C)

set(CMAKE_C_STANDARD 99)

add_executable(c_socket_tcp_server main.c c_tcp_server.h c_tcp_server.c)