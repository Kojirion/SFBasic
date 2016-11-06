project(BasicRevisited)
cmake_minimum_required(VERSION 2.8.11)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14 -Wall")

find_package(Boost COMPONENTS program_options REQUIRED)
include_directories(${Boost_INCLUDE_DIRS})

set(GRAMMARS
        Grammars/Grammars.hpp
        Grammars/Input.hpp
        Grammars/Print.hpp
        Grammars/Expression.hpp
        Grammars/Input.cpp
        Grammars/Print.cpp
        Grammars/Expression.cpp
)

#set(SRCS
#    main.cpp
#)

set(BUILD_TESTS false CACHE BOOL "Build tests")

if (BUILD_TESTS)
    set (TEST_SRCS
            UnitTests/Input.cpp
            UnitTests/Print.cpp
            UnitTests/Add.cpp
            UnitTests/main.cpp
        )

    add_executable(unit_tests ${GRAMMARS} ${TEST_SRCS})
endif()

set (INTERPRETER_SRCS
        Interpreter/Interpreter.hpp
        Interpreter/Interpreter.cpp
        Interpreter/main.cpp
    )

add_executable(sfbasic-interpreter ${GRAMMARS} ${INTERPRETER_SRCS})
target_link_libraries(sfbasic-interpreter ${Boost_PROGRAM_OPTIONS_LIBRARY})

add_executable(sfbasic-converter ${GRAMMARS} ${SRCS} Converter.cpp)
target_link_libraries(sfbasic-converter ${Boost_PROGRAM_OPTIONS_LIBRARY})

add_executable(sfbasic-formatter ${GRAMMARS} ${SRCS} Formatter/main.cpp)
target_link_libraries(sfbasic-formatter ${Boost_PROGRAM_OPTIONS_LIBRARY})

add_subdirectory(Interpreter/gui)

install(TARGETS sfbasic-converter DESTINATION .)
install(FILES sample.bas sample2.bas sample3.bas DESTINATION .)
install(FILES sfbasic-compile DESTINATION . PERMISSIONS OWNER_READ OWNER_EXECUTE)
