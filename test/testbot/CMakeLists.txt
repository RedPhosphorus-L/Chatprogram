cmake_minimum_required(VERSION 3.0)
project(test)
add_executable(botclient botclient.cpp)
target_link_libraries(botclient pthread)