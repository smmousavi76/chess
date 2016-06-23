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
    for(int i=pos.xPos;i<=8;i++)
    {
        for(int j=pos.yPos;j<=8;j++)
        {


            Posiotion a;
            a.xPos=i;
            a.yPos=j;
            possibleMoves.push_back(a);
    }
    }
    pos.xPos=First_x;
    pos.yPos=First_y;
    for(int i=pos.xPos;i>0;i++)
    {
        for(int j=pos.yPos;j>=8;j++)
        {
            Posiotion b;
            b.xPos=i;
            b.yPos=j;
            possibleMoves.push_back(b);

        }
    }
    for(int i=pos.xPos;i>0;i--)
    {
        for(int j=pos.yPos;j>0;j--)
        {
            Posiotion c;
            c.xPos=i;
            c.yPos=j;
            possibleMoves.push_back(c);
        }
    }
    pos.xPos=First_x;
    pos.yPos=First_y;
    for(int i=pos.xPos;i<=8;i++)
    {
        for(int j=pos.yPos;j>0;j--)
        {
            Posiotion d;
            d.xPos=i;
            d.yPos=j;
            possibleMoves.push_back(d);
        }
    }
    ;
    return possibleMoves;
}
Bishop::~Bishop()
{

}
