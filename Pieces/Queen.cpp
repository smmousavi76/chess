#include "Queen.h"

Queen::Queen(int owner):Piece( owner)
{


    if(owner == 0)//white
    {
         typeId = 3;

        pos.xPos = 4;
        pos.yPos = 0;
    }
    else if(owner == 1)//black
    {
        typeId=9;

        pos.xPos =4;
        pos.yPos = 7;
    }
}

std::vector <Posiotion> Queen:: PossibleMove(int owner)
{
    std::vector<Posiotion> possibleMoves;
    int First_x=pos.xPos;
    int First_y=pos.yPos;
    if (owner == 0){
        for(int i=pos.yPos;i<=8;i++)
    {

        Posiotion a;
        a.yPos=i;
        a.xPos=First_x;
        possibleMoves.push_back(a);
    }
        pos.xPos=First_x;
        pos.yPos=First_y;
    for(int i=pos.yPos;i>=0;i--)
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
    for(int i=pos.xPos;i>=0;i--)
    {
        Posiotion d;
        d.xPos=i;
        d.yPos=First_y;
        possibleMoves.push_back(d);
    }

    pos.xPos=First_x;
    pos.yPos=First_y;
    for(int i=1;i<8;i++)
    {
        possibleMoves.push_back(Posiotion(First_x+i,First_y+i));
        possibleMoves.push_back(Posiotion(First_x+i,First_y-i));
        possibleMoves.push_back(Posiotion(First_x-i,First_y+i));
        possibleMoves.push_back(Posiotion(First_x-i,First_y-i));
    }

    return possibleMoves;
    }
    else {
        for(int i=pos.yPos;i<=8;i++)
    {

        Posiotion a;
        a.yPos=i;
        a.xPos=First_x;
        possibleMoves.push_back(a);
    }
        pos.xPos=First_x;
        pos.yPos=First_y;
    for(int i=pos.yPos;i>=0;i--)
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
    for(int i=pos.xPos;i>=0;i--)
    {
        Posiotion d;
        d.xPos=i;
        d.yPos=First_y;
        possibleMoves.push_back(d);
    }

    pos.xPos=First_x;
    pos.yPos=First_y;
    for(int i=8;i>0;i--)
    {
        possibleMoves.push_back(Posiotion(First_x+i,First_y+i));
        possibleMoves.push_back(Posiotion(First_x+i,First_y-i));
        possibleMoves.push_back(Posiotion(First_x-i,First_y+i));
        possibleMoves.push_back(Posiotion(First_x-i,First_y-i));
    }

    return possibleMoves;
    }

}

Queen::~Queen()
{

}
