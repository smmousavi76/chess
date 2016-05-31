#include "Pawn.h"
Pawn::Pawn(int owner)
{
 typeId=6;
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
void Pawn::move()
{


}
Pawn::~Pawn()
{

}
