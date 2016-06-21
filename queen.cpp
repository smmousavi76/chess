#include "Queen.h"
#include "Position.h"
#include <iostream>
Queen::Queen(int owner):Piece( owner)
{


    if(owner == 0)//white
    {
         typeId = 3;

       // Black_White=0;
        pos.xPos = 4;
        pos.yPos = 0;
    }
    else if(owner == 1)//black
    {
        typeId=9;
    std::cout<<"salam";
      //  Black_White=1;
        pos.xPos =4;
        pos.yPos = 7;
    }
}

void Queen::move(Posiotion pos)
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

Queen::~Queen()
{

}
