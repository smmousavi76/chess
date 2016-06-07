#ifndef CELL_H_INCLUDED
#define CELL_H_INCLUDED

#include <SFML/Graphics.hpp>
#include <vector>
//#include "Board.h"
class Cell:public sf::Drawable, public sf::Transformable

{
private:
        virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;


    sf::RectangleShape rectangle;
    bool color;

public:

    Cell(bool c,int size);
    bool getColor();


};
#endif // cell_H_INCLUDED
