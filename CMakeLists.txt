cmake_minimum_required(VERSION 3.0)
project(TCPServer)

include_directories(/usr/include/postgresql)
add_subdirectory(Server)
add_subdirectory(Client)

