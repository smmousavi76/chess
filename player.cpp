#include "Player.h"

Player::Player(int id)
{
 this->playerId=id;
 Piece_Count=16;
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
void Player::Attack(Piece *target ,Data data)
{

    int player_id=target->owner;
    int piece_id=target->typeId;
//    int vector_count=target->counter;
//    int sum=piece_id+vector_count-1;
    int a=vectorPos(target,data);
    pieces.erase(pieces.begin()+a);
    //player[player_id]->pieces.erase(player[player_id]->pieces.begin()+sum);

    Piece_Count--;

}
int Player::vectorPos(Piece *target,Data data)
{
    if(target==nullptr)
    return -1;

    else
    {
        for(int i=0;i<pieces.size();i++)
        {
        if(target==pieces[i])
                return i;
        }

    }
}

