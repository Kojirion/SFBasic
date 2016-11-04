project(BasicRevisited)
cmake_minimum_required(VERSION 2.8)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14")

find_package(Boost REQUIRED)
include_directories(${Boost_INCLUDE_DIRS})

add_executable(unit_tests UnitTests.cpp)
add_executable(interpreter Interpreter.cpp)

#set(HDRS

#)

#set(SRCS
#    main.cpp
#)

#add_executable(${PROJECT_NAME} ${HDRS} ${SRCS})
