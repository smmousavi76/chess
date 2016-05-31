#include "Bishop.h"
Bishop::Bishop(int owner):Piece(int owner)
{
 typeId = 4;
 int counter=0

    if(owner == 0)//white
    {
        Black_White=0;
if(counter==0)
    {
    pos.xPos = 1;
    pos.yPos = 1;
}
else
{
 pos.xPos=8;
 pos.yPos=1;
}
    }

        }

    else if(owner == 1)//black
    {
        Black_White=1;
        if(counter==0)
        {
        pos.xPos = 1;
        pos.yPos = 8;
        }
        else
        {
            pos.xPos=8;
            pos.yPos=8;
        }
    }
    counter++;
}
}
void Bishop::move(Posiotion)
{

}
Bishop::~Bishop()
{

}
