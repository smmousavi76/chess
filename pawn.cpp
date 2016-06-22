#include "Pawn.h"
#include "Position.h"
Pawn::Pawn(int owner,int count):Piece(owner)
{
   if(owner == 0)//white
    {
         typeId=5;

          pos.yPos=1;
          pos.xPos =count;


        pos.yPos = 1;
    }
    else if(owner == 1)//black
    {
        typeId=11;
        pos.xPos =count;
        pos.yPos = 6;
    }
}
std::vector <Posiotion> Pawn::PossibleMove()
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
         possibleMoves.push_back(a);
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
         possibleMoves.push_back(a);
     }

 }
 return possibleMoves;

}
Pawn::~Pawn()
{

}
