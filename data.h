#ifndef DATA_H_INCLUDED
#define DATA_H_INCLUDED
#include "Piece.h"

struct Data
{
    std::vector<CPiece*> pieces;
    std::vector<Posiotion> possibleMoves;
};

#endif // DATA_H_INCLUDED
