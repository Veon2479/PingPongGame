//
// Created by Andmin on 22.10.2022.
//

#ifndef COURSEWORK_SERVER_H
#define COURSEWORK_SERVER_H

#include <vector>

#include "../Player/Player.h"

class Server {
public:
    Server(Player playerOne, Player playerTwo, bool IsActive);
    ~Server();

    bool Start();
    bool Stop();
    bool GetRunningState();

    void DecodeKey(wchar_t code);

    virtual void Update();

    const std::vector<const Entity> GetEntityList();

private:
    float time = 0;

    bool IsRunning = false;

    std::vector<Entity> *EntityList = nullptr;


    //TODO: using timer - maybe window winapi timer

};


#endif //COURSEWORK_SERVER_H
