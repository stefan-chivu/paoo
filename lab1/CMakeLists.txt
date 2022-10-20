cmake_minimum_required(VERSION 3.2) 

project(myapp)

set(myfiles build/src/test.cpp build/inc/test.hpp)

include_directories(build/inc build/src build/cfg)

add_executable(${PROJECT_NAME} ${myfiles})
