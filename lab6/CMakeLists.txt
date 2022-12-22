cmake_minimum_required(VERSION 3.2) 

project(lab6)

set(myfiles src/main.cpp include/include.hpp)

include_directories(include src)

add_executable(${PROJECT_NAME} ${myfiles})
