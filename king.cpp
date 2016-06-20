#include "King.h"
King::King(int owner):Piece( owner)
{
 typeId=1;
  if(owner == 0)//white
    {

        //Black_White=0;
        pos.xPos = 5;
        pos.yPos = 1;
    }
    else if(owner == 1)//black
    {
        //Black_White=1;
        pos.xPos =5;
        pos.yPos = 8;
    }
}
void King::move(Posiotion pos)
{
   int First_x=pos.xPos;
   int First_x=pos.xPos;

}
King::~King()
{

}
