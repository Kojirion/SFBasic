set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)

find_package(Qt5Widgets)

set(SRCS
    MainWindow.hpp
    MainWindow.cpp
    main.cpp
)

add_executable(interpreter-gui ${SRCS})

target_link_libraries(interpreter-gui Qt5::Widgets)
