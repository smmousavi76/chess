#include "King.h"
King::King(int owner):Piece( owner)
{
 typeId=1;
  if(owner == 0)//white
    {
        //Black_White=0;
        pos.xPos = 5;
        pos.yPos = 1;
    }
    else if(owner == 1)//black
    {
        //Black_White=1;
        pos.xPos =5;
        pos.yPos = 8;
    }
}
void King::move(Posiotion pos)
{
    /*
    for(int i=pos.xPos;i=<8;i+=1)
    {
        for(int j=pos.yPos;i=<8;i-=1)
    }

PossibleMovesibeMoves.push_back(pos.xPos+1);
PossibleMovesibeMoves.push_back(pos.xPos-1);
PossibleMovesibeMoves.push_back(pos.xPos-2);
PossibleMovessibeMoves.push_back(pos.xPos+2);
PossibleMovesibeMoves.push_back(pos.yPos+1);
PossibleMovesibeMoves.push_back(pos.yPos-1);
PossibleMovesibeMoves.push_back(pos.yPos-2);
PossibleMovessibeMoves.push_back(pos.yPos+2);
*/




}
King::~King()
{

}
