#ifndef CELL_H_INCLUDED
#define CELL_H_INCLUDED

#include <SFML/Graphics.hpp>
#include <vector>

class Cell:public sf::Drawable, public sf::Transformable

{
private:
    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const=0;
    sf::RectangleShape rectangle;
    bool color;

public:
    Board(bool color,int size);
    bool GetColor();



};
#endif // cell_H_INCLUDED
