#include "Bishop.h"

Bishop::Bishop(int owner,int count):Piece( owner)
{


if(owner == 0)//white
{
     typeId = 0;

pos.yPos=0;
    if(count==1)

        pos.xPos=2;
    else{
        pos.xPos=5;
}
}
if(owner==1)
{
    typeId=6;
     if(count==1)
        pos.xPos=2;
    else{
        pos.xPos=5;
    }
    pos.yPos=7;
}

}


std::vector <Posiotion> Bishop::PossibleMove()
{
    std::vector<Posiotion> possibleMoves;
    int First_x=pos.xPos;
    int First_y=pos.yPos;
    for(int i=1;i<8;i++)
    {
        possibleMoves.push_back(Posiotion(First_x+i,First_y+i));
        possibleMoves.push_back(Posiotion(First_x+i,First_y-i));
        possibleMoves.push_back(Posiotion(First_x-i,First_y+i));
        possibleMoves.push_back(Posiotion(First_x-i,First_y-i));
    }

    return possibleMoves;
}

Bishop::~Bishop()
{

}
