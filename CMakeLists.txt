cmake_minimum_required(VERSION 3.23)
project(Coursework)

set(CMAKE_CXX_STANDARD 23)

LINK_LIBRARIES(${MyProject} -lgdiplus )

set(Files
        src/main.cpp
        )

add_executable(Coursework ${Files})
