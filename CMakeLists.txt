cmake_minimum_required(VERSION 3.0)
project(TCPServer)

# find_package(MySQL REQUIRED)
# target_include_directories(my_target PRIVATE ${MYSQL_INCLUDE_DIR})
# target_link_libraries(my_target PRIVATE ${MYSQL_LIBRARY})

add_subdirectory(Server)
add_subdirectory(Client)

