#include "Pawn.h"
#include "Position.h"
Pawn::Pawn(int owner,int count):Piece(owner)
{
 typeId=6;
   if(owner == 0)//white
    {
          pos.yPos=1;
          pos.xPos =count;


        pos.yPos = 1;
    }
    else if(owner == 1)//black
    {
        pos.xPos =count;
        pos.yPos = 6;
    }
}
void Pawn::move(Posiotion pos)
{
    int First_x=pos.xPos;
    int First_y=pos.yPos;
 if(start())
 {
     for(int i=pos.yPos;i<pos.yPos+2;i++)
     {
         Posiotion a;
         a.xPos=i;
         a.yPos=First_y;
         PossibleMoves.push_back(a);
            ///no possible move for attack
     }

 }
 else
 {

     for(int i=pos.yPos;i<pos.yPos+1;i++)
     {
         Posiotion a;
         a.xPos=First_x;
         a.yPos=pos.yPos;
         PossibleMoves.push_back(a);
     }

 }

}
Pawn::~Pawn()
{

}
