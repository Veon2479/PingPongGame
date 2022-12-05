//
// Created by Andmin on 22.10.2022.
//

#ifndef COURSEWORK_PLAYER_H
#define COURSEWORK_PLAYER_H

#include "../Entity/Entity.h"
#include "../Server/ServerData.h"

class Player : Entity {

public:

    int const PlayerID = 0;
    Player(int playerID);

    void SetData(ServerData* data);

};


#endif //COURSEWORK_PLAYER_H
