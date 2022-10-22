//
// Created by Andmin on 22.10.2022.
//

#ifndef COURSEWORK_SERVER_H
#define COURSEWORK_SERVER_H


#include "IPlayer.h"

class Server {
public:
    Server(IPlayer playerOne, IPlayer playerTwo);
    ~Server();
    bool Start();
    bool Stop();
    bool DecodeKey();

    bool IsRunning = false;

private:
    IPlayer PlayerOne, PlayerTwo;
    float time;

    //TODO: using timer - maybe window winapi timer

};


#endif //COURSEWORK_SERVER_H
