//
// Created by Andmin on 22.10.2022.
//

#ifndef COURSEWORK_DRAWER_H
#define COURSEWORK_DRAWER_H


class Drawer {

public:

    typedef enum state
    {
        Menu = 0,
        Game = 1
    } State;

    State GetState();

    State ChangeState(); //due to chosen entry
    void ChangeEntry(int dChosenEntry); // -1 or 1

    void Draw(HDC hdc, IPlayer *playerOne, IPlayer *playerTwo, std::vector<Entity>); //draw due to State


private:
    State state = Menu, lastState = Menu;
    int ChosenEntry = 0;
};


#endif //COURSEWORK_DRAWER_H
