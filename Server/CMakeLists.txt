cmake_minimum_required(VERSION 3.0)
project(Server)

set(CMAKE_CXX_STANDARD 20)

add_executable(${PROJECT_NAME} src/Server.cpp)

include_directories(/usr/include/postgresql)
target_link_libraries(Server -lpq)
