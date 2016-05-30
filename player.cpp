#include "Player.h"
Player::Player(int id)
{
 this->playerId=id;
}

void Player::prepair()
{
    pieces.clear();
    pieces.push_back(new King(playerId));
    pieces.push_back(new Queen(playerId));
    pieces.push_back(new Pawn(playerId));//1
    pieces.push_back(new Pawn(playerId));//2
    pieces.push_back(new Pawn(playerId));//3
    pieces.push_back(new Pawn(playerId));//4
    pieces.push_back(new Pawn(playerId));//5
    pieces.push_back(new Pawn(playerId));//5
    pieces.push_back(new Pawn(playerId));//6
    pieces.push_back(new Pawn(playerId));//7
    pieces.push_back(new Pawn(playerId));//8
    pieces.push_back(new Rook(playerId));
    pieces.push_back(new Rook(playerId));
    pieces.push_back(new Knight(playerId));
    pieces.push_back(new Knight(playerId));
    pieces.push_back(new Bishop(playerId));
    pieces.push_back(new Bishop(playerId));
}
