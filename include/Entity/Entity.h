//
// Created by Andmin on 22.10.2022.
//

#ifndef COURSEWORK_ENTITY_H
#define COURSEWORK_ENTITY_H


class Entity {

public:

    Entity(long x_, long y_, long xSize_, long ySize_)
    {
        X = x_;
        Y = y_;
        Width = xSize_;
        Height = ySize_;
    }

    virtual void MoveTo(int dx, int dy) = 0;
    virtual void Update(int v) = 0;

    long GetX()
    {
        return X;
    }

    void SetX(long x_)
    {
        X = x_;
    }

    long GetY()
    {
        return Y;
    }

    void SetY(long y_)
    {
        Y = y_;
    }


    long GetWidth()
    {
        return Width;
    }

    void SetWidth(long width_)
    {
        Width = width_;
    }

    long GetHeight()
    {
        return Height;
    }

    void SetHeight(long height_)
    {
        Height = height_;
    }

private:
    long X = 0, Y = 0;
    long Width = 0, Height = 0;

};


#endif //COURSEWORK_ENTITY_H
