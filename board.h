#ifndef BOARD_H_INCLUDED
#define BOARD_H_INCLUDED
#include "Cell.h"
class Board:public sf::Drawble
{
private:
    int Height,Width;
    Cell **Cell;
    void draw(sf::RenderTarget& target, sf::RenderStates states);

public:
    Board(int Height,int Width);

};

#endif // CLIENT_H_INCLUDED
