#include "Knight.h"

Knight::Knight(int owner,int count):Piece(owner)
{
   if(owner == 0)//white
    {
         typeId=1;

        pos.yPos=0;
        if(count==1)
        pos.xPos = 1;
        if(count==2){
        pos.xPos=6;
        }
    }
    else if(owner == 1)//black
    {
        typeId=7;

       if(count==1)
        pos.xPos = 1;
        if(count==2){
        pos.xPos=6;

        }
        pos.yPos = 7;
    }
}
std::vector <Posiotion> Knight::PossibleMove(int owner)
{
    std::vector<Posiotion> possibleMoves;
    int First_x=pos.xPos;
    int First_y=pos.yPos;
    Posiotion a;

    a.xPos = pos.xPos-1;
    a.yPos = pos.yPos+2;
    possibleMoves.push_back(a);
    a.xPos=First_x;
    a.yPos=First_y;
    a.xPos = pos.xPos-1;
    a.yPos = pos.yPos-2;
    possibleMoves.push_back(a);
a.xPos=First_x;
    a.yPos=First_y;
    a.xPos = pos.xPos+1;
    a.yPos = pos.yPos-2;
    possibleMoves.push_back(a);
    a.xPos=First_x;
    a.yPos=First_y;
    a.xPos = pos.xPos+1;
    a.yPos = pos.yPos+2;
    possibleMoves.push_back(a);
    a.xPos=First_x;
    a.yPos=First_y;

    a.xPos = pos.xPos-2;
    a.yPos = pos.yPos-1;
    possibleMoves.push_back(a);
    a.xPos=First_x;
    a.yPos=First_y;
    a.xPos = pos.xPos-2;
    a.yPos = pos.yPos+1;
    possibleMoves.push_back(a);
a.xPos=First_x;
    a.yPos=First_y;
    a.xPos = pos.xPos+2;
    a.yPos = pos.yPos-1;
    possibleMoves.push_back(a);
    a.xPos=First_x;
    a.yPos=First_y;
    a.xPos = pos.xPos+2;
    a.yPos = pos.yPos+1;
    possibleMoves.push_back(a);
    return possibleMoves;
}
Knight::~Knight()
{

}
