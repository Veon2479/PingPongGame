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

#define FontPath "data/uglyFont.otf"


class Drawer {

public:

    Drawer();
    ~Drawer();

    typedef enum state
    {
        None = 0,
        Menu = 1,
        MultiplayerMenu = 2,
        GameResult = 3,
        LocalGame = 4,
        RemoteHostGame = 5,
        RemoteGuestGame = 6
    } State;

    State GetState()
    {
        return state;
    }

    State ChangeState() //due to chosen entry
    {
        //TODO: state = new state from chosen entry
    }

    State ReturnToPrevState()
    {
        //TODO: get previous state and set it
    }

    void ChangeEntry(int dChosenEntry) // -1 or 1
    {
        if ( (ChosenEntry > 1 && dChosenEntry == -1) || (ChosenEntry < GetEntriesCount() && dChosenEntry == 1) )
            ChosenEntry += dChosenEntry;
    }

    int GetEntriesCount()
    {
        //TODO: write this method
        //TODO: write table of state(entries) transitions - 0 element is previous state
    }

    void Draw(HDC hdc, ServerState* state_); //draw due to State

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
    State state = Menu;
    int ChosenEntry = 1;
    bool isGameRunning = false;
    long xSize = 0, ySize = 0;
    ULONG_PTR gdiplusToken{};

    void DrawGameState(Gdiplus::Graphics* graphics, ServerState* state);
    void DrawNonGameState(Gdiplus::Graphics* graphics);

    Gdiplus::FontFamily*  fontFamily = nullptr;
    Gdiplus::SolidBrush*  solidBrush = nullptr;
    
    Gdiplus::Font* MainMenuFont = nullptr;

};


#endif //COURSEWORK_DRAWER_H
