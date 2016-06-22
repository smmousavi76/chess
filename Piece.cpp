#include "Piece.h"
Piece::Piece(int owner)
{
this->owner = owner;

}
bool Piece::start()
{
    return  1;
}

Piece::~Piece()
{

}
void Piece::move(Posiotion  pos)
{
    this->pos=pos;
}
