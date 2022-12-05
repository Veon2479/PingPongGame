//
// Created by Andmin on 23.10.2022.
//

#include <iostream>
#include "../include/Game.h"

Game::Game()
{
    drawer = new Drawer();
}

Game::~Game()
{

}

bool Game::Start()
{

    return IsRunning;
}

bool Game::Stop()
{
    return !IsRunning;
}

void Game::DecodeKey(wchar_t code)
{
    if (drawer != nullptr)
        if (drawer->IsGameRunning())
        {
            switch (code)
            {
                case L'W':
                case L'w':
                case L'ц':
                case L'Ц':
                case VK_UP:
                case L'S':
                case L's':
                case L'Ы':
                case L'ы':
                case VK_DOWN:
                    if (server != nullptr)
                        server->DecodeKey(code);
                    break;

                //TODO: any other view controls?

                default:
                    break;
            }
        }
        else
        {
            switch (code)
            {
                case VK_ESCAPE:    //escape
                    drawer->ReturnToPrevState();
                    break;

                case VK_RETURN:      //Enter
                    Drawer::State state = drawer->ChangeState();
                    if (state == Drawer::Game)
                    {
                        //TODO: start game (server)
                    }
                    break;

                case L'W':
                case L'w':
                case L'ц':
                case L'Ц':
                case VK_UP:
                    drawer->ChangeEntry(-1);
                    break;

                case L'S':
                case L's':
                case L'Ы':
                case L'ы':
                case VK_DOWN:
                    drawer->ChangeEntry(1);
                    std::wcout << "LOG: pressed: " << (int)code << " - " << code << std::endl;
                    break;

                default:
                    break;
            }
        }
    else
    {
        std::cout << "LOG: cannot decode key due to null drawer" << std::endl;
    }
}

void Game::Update()
{

}

void Game::Paint(HDC hdc)
{
    drawer->Draw(hdc, nullptr);
}

void Game::SetWindowSize(RECT rc)
{
    drawer->SetWindowSize(rc);
}
