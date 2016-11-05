project(BasicRevisited)
cmake_minimum_required(VERSION 2.8.11)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14")

find_package(Boost COMPONENTS program_options REQUIRED)
include_directories(${Boost_INCLUDE_DIRS})

set(HDRS
    Grammars.hpp
)

#set(SRCS
#    main.cpp
#)

add_executable(unit_tests ${HDRS} ${SRCS} UnitTests.cpp)
add_executable(interpreter ${HDRS} ${SRCS} Interpreter.cpp)
target_link_libraries(interpreter ${Boost_PROGRAM_OPTIONS_LIBRARY})

add_executable(converter ${HDRS} ${SRCS} Converter.cpp)
target_link_libraries(converter ${Boost_PROGRAM_OPTIONS_LIBRARY})

add_subdirectory(Interpreter)
