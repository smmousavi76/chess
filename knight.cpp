#include "Knight.h"
#include "Position.h"
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
void Knight::move(Posiotion Pos)
{
    int First_x=pos.xPos;
    int First_y=pos.yPos;


}
Knight::~Knight()
{

}
