#ifndef QUEEN_H_INCLUDED
#define QUEEN_H_INCLUDED
#include "Piece.h"
#include "Position.h"
class Queen :public Piece
{
private:


public:
    Queen(int owner);
    virtual ~Queen();

};

#endif
