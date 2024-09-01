cmake_minimum_required(VERSION 3.5)

project(MKV_Player LANGUAGES CXX)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

#find_package(PkgConfig REQUIRED)
#pkg_check_modules(FFMPEG REQUIRED IMPORTED_TARGET libavformat libavcodec libavutil libswscale)
find_package(Qt6 REQUIRED COMPONENTS Core Gui Widgets Multimedia MultimediaWidgets)

add_executable(MKV_Player
    main.cpp
    mainwindow.cpp
    mainwindow.h
    ui_mainwindow.h
    mainwindow.ui
)

target_link_libraries(MKV_Player Qt6::Core Qt6::Gui Qt6::Widgets Qt6::Multimedia Qt6::MultimediaWidgets)
