cmake_minimum_required(VERSION 3.23)
project(Coursework)

set(CMAKE_CXX_STANDARD 23)

LINK_LIBRARIES(${MyProject} -lgdiplus )

set(Files
        src/main.cpp
        include/IPlayer.h include/LocalPlayer.h include/RemotePlayer.h
        include/Server.h
        include/Entity.h include/Ball.h
        include/Drawer.h
        include/Game.h src/Game.cpp)

add_executable(Coursework ${Files})
