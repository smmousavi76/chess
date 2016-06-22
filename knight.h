#ifndef KNIGHT_H_INCLUDED
#define KNIGHT_H_INCLUDED
#include "Piece.h"

class Knight:public Piece
{
private:

public:
    std::vector<Posiotion> possibleMoves;
    Knight(int owner,int count);
    virtual ~Knight ();
    std::vector <Posiotion> PossibleMove();

};
#endif
