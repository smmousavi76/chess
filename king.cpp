#include "King.h"
#include <iostream>
King::King(int owner):Piece( owner)
{
  if(owner == 0)//white
    {
     typeId=2;

        //Black_White=0;
        pos.xPos = 3;
        pos.yPos = 0;
    }
     if(owner == 1)//black
    {
        std::cout<<"hhhhhh";
        typeId=8;
        //Black_White=1;
        pos.xPos =3;
        pos.yPos = 7;

    }

}
std::vector <Posiotion> King::PossibleMove()
{
    std::vector<Posiotion> possibleMoves;
    int First_x=pos.xPos;
    int First_y=pos.yPos;
    Posiotion a;
    a.xPos=pos.xPos;
    a.yPos=pos.yPos+1;
    possibleMoves.push_back(a);
    a.yPos=pos.yPos+1;
    possibleMoves.push_back(a);
    a.xPos=pos.xPos+1;
    a.yPos=pos.yPos;
    possibleMoves.push_back(a);
    a.xPos=pos.xPos-1;
    a.yPos=pos.yPos;
    possibleMoves.push_back(a);
    a.xPos=pos.xPos+1;
    a.yPos=pos.yPos+1;
    possibleMoves.push_back(a);
    a.xPos=pos.xPos-1;
    a.yPos=pos.yPos+1;
    possibleMoves.push_back(a);
    a.xPos=pos.xPos+1;
    a.yPos=pos.yPos-1;
    possibleMoves.push_back(a);
    a.xPos=pos.xPos-1;
    a.yPos=pos.yPos-1;
    possibleMoves.push_back(a);

}
King::~King()
{

}

