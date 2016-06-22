#ifndef PLAYER_H_INCLUDED
#define PLAYER_H_INCLUDED

#include <vector>

#include "Piece.h"
#include "Pawn.h"
#include "King.h"
#include "Queen.h"
#include "Rook.h"
#include "Knight.h"
#include "Bishop.h"

class Player
{

public:
    int playerId;
    std::vector<Piece*> pieces;
    Player(int id);
    void prepair();
    int Piece_Count;
};

#endif // PLAYER_H_INCLUDED
