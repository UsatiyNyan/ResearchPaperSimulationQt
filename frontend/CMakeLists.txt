find_package(Qt5 COMPONENTS Widgets REQUIRED)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

add_library(simulation_widget STATIC
        simulation_widget/simulation_widget.cpp
        simulation_widget/simulation_widget.ui)
target_include_directories(simulation_widget PUBLIC
        simulation_widget)
target_link_libraries(simulation_widget PUBLIC
        Qt5::Widgets
        simulation_engine
        )

add_library(main_window STATIC
        main_window/main_window.cpp
        main_window/main_window.ui)
target_include_directories(main_window PUBLIC
        main_window)
target_link_libraries(main_window PUBLIC simulation_widget)

#include(../cmake-build-debug/cmake_install.cmake)
