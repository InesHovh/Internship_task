cmake_minimum_required(VERSION 3.0)
project(TCPServer)

include_directories(${Boost_INCLUDE_DIRS})
include_directories(/usr/include/postgresql)
add_subdirectory(DB)
add_subdirectory(Server)
add_subdirectory(Client)

# find_package(Boost REQUIRED COMPONENTS system)
# if(NOT Boost_FOUND)
#     message(FATAL_ERROR "Boost not found. Please install it or check your Boost_ROOT variable.")
# endif()

