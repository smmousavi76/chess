#ifndef KING_H_INCLUDED
#define KING_H_INCLUDED

#include "../Piece.h"

class King:public Piece
{
public:
    King(int owner);
    virtual ~King() ;
    std::vector <Posiotion> PossibleMove(int owner);

};

#endif
