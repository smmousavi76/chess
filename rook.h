#ifndef ROOK_H_INCLUDED
#define ROOK_H_INCLUDED
#include "Position.h"
#include "Piece.h"

 class Rook :public Piece
 {
 public:
    std::vector <Posiotion> PossibleMove();
    Rook(int owner,int count);
    virtual ~Rook();
 };
 #endif
