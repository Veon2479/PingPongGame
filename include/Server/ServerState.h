//
// Created by Andmin on 12/5/2022.
//

#ifndef COURSEWORK_SERVERSTATE_H
#define COURSEWORK_SERVERSTATE_H


#include <vector>
#include "../Player/Player.h"
#include "ServerData.h"

class ServerState {

public:

    Player *PlayerOne = nullptr, *PlayerTwo = nullptr;
    std::vector<Entity>* EntityList = nullptr;

    ServerData GetServerData(int playerID);




private:

};


#endif //COURSEWORK_SERVERSTATE_H
