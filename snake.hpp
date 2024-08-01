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

enum Direction
{
    UP,
    DOWN,
    LEFT,
    RIGHT
};

class Snake : public sf::Drawable
{
    private:
    list<sf::RectangleShape> body; 
    int length;
    Direction dir = UP;

    // How big each individual part of the snake is
    float part_size = 20.f;

    virtual void draw(sf::RenderTarget &target, sf::RenderStates states) const override;
    void updateDirection();

    public:
    Snake(sf::Vector2f position);
    void move();
    void loopOver();


};