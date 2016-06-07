#ifndef BOARD_H_INCLUDED
#define BOARD_H_INCLUDED
#include "Cell.h"
#include <SFML/Graphics.hpp>

class Board:public sf::Drawable
{
private:
    int Height,Width;
    Cell ***cells;
    void draw(sf::RenderTarget& target, sf::RenderStates states);

public:
    Board(int h,int w);
};

#endif // CLIENT_H_INCLUDED
