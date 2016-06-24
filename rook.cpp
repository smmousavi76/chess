#include "Rook.h"
#include "Position.h"
Rook::Rook(int owner,int count) : Piece(owner)
{

    if(owner == 0)//white
    {
            typeId = 4;

        pos.yPos=0;
    if(count==1)
        pos.xPos=0;
    if(count==2){
        pos.xPos=7;
    }
    }
    else if(owner == 1)//black
    {
        typeId=10;
        pos.yPos=7;
      if(count==1)
        pos.xPos=0;
    if(count==2){
        pos.xPos=7;
    }
    }
}

std::vector <Posiotion> Rook::PossibleMove(int owner)
{
    std::vector<Posiotion> possibleMoves;
    int First_x=pos.xPos;
    int First_y=pos.yPos;
    for(int i=pos.yPos;i<=8;i++)
    {

        Posiotion a;
        a.yPos=i;
        a.xPos=First_x;
        possibleMoves.push_back(a);
    }
        pos.xPos=First_x;
        pos.yPos=First_y;
    for(int i=pos.yPos;i>0;i--)
    {
        Posiotion b;
        b.xPos=First_x;
        b.yPos=i;
        possibleMoves.push_back(b);
    }
    pos.xPos=First_x;
    pos.yPos=First_y;
    for(int i=pos.xPos;i<=8;i++)
    {
        Posiotion c;
        c.xPos=i;
        c.yPos=First_y;
        possibleMoves.push_back(c);
    }
    pos.xPos=First_x;
    pos.yPos=First_y;
    for(int i=pos.xPos;i>0;i--)
    {
        Posiotion d;
        d.xPos=i;
        d.yPos=First_y;
        possibleMoves.push_back(d);
    }
    return possibleMoves;
}

Rook::~Rook()
{

}
