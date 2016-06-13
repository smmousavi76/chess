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
