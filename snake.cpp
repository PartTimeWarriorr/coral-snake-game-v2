#include "snake.hpp"
using std::list;


Snake::Snake(sf::Vector2f position, sf::RenderWindow& window)
{
    sf::RectangleShape head(sf::Vector2f(20, 20));

    this->tempDraw = head;

}