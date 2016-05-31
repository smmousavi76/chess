#include "Rook.h"

Rook::Rook(int owner) : Piece(owner)
{
    typeId = 3;


    if(owner == 0)//white
    {
        Black_White=0;
        pos.xPos = 5;
        pos.yPos = 8;
    }
    else if(owner == 1)//black
    {
        Black_White=1;
        pos.xPos = 5;
        pos.yPos = 1;
    }
}

void Rook::move(Posiotion)
{

}
Rook::~Rook()
{

}
