#include "Update.h"
void Update::prepair()
{
    player[0]->prepair();
    player[1]->prepair();

}
void Update::phaseChanger()
{

    phase = (phase+1)%2;

}

void Update::playerChanger()
{
    playerTurn = (playerTurn+1)%2;
}
Update::Update()
{
    for(int i=0;i<2;i++)
        player[i] = new Player(i);
        playerTurn = 0;
        phase = -1;
}
void Update::getEvent(MouseEvent& mouse,Data& data)
{

    std::cout <<phase <<"\n";
    if(phase == -1)
    {
        this->prepair();
        this->makeData(data);
        phaseChanger();
        return;
    }
    if(mouse.clicked)
    {
        translatePos(mouse.pos);
        target = whichPiece(mouse.pos);
        if(phase == 0) ///Phase Select Mine Piece
        {
            if(target != nullptr)
                if(target->owner == playerTurn)
                {
                    for(auto po : target->PossibleMove(target->owner))
                    {
                       // std::cout«"po \n ";
                        Piece *a;
                        //std::cout«"po 2 \n ";
                        a=whichPiece(po);
                        //std::cout«"po 3 \n";
                        if(a!=nullptr)
                        {
                            if(a->owner!=target->owner)
                            {
                                   data.possibleMoves.push_back(po);
                            }
                        }
                        else
                        {
                            data.possibleMoves.push_back(po);
                        }
                    }
                    if(data.possibleMoves.size()>0)
                    {
                        lastTarget = target;
                        phaseChanger();
                    }
                }
        }
        if(phase == 1)
        {
            std::cout<<" clicked 5  ";
            bool flag = false;
            for(int i=0;i<data.possibleMoves.size();i++)
                if(mouse.pos == data.possibleMoves[i])
                {
                    flag = true;
                    break;
                }
            if(flag)
            {
                target = whichPiece(mouse.pos);
                if(target == nullptr)
                {
                    lastTarget->move(mouse.pos);
                    data.possibleMoves.clear();
                    phaseChanger();
                    playerChanger();
                }
                else if(target->owner == (playerTurn+1)%2)
                {
                    lastTarget->move(mouse.pos);

                    player[(playerTurn+1)%2]->remove(target);
                    this->makeData(data);
                    data.possibleMoves.clear();
                    phaseChanger();
                    playerChanger();
                }

            }
        }
    }
//    target->start();
    return;
}

void Update::makeData(Data& data)
{
    data.pieces.clear();
    for(int j=0;j<2;j++)
        {
            for(int i=0;i<player[j]->pieces.size();i++)
            {
                data.pieces.push_back(player[j]->pieces[i]);
            }

        }
}

bool Update::finish()
{
    if(player[2]->Piece_Count==0||player[1]->Piece_Count==0)
        return 1;
    else return 0;
}

Update::~Update()
{

}
void Update::translatePos(Posiotion& pos)
{
    pos.xPos /= 100;
    pos.yPos /= 100;
}

Piece* Update::whichPiece(Posiotion pos)
{
    for (int i=0 ; i<player[playerTurn]->pieces.size() ; i++)
    {
        if(pos == player[playerTurn]->pieces[i]->pos)
        {
            return player[playerTurn]->pieces[i];
        }
    }
    for (int i=0 ; i<player[(playerTurn+1)%2]->pieces.size() ; i++)
    {
        if(pos == player[(playerTurn+1)%2]->pieces[i]->pos)
        {
            return player[(playerTurn+1)%2]->pieces[i];
        }
    }
    return nullptr;
}
//<<<<<<< Updated upstream

/*
std::vector<CPiece *> Update::write(std::string recieved);
=======
void Update::Attack(Piece *target ,Data data)
{

    int player_id=target->owner;
    int piece_id=target->typeId;
//    int vector_count=target->counter;
//    int sum=piece_id+vector_count-1;
    int a=vectorPos(target,data);
    player[player_id]->pieces.erase(player[player_id]->pieces.begin()+a);
    //player[player_id]->pieces.erase(player[player_id]->pieces.begin()+sum);
    player[player_id]->Piece_Count--;

}

int Update::vectorPos(Piece *target,Data data)
{
    if(target==nullptr)
    return -1;

    else
    {
        for(int i=0;i<data.pieces.size();i++)
        {
        if(target==data.pieces[i])
                return i;
        }

    }
}
*/
int Update::check(int a)
{
    if(a==2)
        return 1;
    else
        return 2;
}
vector<CPiece *> Update::write(string recieved)
//>>>>>>> Stashed changes
{
    Data data;
 for(int i=0;i=recieved.size();i++)
 {
     data.pieces[4*i]->pos.xPos=recieved[4*i];
     data.pieces[4*i+1]->pos.yPos=recieved[4*i+1];
     data.pieces[4*i+2]->typeId=recieved[4*i+2];
     data.pieces[4*i+3]->owner=recieved[4*i+3];

 }
 return data.pieces;

}

string Update::read(Data data )
{


    string send;
    for(int i=0;i<player[playerTurn]->pieces.size();i++)
    {
       send[4*i]=data.pieces[4*i]->pos.xPos;
       send[4*i+1]=data.pieces[4*i+1]->pos.yPos;
       send[4*i+2]=data.pieces[4*i+2]->typeId;
       send[4*i+3]=data.pieces[4*i+3]->owner;
    //player->pieces[i]->pos
    }
    return send;
}

void Update::send_socket(string send,Data data)
{

    sf::TcpSocket socket;
    send=read(data);
	socket.connect("127.0.0.1", 55001);
	socket.send(send.c_str(), send.size());


}
vector<CPiece*> Update::translate_socket(vector<CPiece *> send)
{
    sf::TcpListener listener;
	listener.listen(55001);
	sf::TcpSocket socket;
	listener.accept(socket);
	cout << "New client connected: " << socket.getRemoteAddress() << std::endl;
	string buffer;
	std::size_t received ;
	int a=sizeof(buffer);
	//socket.receive(buffer,a , received)
    vector <CPiece*> recieved1;
    recieved1=write(buffer);
    return recieved1;
}

