#include "Queen.h"
Queen::Queen(int owner):Piece(int owner)
{
 typeId = 2;


    if(owner == 0)//white
    {
        Black_White=0;
        pos.xPos = 1;
        pos.yPos = 4;
    }
    else if(owner == 1)//black
    {
        Black_White=1;
        pos.xPos =1;
        pos.yPos = 8;
    }
}
}
void Queen::move(Posiotion)
{

}

Queen::~Queen()
{

}
