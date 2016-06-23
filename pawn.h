#ifndef PAWN_H_INCLUDED
#define PAWN_H_INCLUDED
#include "Piece.h"

class Pawn:public Piece
{
public:
    Pawn(int owner,int count);
    virtual ~Pawn();
    std::vector <Posiotion> PossibleMove();

};


#endif
