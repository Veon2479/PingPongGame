//
// Created by Andmin on 22.10.2022.
//

#ifndef COURSEWORK_GAME_H
#define COURSEWORK_GAME_H

#include <tchar.h>
#include <windef.h>
#include "Server/Server.h"
#include "../include/Drawer.h"

class Game {

public:
    Game();     //TODO: make beautiful start screen
    ~Game();

    bool Start();
    bool Stop();
    bool GetRunningState();

    void DecodeKey(wchar_t code);

    void Update();
    void Paint(HDC hdc);
    void SetWindowSize(RECT rc);

private:
    Server *server = nullptr;
    Drawer *drawer = new Drawer();

    bool IsRunning = false;

};


#endif //COURSEWORK_GAME_H
