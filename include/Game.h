//
// Created by Andmin on 22.10.2022.
//

#ifndef COURSEWORK_GAME_H
#define COURSEWORK_GAME_H

#include <tchar.h>
#include <windef.h>
#include "../include/Server.h"
#include "../include/Drawer.h"

class Game {

public:
    Game();     //TODO: make beautiful start screen
    ~Game();

    bool Start();
    bool Stop();
    bool IsRunning;

    void DecodeKey(wchar_t code);

    void Update();
    void Paint(HDC hdc);
    void SetWindowSize(RECT rc);

private:
    Server *srv = nullptr;
    Drawer *drawer = nullptr;

};


#endif //COURSEWORK_GAME_H
