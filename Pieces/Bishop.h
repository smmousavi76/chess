#ifndef BISHOP_H_INCLUDED
#define BISHOP_H_INCLUDED

#include "../Piece.h"

class Bishop:public Piece
{
public:
    Bishop(int owner,int count);
    virtual ~Bishop();
    std::vector <Posiotion> PossibleMove(int owner);
};

#endif
