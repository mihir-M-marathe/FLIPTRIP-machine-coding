cmake_minimum_required(VERSION 3.29)
project(AirlineManagementSystem_updated)

set(CMAKE_CXX_STANDARD 14)

include_directories(include)

add_executable(AirlineManagementSystem_updated
    include/Airline.hpp
    include/Exception.hpp
    include/Flight.hpp
    include/FlightManager.hpp
    src/Airline.cpp
    src/Exception.cpp
    src/Flight.cpp
    src/FlightManager.cpp
    src/main.cpp)
