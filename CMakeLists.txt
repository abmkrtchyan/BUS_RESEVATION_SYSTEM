cmake_minimum_required(VERSION 3.17)
project(Bus_Resevation_System)

set(CMAKE_CXX_STANDARD 14)

add_executable(Bus_Resevation_System main.cpp Source/People.cpp Header/People.h Source/Bus.cpp Header/Bus.h Source/Driver.cpp Header/Driver.h Source/Trip.cpp Header/Trip.h "Data Base Access/IDataBaseAccess.h")