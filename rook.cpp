#include "Rook.h"
#include "Position.h"
Rook::Rook(int owner,int count) : Piece(owner)
{
    typeId = 3;


    if(owner == 0)//white
    {
    if(count==1)
        pos.xPos=1;
    else{
        pos.xPos=8;
    }
        pos.xPos = 1;
    }
    else if(owner == 1)//black
    {
      if(count==1)
        pos.xPos=1;
    else{
        pos.xPos=8;
    }
            pos.xPos = 8;
    }
}

void Rook::move(Posiotion pos)
{

}
Rook::~Rook()
{

}
