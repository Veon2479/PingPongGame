//
// Created by Andmin on 22.10.2022.
//

#ifndef COURSEWORK_PLAYER_H
#define COURSEWORK_PLAYER_H

#include "../Entity/Entity.h"
#include "../Server/ServerData.h"

#define PlayerWidth 10
#define PlayerHeight 70

class Player : Entity {

public:

    int const PlayerID = 0;
    explicit Player(int playerID);

    void MoveTo(int dx, int dy) override;
    void Update(int v) override;

    void SetData(ServerData* data);

};


#endif //COURSEWORK_PLAYER_H
