#ifndef POSITION_H_INCLUDED
#define POSITION_H_INCLUDED

struct Posiotion
{
    int xPos;
    int yPos;
    bool operator==(Posiotion pos)
    {
        if(xPos == pos.xPos && yPos == pos.yPos)
        return true;
        return false;
    }
    Posiotion()
    {

    }
    Posiotion(int x, int y)
    {
        xPos=x;
        yPos=y;
    }
};

#endif // POSITION_H_INCLUDED
