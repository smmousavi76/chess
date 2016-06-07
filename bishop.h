#ifndef BISHOP_H_INCLUDED
#define BISHOP_H_INCLUDED
#include "Piece.h"
#include "Position.h"
#include "CPiece.h"
#include <vector>
using namespace std;
class Bishop:public Piece
{

public:
    Bishop(int owner);
    virtual ~Bishop();
    void move(Posiotion pos);
};

#endif
