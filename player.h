#ifndef PLAYER_H_INCLUDED
#define PLAYER_H_INCLUDED
#include"data.h"
#include <vector>

#include "Pieces/pawn.h"
#include "Pieces/King.h"
#include "Pieces/Queen.h"
#include "Pieces/Rook.h"
#include "Pieces/Knight.h"
#include "Pieces/Bishop.h"

class Player
{

public:
    int playerId;
    std::vector<Piece*> pieces;
    Player(int id);
    void prepair();
    int Piece_Count;
    void Attack(Piece *target ,Data data);
    int vectorPos(Piece *target ,Data data);
    void remove(Piece* target);
};

#endif // PLAYER_H_INCLUDED
