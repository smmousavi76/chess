#ifndef PAWN_H_INCLUDED
#define PAWN_H_INCLUDED
#include "Piece.h"

class Pawn:public Piece
{
private:


public:
   // std::vector<Posiotion> possibleMoves;
    Pawn(int owner,int count);
   virtual ~Pawn();
    std::vector <Posiotion> PossibleMove();

};


#endif
