#ifndef BISHOP_H_INCLUDED
#define BISHOP_H_INCLUDED
#include "Piece.h"


class Bishop:public Piece
{
private:

public:
    Bishop(int owner);
    virtual ~Bishop();
};

#endif
