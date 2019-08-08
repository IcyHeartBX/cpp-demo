cmake_minimum_required(VERSION 3.12)
project(c_socket_tcp_client C)

set(CMAKE_C_STANDARD 99)

add_executable(c_socket_tcp_client main.c c_tcp_client.c c_tcp_client.h)