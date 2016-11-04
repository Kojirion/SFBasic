project(BasicRevisited)
cmake_minimum_required(VERSION 2.8)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14")

find_package(Boost REQUIRED)
include_directories(${Boost_INCLUDE_DIRS})

set(HDRS
    Grammars.hpp
)

#set(SRCS
#    main.cpp
#)

add_executable(unit_tests ${HDRS} ${SRCS} UnitTests.cpp)
add_executable(interpreter ${HDRS} ${SRCS} Interpreter.cpp)
