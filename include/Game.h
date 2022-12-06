//
// Created by Andmin on 22.10.2022.
//

#ifndef COURSEWORK_GAME_H
#define COURSEWORK_GAME_H

#include <tchar.h>
#include <windef.h>
#include <iostream>

#include "Server/Server.h"
#include "../include/Drawer.h"
#include "../include/Player/LocalPlayer.h"
#include "../include/Player/RemotePlayer.h"

class Game {

public:
    Game();     //TODO: make beautiful start screen
    ~Game();

    bool Start();
    bool Stop();
    bool GetRunningState()
    {
        return IsRunning;
    }

    void DecodeKey(wchar_t code);

    void Update();
    void Paint(HDC hdc);
    void SetWindowSize(RECT rc);

private:
    Server *server = nullptr;
    Drawer *drawer = nullptr;

    bool IsRunning = false;

};


#endif //COURSEWORK_GAME_H
