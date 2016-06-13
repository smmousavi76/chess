#include "Knight.h"
#include "Position.h"
Knight::Knight(int owner,int count):Piece(owner)
{
 typeId=5;
   if(owner == 0)//white
    {
        if(count==1)
        pos.xPos = 2;
        else{
        pos.xPos=1;

        }
        pos.yPos = 1;
    }
    else if(owner == 1)//black
    {
       if(count==1)
        pos.xPos = 2;
        else{
        pos.xPos=8;

        }
        pos.yPos = 1;
    }
}
void Knight::move(Posiotion Pos)
{


}
Knight::~Knight()
{

}
