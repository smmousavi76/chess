#ifndef PAWN_H_INCLUDED
#define PAWN_H_INCLUDED

#include "../Piece.h"

class Pawn:public Piece
{
    bool isFirstMove;
public:
    Pawn(int owner,int count);
    virtual ~Pawn();
    std::vector <Posiotion> PossibleMove(int owner);

};


#endif
