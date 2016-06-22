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
    std::vector<Posiotion> possibleMoves;
    Bishop(int owner,int count);
    virtual ~Bishop();
    std::vector <Posiotion> PossibleMove();
};

#endif
