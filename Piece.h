#ifndef PIECE_H_INCLUDED
#define PIECE_H_INCLUDED
#include "MouseEvent.h"
#include "CPiece.h"
#include "Position.h"
#include "Piece.h"

class Piece : public CPiece
{
public:
    bool start(int count);
    bool White_Black;
    MouseEvent mouse;
    Piece(int owner);
    virtual ~Piece();
    int count1;
  //  virtual bool attack(Piece* defender) = 0;
    void move(Posiotion pos) ;
    virtual std::vector<Posiotion > PossibleMove(int owner)=0;
    bool enemy;
};

#endif // PIECE_H_INCLUDED
