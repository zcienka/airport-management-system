cmake_minimum_required(VERSION 3.20)
project(AirlineTicketManagementSystem)

set(CMAKE_CXX_STANDARD 17)

add_executable(AirlineTicketManagementSystem
        main.cpp
        Tickets/BusinessClass.cpp
        Tickets/RegularClass.cpp
        Person.cpp
        constants.h
        Date.cpp)
