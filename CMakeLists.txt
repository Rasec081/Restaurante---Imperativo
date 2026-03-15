cmake_minimum_required(VERSION 3.28.3)
project(Imperativo)

set(CMAKE_CXX_STANDARD 20)

add_executable(Imperativo main.cpp
        server/order_manager.h)
