//
// Created by Andmin on 22.10.2022.
//

#ifndef COURSEWORK_ISERVER_H
#define COURSEWORK_ISERVER_H

#include <vector>

#include "../Player/IPlayer.h"

class IServer {
public:
    IServer(IPlayer playerOne, IPlayer playerTwo);
    ~IServer();

    bool Start();
    bool Stop();
    bool GetRunningState();

    bool DecodeKey();

    virtual void Update();

    const std::vector<const Entity> GetEntityList();

private:
    IPlayer *PlayerOne = nullptr, *PlayerTwo = nullptr;
    float time = 0;

    bool IsRunning = false;

    std::vector<Entity> *EntityList = nullptr;


    //TODO: using timer - maybe window winapi timer

};


#endif //COURSEWORK_ISERVER_H
