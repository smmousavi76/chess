#ifndef CPIECE_H_INCLUDED
#define CPIECE_H_INCLUDED
#include <vector>
#include "Position.h"

struct CPiece
{
    int typeId;
    int owner;
    Posiotion pos;
    std::vector<Posiotion> possibleMoves;
};

#endif // CPIECE_H_INCLUDED
