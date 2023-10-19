cmake_minimum_required(VERSION 3.26)
project(l3)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

set(CMAKE_PREFIX_PATH "D:/Code/C++/qt6/qt6-static/lib/cmake")

find_package(Qt6 COMPONENTS
        Core
        Gui
        Widgets
        REQUIRED)

include_directories(src)

add_executable(l3 main.cpp
        src/widget/widget.cpp
        src/widget/widget.hpp
        src/widget/widget.ui
        src/player/player.cpp
        src/player/player.hpp
        src/enemy/enemy.cpp
        src/enemy/enemy.hpp
        src/health_bar/health_bar.cpp
        src/health_bar/health_bar.hpp
        src/healing/healing.cpp
        src/healing/healing.hpp)

target_link_libraries(l3
        Qt::Core
        Qt::Gui
        Qt::Widgets
)
