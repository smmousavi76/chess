#ifndef KNIGHT_H_INCLUDED
#define KNIGHT_H_INCLUDED
#include "Piece.h"

class Knight:public Piece
{
public:
    Knight(int owner,int count);
    virtual ~Knight ();
    std::vector <Posiotion> PossibleMove(int owner);

};
#endif
