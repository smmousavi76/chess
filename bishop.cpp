#include "Bishop.h"

Bishop::Bishop(int owner,int count):Piece( owner)
{
 typeId = 4;


if(owner == 0)//white
{
pos.xPos=1;
    if(count==1)
        pos.yPos=3;
    else{
        pos.yPos=6;
    }
}
if(owner==1)
{
     if(count==1)
        pos.yPos=3;
    else{
        pos.yPos=6;
    }
    pos.xPos=8;
}
}

void Bishop::move(Posiotion Pos)
{
    int First_x=pos.xPos;
    int First_y=pos.yPos;
    for(int i=pos.xPos;i<=8;i++)
    {
        for(int j=pos.yPos;j<=8;j++)
        {


            Posiotion a;
            a.xPos=i;
            a.yPos=j;
            PossibleMoves.push_back(a);
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
            PossibleMoves.push_back(b);

        }
    }
    for(int i=pos.xPos;i>0;i--)
    {
        for(int j=pos.yPos;j>0;j--)
        {
            Posiotion c;
            c.xPos=i;
            c.yPos=j;
            PossibleMoves.push_back(c);
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
            PossibleMoves.push_back(d);
        }
    }
}
Bishop::~Bishop()
{

}
