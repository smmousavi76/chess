#ifndef QUEEN_H_INCLUDED
#define QUEEN_H_INCLUDED
#include "Piece.h"
#include "Position.h"
class Queen :public Piece
{
private:


public:
   // std::vector<Posiotion> possibleMoves;
    std::vector <Posiotion> PossibleMove();

    Queen(int owner);
    virtual ~Queen();

};

#endif
