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
    pieces.push_back(new Pawn(playerId,0));//1
    pieces.push_back(new Pawn(playerId,1));//2
    pieces.push_back(new Pawn(playerId,2));//3
    pieces.push_back(new Pawn(playerId,3));//4
    pieces.push_back(new Pawn(playerId,4));//5
    pieces.push_back(new Pawn(playerId,5));//6
    pieces.push_back(new Pawn(playerId,6));//7
    pieces.push_back(new Pawn(playerId,7));//8
    pieces.push_back(new Rook(playerId,1));
    pieces.push_back(new Rook(playerId,2));
    pieces.push_back(new Knight(playerId,1));
    pieces.push_back(new Knight(playerId,2));
    pieces.push_back(new Bishop(playerId,1));
    pieces.push_back(new Bishop(playerId,2));

}

