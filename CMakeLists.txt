cmake_minimum_required(VERSION 3.23)
project(Coursework)

set(CMAKE_CXX_STANDARD 23)

LINK_LIBRARIES(${MyProject} -lgdiplus )

set(Files
        main.cpp
        include/Player/Player.h include/Player/LocalPlayer.h include/Player/RemotePlayer.h
        include/Server/Server.h
        include/Entity/Entity.h include/Entity/Ball.h
        include/Drawer.h
        include/Game.h src/Game.cpp include/Server/ServerState.h include/Server/ServerState.h include/Server/ServerData.h src/Drawer.cpp src/Server/Server.cpp)

add_executable(Coursework ${Files})
