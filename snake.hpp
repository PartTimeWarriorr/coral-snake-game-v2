#pragma once
#include <SFML/Graphics.hpp>
#include <list>

using std::list;

struct BodyNode
{
    private:
    int coord_x;
    int coord_y;
    sf::Color color;
};

class Snake
{
    private:
    list<BodyNode> body; 
    int length;


    public:
    Snake(sf::Vector2f position, sf::RenderWindow& window);
    sf::RectangleShape tempDraw;

};