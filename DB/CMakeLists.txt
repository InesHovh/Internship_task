cmake_minimum_required(VERSION 3.0)
project(DB)

set(CMAKE_CXX_STANDARD 20)

add_executable(DB src/DB.cpp)
# target_link_libraries(DB PRIVATE headers/DB.hpp)

add_executable(HTTP src/HTTP.cpp)
# target_link_libraries(HTTP PRIVATE headers/HTTP.hpp)

include_directories(/usr/include/postgresql)
target_link_libraries(DB -lpq)

include_directories(${Boost_INCLUDE_DIRS})
target_link_libraries(DB PRIVATE ${Boost_LIBRARIES})