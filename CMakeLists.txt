cmake_minimum_required(VERSION 3.23)
project(Coursework)

set(CMAKE_CXX_STANDARD 23)

LINK_LIBRARIES(${MyProject} -lgdiplus )

set(Files
        src/main.cpp
        include/Player/IPlayer.h include/Player/LocalPlayer.h include/Player/RemotePlayer.h
        include/Server/IServer.h include/Server/ActiveServer.h include/Server/PassiveServer.h
        include/Entity/Entity.h include/Entity/Ball.h
        include/Drawer.h
        include/Game.h src/Game.cpp )

add_executable(Coursework ${Files})
