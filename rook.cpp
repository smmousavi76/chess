#include "Rook.h"
#include "Position.h"
Rook::Rook(int owner,int count) : Piece(owner)
{
    typeId = 3;

    if(owner == 0)//white
    {
        pos.xPos=0;
    if(count==1)
        pos.yPos=0;
    if(count==2){
        pos.yPos=7;
    }
    }
    else if(owner == 1)//black
    {
        pos.xPos=7;

      if(count==1)
        pos.yPos=0;
    if(count==2){
        pos.yPos=7;
    }
    }
}

void Rook::move(Posiotion pos)
{
    int First_x=pos.xPos;
    int First_y=pos.yPos;
 for(int i=pos.yPos;i<=8;i++)
 {

     Posiotion a;
     a.xPos=First_x;
     PossibleMoves.push_back(a);
 }
    pos.xPos=First_x;
    pos.yPos=First_y;
 for(int i=pos.yPos;i>0;i--)
 {
     Posiotion b;
     b.xPos=First_x;
     PossibleMoves.push_back(b);
 }
    pos.xPos=First_x;
    pos.yPos=First_y;

 for(int i=pos.xPos;i<=8;i++)
 {
     Posiotion c;
     c.yPos=First_y;
     PossibleMoves.push_back(c);
 }
    pos.xPos=First_x;
    pos.yPos=First_y;
 for(int i=pos.xPos;i>0;i--)
 {
     Posiotion d;
     d.yPos=First_y;
     PossibleMoves.push_back(d);
 }
}
Rook::~Rook()
{

}
