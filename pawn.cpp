#include "Pawn.h"
#include "Position.h"
Pawn::Pawn(int owner,int count):Piece(owner)
{
   if(owner == 0)//white
    {
         typeId=5;

          pos.yPos=1;
          pos.xPos =count;


        pos.yPos = 1;
    }
    else if(owner == 1)//black
    {
        typeId=11;
        pos.xPos =count;
        pos.yPos = 6;
    }
    isFirstMove = 1;
}
std::vector <Posiotion> Pawn::PossibleMove(int owner)
{
//    int count1;

    std::vector<Posiotion> possibleMoves;
    int First_x=pos.xPos;
    int First_y=pos.yPos;
    if (owner == 0){
        if(isFirstMove){

         Posiotion a;
         a.xPos=First_x;
         a.yPos=pos.yPos+1;
         possibleMoves.push_back(a);
         a.yPos=pos.yPos+2;
         possibleMoves.push_back(a);
        isFirstMove = false;
        }
        else{

             Posiotion a;
             a.xPos=First_x;
             a.yPos=First_y;
             a.yPos=pos.yPos+1;
             possibleMoves.push_back(a);
        }


        return possibleMoves;
        }
    else {
        if(isFirstMove){
         Posiotion a;
         a.xPos=First_x;
         a.yPos=pos.yPos-1;
         possibleMoves.push_back(a);
         a.yPos=pos.yPos-2;
         possibleMoves.push_back(a);
         isFirstMove=false;
    }
    //count1++;
    else
    {


         Posiotion a;
         a.xPos=First_x;
         a.yPos=First_y;
         a.yPos=pos.yPos-1;
         possibleMoves.push_back(a);
    }
    count1++;
    return possibleMoves;

    }
}


Pawn::~Pawn()
{

}
