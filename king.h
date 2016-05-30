#ifndef KING_H_INCLUDED
#define KING_H_INCLUDED
#include "Piece.h"


class King:public Piece
{
private:

public:
    King(int owner);
    virtual ~King();
};
#endif
