//
// Created by Andmin on 22.10.2022.
//

#ifndef COURSEWORK_DRAWER_H
#define COURSEWORK_DRAWER_H


#include <objidl.h>
#include <gdiplus.h>
#include <gdiplus/gdiplusheaders.h>
#include <windef.h>

#include "Server/ServerState.h"

class Drawer {

public:

    Drawer();
    ~Drawer();

    typedef enum state
    {
        None = -1,
        Game = 0,
        Menu = 1,
        MultiplayerMenu = 2,
        GameResult = 3
    } State;

    State GetState()
    {
        return state;
    }

    State ChangeState(); //due to chosen entry

    State ReturnToPrevState();

    void ChangeEntry(int dChosenEntry); // -1 or 1

    void Draw(HDC hdc, ServerState* state); //draw due to State

    bool IsGameRunning()
    {
        return isGameRunning;
    }

    void SetWindowSize(RECT rc)
    {
        xSize = rc.right - rc.left;
        ySize = rc.bottom - rc.top;
    }


private:
    State state = Menu, lastState = None;
    int ChosenEntry = 0;
    bool isGameRunning = false;
    long xSize = 0, ySize = 0;
    ULONG_PTR gdiplusToken;
};


#endif //COURSEWORK_DRAWER_H
