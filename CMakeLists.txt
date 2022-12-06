cmake_minimum_required(VERSION 3.23)
project(Coursework)

set(CMAKE_CXX_STANDARD 23)

LINK_LIBRARIES(${MyProject} -lgdiplus )

set(Files
        main.cpp

        include/Game.h src/Game.cpp

        include/Server/Server.h src/Server/Server.cpp
        include/Server/ServerState.h include/Server/ServerData.h

        include/Drawer.h src/Drawer.cpp

        include/Player/Player.h include/Player/LocalPlayer.h include/Player/RemotePlayer.h
        src/Player/LocalPlayer.cpp src/Player/Player.cpp src/Player/RemotePlayer.cpp

        include/Entity/Entity.h include/Entity/Ball.h
        )

add_executable(Coursework ${Files})
