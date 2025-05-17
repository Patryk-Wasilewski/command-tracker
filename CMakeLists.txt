cmake_minimum_required(VERSION 3.30)
project(Command_Tracker C)

set(CMAKE_C_STANDARD 23)

find_package(PkgConfig REQUIRED)
pkg_check_modules(GTK3 REQUIRED gtk+-3.0)

include_directories(${GTK3_INCLUDE_DIRS})
link_directories(${GTK3_LIBRARY_DIRS})
add_definitions(${GTK3_CFLAGS_OTHER})


add_executable(
        Command_Tracker

        main.c
)

target_link_libraries(Command_Tracker ${GTK3_LIBRARIES})
