cmake_minimum_required(VERSION 3.0)
project(Client)

set(CMAKE_CXX_STANDARD 20)

add_executable(${PROJECT_NAME} src/Client.cpp)

# find_package(MySQL REQUIRED)
# target_include_directories(my_target PRIVATE ${MYSQL_INCLUDE_DIR})
# target_link_libraries(my_target PRIVATE ${MYSQL_LIBRARY})

