#ifndef QUEEN_H_INCLUDED
#define QUEEN_H_INCLUDED
#include "Piece.h"
#include "Position.h"
class Queen :public Piece
{
public:
    std::vector <Posiotion> PossibleMove(int owner);
    Queen(int owner);
    virtual ~Queen();

};

#endif
