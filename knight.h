#ifndef KNIGHT_H_INCLUDED
#define KNIGHT_H_INCLUDED
#include "Piece.h"

class Knight:public Piece
{
private:

public:
    Knight(int owner);
    virtual ~Knight ();
    void move(Posiotion pos);
};
#endif
