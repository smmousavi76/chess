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
    int count_piecce;
    int playerId;
    int score;
    std::vector<Piece*> pieces;
    Player(int id);
    void prepair();
};

#endif // PLAYER_H_INCLUDED
