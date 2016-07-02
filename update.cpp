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
    Piece *a,*b,*c;
    char data[6];//= {'1', '2', '3', '4', '5','6'};
    bool flag=1;
    ///send "data" using socket
    //char data[6];
    packet>>req.from>>req.to;
    /*
    b=whichPiece(req.from);
    if(b->owner==0)
    data[0]='0';
    if(b->owner==1)
    data[0]='1';
    data[1]=b->typeId+48;
    data[2]=req.from.xPos+48;
    data[3]=req.from.yPos+48;
    data[4]=req.to.xPos+48;
    data[5]=req.to.yPos+48;


    cout << " sending " ;
    for(int i =0; i < 6; ++i)   cout <<data[i];
    cout <<endl;
    socket.send(data, 6);
    cout <<"sended \n";
    */
    connection.sendPacket(packet);
    playerTurn=(playerTurn+1)%2;
}

void Update::recieveData()
{
    //sf::Thread th(&Update::thread_receive, this);
   // th.launch();
    //a.terminate();
    packet=connection.receivePacket();
    Request a;
    packet<<a;
    Piece *from;
    from=whichPiece(a.from);
    cout<<a.from.xPos<<" "<<a.from.yPos<<" "<<a.to.xPos<<" "<<a.to.yPos;
    for(int i=0;i<player[(playerTurn+1)%2]->pieces.size();i++)
    {
    if(player[(myTurn+1)%2]->pieces[i]->typeId==from->typeId&&player[(myTurn+1)%2]->pieces[i]->pos.xPos==from->pos.xPos&&player[(myTurn+1)%2]->pieces[i]->pos.yPos==from->pos.yPos)
    {

    player[(myTurn+1)%2]->pieces[i]->pos.xPos=a.to.xPos;
    player[(myTurn+1)%2]->pieces[i]->pos.yPos=a.to.yPos;

    }
    }
    /*
    std::size_t received=6;
    bool flag=1;


    // TCP socket:
    //coumt << "before recieve";
    if(socket.receive(data, 6, received) != sf::Socket::Status::Done)
    return;
    int a_data,b_data,c_data,d_data,e_data;
   // int owner=a->owner;

    //cout<<data[0]<<data[1]<<data[2]<<data[3]<<data[4]<<data[5];
    if(data[0]!='/0'&&data[1]!='/0'&&data[2]!='\0'&&data[3]!='/0'&&data[4]!='/0'&&data[5]!='/0')
    {
    cout<<"data is "<<data[0]<<data[1]<<data[2]<<data[3]<<data[4]<<data[5];
    if(data[0]=='0')
    a->owner=0;
    if(data[0]=='1')
    a->owner=1;
    a_data=data[1];//1=typeid
    b_data=data[2];//2=xpos from
    c_data=data[3];//3=ypos from
    d_data=data[4];//4 xpos to
    e_data=data[5];//5= ypos to
    a->typeId=a_data-48;
    b->typeId=a->typeId;
    a->pos.xPos=b_data-48;
    a->pos.yPos=c_data-48;
    b->pos.xPos=d_data-48;
    b->pos.yPos=e_data-48;



    for(int i=0;i<=player[(myTurn+1)%2]->pieces.size();i++)
    {
        if(player[(myTurn+1)%2]->pieces[i]->typeId==a->typeId&&player[(myTurn+1)%2]->pieces[i]->pos.xPos==a->pos.xPos&&player[(myTurn+1)%2]->pieces[i]->pos.yPos==a->pos.yPos)
        {
            player[(myTurn)%2]->pieces[i]->pos.xPos==b->pos.xPos;
            player[(myTurn+1)%2]->pieces[i]->pos.yPos==b->pos.yPos;

    }
    }
*/
            playerTurn=(playerTurn+1)%2;
    }




// : sendT(&Update::playerChanger, this), receiveT(&Update::recieveData,this)

Update::Update(int mt)
{


    myTurn = mt;
    count=0;
    for(int i=0; i<2; i++)
        player[i] = new Player(i);
        int i;
        //cout<<" player \n";
       // cin>>i;
    playerTurn = 1;
    phase = -1;

}

void Update::start()
{


    if(myTurn==1)///PlayerId
    {
    if(socket.connect("localhost", 53000) != sf::Socket::Done)
        cout <<"client connect is field  \n";

    if(socket.connect("localhost",53000)==sf::Socket::Done)
        cout<<"client connect is ok \n ";

    std::cout << "New client connected: " << socket.getRemoteAddress() << std::endl;

    }
    if(myTurn==0)
    {
            connection.start();
/*
        sf::TcpListener listener;
        if (listener.listen(43001) != sf::Socket::Done)
        {
        cout << "server connection field \n";
        }
        if(listener.listen(43001)==sf::Socket::Done)
        cout<<" server is ok \n";
        sf::TcpSocket client;
        if(listener.accept(client) == sf::Socket::Done)
        cout <<"client accepted \n";
        */

    }
    return ;

}

void Update::getEvent(MouseEvent& mouse,Data& data)
{

    sf::SocketSelector selector;
    selector.add(socket);
    if(phase == -1)
    {

        this->prepair();
        this->makeData(data);
        phaseChanger();
        return;
    }

  //  recieveData();
    if(mouse.clicked)


    if(playerTurn!=myTurn)
    {

        //sf::Time timeout=sf::seconds(.5f);
        //sf::SocketSelector selector;
        //selector.add(socket);
        //cout << selector.wait(timeout);
   // if (selector.wait(timeout)){
           // cout << "before recieve \n";
          //  recieveData();
//            receiveT.launch();
            //cout << "$";
   // }
    //cout << "after ready if \n";

    //else cout <<"sads";

    }

    if(playerTurn==myTurn&&mouse.clicked)
    {
        count++;
        translatePos(mouse.pos);
        target = whichPiece(mouse.pos);
        if(phase == 0) ///Phase Select Mine Piece
        {
            if(target != nullptr)
                if(target->owner == playerTurn)
                {
                    for(auto po : target->PossibleMove(target->owner))
                    {
                        Piece* tmp = whichPiece(po);
                        if(tmp==nullptr)
                        {
                            if(check(target, po))
                                data.possibleMoves.push_back(po);
                        }
                        else if(tmp->owner!= target->owner)
                        {
                            if(check(target, po))
                                data.possibleMoves.push_back(po);
                        }
                    }
                    if(data.possibleMoves.size()>0)
                    {
                        std::cout <<data.possibleMoves.size() <<"\n";
                        for(auto po:data.possibleMoves)
                        {
                            std::cout <<po.xPos <<" " <<po.yPos <<"\n";
                        }
                        lastTarget = target;
                        phaseChanger();
                    }
                }
        }
        if(phase == 1)
        {
            bool flag = false;
            for(int i=0; i<data.possibleMoves.size(); i++)
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
                    cout <<".";
                    req.from = lastTarget->pos;
                    req.to = mouse.pos;
                    //sendT.launch();
                }
                else if(target->owner == (playerTurn+1)%2)
                {
                    lastTarget->move(mouse.pos);
                    player[(playerTurn+1)%2]->remove(target);
                    this->makeData(data);
                    data.possibleMoves.clear();
                    phaseChanger();
                    req.from = lastTarget->pos;
                    req.to = target->pos;
                   // sendT.launch();
                }
            }
        }

    }
//    a.terminate();
    return;


}

void Update::makeData(Data& data)
{
    data.pieces.clear();
    for(int j=0; j<2; j++)
    {
        for(int i=0; i<player[j]->pieces.size(); i++)
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
bool Update::check(Piece* target, Posiotion pos)
{
    if(target->typeId == 4||target->typeId==10) ///Rook
    {
        if(pos.xPos == target->pos.xPos)
        {
            for(int i=min(pos.yPos, target->pos.yPos)+1;i<max(pos.yPos, target->pos.yPos);i++ )
            {
                if(this->whichPiece(Posiotion(pos.xPos, i))!= nullptr)
                    return false;
            }
            return true;
        }
        if(pos.yPos == target->pos.yPos)
        {
            for(int i=min(pos.xPos, target->pos.xPos)+1;i<max(pos.xPos, target->pos.xPos);i++ )
            {
                if(this->whichPiece(Posiotion(i, pos.yPos))!= nullptr)
                    return false;
            }
            return true;
        }
    }
    else
        return 1;
}
