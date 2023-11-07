cmake_minimum_required(VERSION 3.0)
project(Client)

set(CMAKE_CXX_STANDARD 20)

add_executable(${PROJECT_NAME} src/Client.cpp)

include_directories(/usr/include/postgresql)
target_link_libraries(Client -lpq)

include_directories(${Boost_INCLUDE_DIRS})
target_link_libraries(Client PRIVATE ${Boost_LIBRARIES})


