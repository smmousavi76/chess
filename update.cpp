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
    playerTurn = (playerTurn+1)%3;
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
        Piece *target2,*target3;
        /*
    if(target!=nullptr)
{


        if(target->owner==0)
        {
        Posiotion pos,pos1;
        pos.xPos=mouse.pos.xPos+1;
        pos.yPos=mouse.pos.yPos+1;
        pos1.xPos=mouse.pos.xPos-1;
        pos1.yPos=mouse.pos.yPos+1;
        translatePos(pos);
        translatePos(pos1);
        target3=whichPiece(pos1);
        target2=whichPiece(pos);
        if((target2!=nullptr||target3!=nullptr)&&target!=nullptr)
        {
          if(target2->owner!=target->owner||target3->owner!=target->owner)
            {

                target->enemy=1;
            }
        }
        }
        if(target->owner==1)
       {
        Posiotion pos,pos1;
        pos.xPos=mouse.pos.xPos+1;
        pos.yPos=mouse.pos.yPos-1;
        pos1.xPos=mouse.pos.xPos-1;
        pos1.yPos=mouse.pos.yPos-1;
        translatePos(pos);
        translatePos(pos1);
        target3=whichPiece(pos1);
        target2=whichPiece(pos);
            if((target2!=nullptr||target3!=nullptr)&&target!=nullptr)
        {
          if(target2->owner!=target->owner||target3->owner!=target->owner)
            {

                target->enemy=1;
            }
       }
       }

}
*/
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
                                ///pawn attack bishop
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
        if(phase==2)
        {
//         if()
        }
    }

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
int Update::check(int a)
{
    if(a==2)
        return 1;
    else
        return 2;
}
Data Update::string_to_vector(string recieved)
{
    Data data;
 for(int i=0;i=recieved.size();i++)
 {


    player[check(playerTurn)]->pieces[4*i]->pos.xPos=recieved[4*i];
    player[check(playerTurn)]->pieces[4*i+1]->pos.xPos=recieved[4*i+1];
    player[check(playerTurn)]->pieces[4*i+1]->pos.xPos=recieved[4*i+2];
    player[check(playerTurn)]->pieces[4*i+1]->pos.xPos=recieved[4*i+3];



 }
 return data ;


}

string Update::vector_to_string(Data data )
{


    string send;
    for(int i=0;i<player[playerTurn]->pieces.size();i++)
    {
       send[4*i]=data.pieces[4*i]->pos.xPos;
       send[4*i+1]=data.pieces[4*i+1]->pos.yPos;
       send[4*i+2]=data.pieces[4*i+2]->typeId;
       send[4*i+3]=data.pieces[4*i+3]->owner;

    }
    return send;
}
string Update::char_to_string(char *a)
{
    string out(a);
    return a;


}
char *Update::string_to_char(string a)
{
  char * c = new char [a.length()+1];
  std::strcpy (c, a.c_str());


  char * p = std::strtok (c,NULL);

 return p;
}

bool Update::send_socket(Data data)
{
   string send;
    sf::TcpSocket socket;

    send=vector_to_string(data);
    char *a;
    a= new char[100];
    a=string_to_char(send);


    sf::Socket::Status status = socket.connect("192.168.0.5", 53000);
    socket.send(a, send.size());
    if (status != sf::Socket::Done)
    {
        cout<<" error sending \n";
       return 0;         // error...
    }
    else return 1;

}


bool Update::translate_socket(string recieved)
{
    sf::TcpListener listener;
	listener.listen(55001);
	sf::TcpSocket socket;
	listener.accept(socket);
	std::size_t received1 ;
	int a=sizeof(recieved);
    char recieved2[100];
	if (socket.receive(recieved2, 100, received1) != sf::Socket::Done)
    {
        cout<<"error recieved \n";
        return 0;
    }


    else
    {
    Data a;
    string convert;
    convert=char_to_string(recieved2);
    a=string_to_vector(convert);
    makeData(a);
    return 0;

    }
}

