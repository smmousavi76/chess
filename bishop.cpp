#include "Bishop.h"

Bishop::Bishop(int owner):Piece( owner)
{
 typeId = 4;
 int counter=0;

    if(owner == 0)//white
    {
       // Black_White=0;
if(counter==0)
    {
    pos.xPos = 1;
    pos.yPos = 1;
}
else
{
 pos.xPos=8;
 pos.yPos=1;
}
    }



    else if(owner == 1)//black
    {
        //Black_White=1;
        if(counter==0)
        {
        pos.xPos = 1;
        pos.yPos = 8;
        }
        else
        {
            pos.xPos=8;
            pos.yPos=8;
        }
    }
    counter++;
}

void Bishop::move(Posiotion Pos)
{
/*
 for(int i=Pos.xPos;i=<8;i+=1)
 {
      for(int j=Pos.yPos;j==0;j-=1)
 {
  PossibleMoves.push_back(Pos.yPos);
  PossibleMoves.push_back(Pos.xPos);
 }
 }
for(int i=Pos.yPos;i=<8;i+=1)
 {
      for(int j=Pos.xPos;j==0;j-=1)
 {
  PossibleMoves.push_back(Pos.yPos);
  PossibleMoves.push_back(Pos.xPos);
 }

 }
*/

}
Bishop::~Bishop()
{

}
