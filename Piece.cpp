#include "Piece.h"
Piece::Piece(int owner)
{
this->owner = owner;

}
bool Piece::start(int count)
{

    if(1==count)
        return 1;
    if(count!=1)
        return 1;

}


Piece::~Piece()
{

}
void Piece::move(Posiotion  pos)
{
    this->pos=pos;
}
