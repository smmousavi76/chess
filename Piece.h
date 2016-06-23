#ifndef PIECE_H_INCLUDED
#define PIECE_H_INCLUDED
#include "MouseEvent.h"
#include "CPiece.h"
#include "Position.h"
#include "Piece.h"

class Piece : public CPiece
{
public:
    std::vector<Posiotion > possibleMoves;
    bool start();
    bool White_Black;
    MouseEvent mouse;
    Piece(int owner);
    virtual ~Piece();
  //  virtual bool attack(Piece* defender) = 0;
     void move(Posiotion pos) ;
    virtual std::vector<Posiotion > PossibleMove()=0;
};

#endif // PIECE_H_INCLUDED
