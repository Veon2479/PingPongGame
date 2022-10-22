//
// Created by Andmin on 23.10.2022.
//

#include "../include/Game.h"

Game::Game()
{
    IsRunning = false;
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

}

void Game::Update()
{

}

void Game::Paint(HDC hdc)
{

}

void Game::SetWindowSize(RECT rc)
{

}
