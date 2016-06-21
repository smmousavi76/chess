#include "King.h"
King::King(int owner):Piece( owner)
{
 typeId=1;
  if(owner == 0)//white
    {

        //Black_White=0;
        pos.xPos = 5;
        pos.yPos = 0;
    }
    else if(owner == 1)//black
    {
        //Black_White=1;
        pos.xPos =5;
        pos.yPos = 7;
    }
}
void King::move(Posiotion pos)
{
   int First_x=pos.xPos;
   int First_y=pos.yPos;
    Posiotion a;
    a.xPos=pos.xPos;
    a.yPos=pos.yPos+1;
    PossibleMoves.push_back(a);
    a.yPos=pos.yPos+1;
    PossibleMoves.push_back(a);
    a.xPos=pos.xPos+1;
    a.yPos=pos.yPos;
    PossibleMoves.push_back(a);
    a.xPos=pos.xPos-1;
    a.yPos=pos.yPos;
    PossibleMoves.push_back(a);
    a.xPos=pos.xPos+1;
    a.yPos=pos.yPos+1;
    PossibleMoves.push_back(a);
    a.xPos=pos.xPos-1;
    a.yPos=pos.yPos+1;
    PossibleMoves.push_back(a);
    a.xPos=pos.xPos+1;
    a.yPos=pos.yPos-1;
    PossibleMoves.push_back(a);
    a.xPos=pos.xPos-1;
    a.yPos=pos.yPos-1;
    PossibleMoves.push_back(a);

}
King::~King()
{

}
