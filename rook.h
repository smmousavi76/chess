#ifndef ROOK_H_INCLUDED
#define ROOK_H_INCLUDED
#include "Position.h"
#include "Piece.h"

 class Rook :public Piece
 {
 private:

 public:
        Rook(int owner);
        virtual ~Rook();

 };
 #endif
