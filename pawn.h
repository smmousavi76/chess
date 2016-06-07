#ifndef PAWN_H_INCLUDED
#define PAWN_H_INCLUDED
#include "Piece.h"

class Pawn:public Piece
{
private:


public:
    Pawn(int owner);
   virtual ~Pawn();
void move(Posiotion pos);
~Pawn();
};


#endif
