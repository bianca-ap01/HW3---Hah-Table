cmake_minimum_required(VERSION 3.10)
project(HW3_Hash_Table)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

include_directories(.)
include_directories(Chaining)

add_executable(HW3_Hash_Table
        Chaining/HashTable.h
        Chaining/LinkedList.h
        Chaining/main.cpp)
set_target_properties(HW3_Hash_Table PROPERTIES LINKER_LANGUAGE CXX)
