//
// Created by Andmin on 22.10.2022.
//

#ifndef COURSEWORK_REMOTEPLAYER_H
#define COURSEWORK_REMOTEPLAYER_H


#include "Player.h"

class RemotePlayer : public Player{

    //TODO: make UDP connection via UDP winapi socket
public:

    explicit RemotePlayer(int playerId);


};


#endif //COURSEWORK_REMOTEPLAYER_H
