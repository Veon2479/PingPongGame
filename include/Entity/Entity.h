//
// Created by Andmin on 22.10.2022.
//

#ifndef COURSEWORK_ENTITY_H
#define COURSEWORK_ENTITY_H


class Entity {

public:

    virtual void MoveTo(int dx, int dy);
    virtual void Update(int v);

    long GetX();
    long GetY();
    long GetXSize();
    long GetYSize();

private:
    long X = 0, Y = 0;
    long xSize = 0, ySize = 0;

};


#endif //COURSEWORK_ENTITY_H
