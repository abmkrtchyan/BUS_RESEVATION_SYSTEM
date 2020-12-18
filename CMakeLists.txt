cmake_minimum_required(VERSION 3.17)
project(Bus_Resevation_System)

set(CMAKE_CXX_STANDARD 14)

include_directories("nlohmann_json/include")

add_executable(Bus_Resevation_System main.cpp BaseClasses/Source/People.cpp BaseClasses/Header/People.h
        BaseClasses/Source/Bus.cpp BaseClasses/Header/Bus.h BaseClasses/Source/Driver.cpp BaseClasses/Header/Driver.h
        BaseClasses/Source/Trip.cpp BaseClasses/Header/Trip.h "Data Base Access/IDataBaseAccess.h"
        "Data Base Access/JsonDB/JsonDBAccess.cpp" "Data Base Access/JsonDB/JsonDBAccess.h"
        UserAPI/Source/MainFunctions.cpp UserAPI/Header/MainFunctions.h nlohmann_json/include/nlohmann/json.hpp)
