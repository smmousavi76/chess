#include "Pawn.h"
#include "Position.h"
Pawn::Pawn(int owner,int count):Piece(owner)
{
 typeId=6;
   if(owner == 0)//white
    {
        pos.xPos = count;
        pos.yPos = 2;
    }
    else if(owner == 1)//black
    {
        pos.xPos =count;
        pos.yPos = 7;
    }
}
void Pawn::move(Posiotion pos)
{


}
Pawn::~Pawn()
{

}
