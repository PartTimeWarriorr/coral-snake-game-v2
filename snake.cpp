#include "snake.hpp"
using std::list;

#include <iostream>
using std::cout;


Snake::Snake(sf::Vector2f position)
{
    sf::RectangleShape p(sf::Vector2f(part_size, part_size));
    p.setPosition(position);
    p.setFillColor(sf::Color::Red);
    body.push_back(p);


    sf::RectangleShape p2(sf::Vector2f(part_size, part_size));
    p2.setPosition(sf::Vector2f(position.x - 20, position.y - 20));
    p2.setFillColor(sf::Color::Yellow);
    body.push_back(p2);

}

void Snake::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
    for(auto& part : body)
    {
        target.draw(part);
    }
}

void Snake::updateDirection()
{

    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left) && dir != RIGHT)
    {
        dir = LEFT;
    }
    else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right) && dir != LEFT)
    {
        dir = RIGHT;
    }
    else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down) && dir != UP)
    {
        dir = DOWN;
    }
    else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up) && dir != DOWN)
    {
        dir = UP;
    }

}

void Snake::loopOver()
{

}

void Snake::move()
{
    sf::Vector2f prev_pos, curr_pos;
    updateDirection();

    for(list<sf::RectangleShape>::iterator it = body.begin(); it != body.end(); ++it)
    {

        sf::RectangleShape& curr_elem = (*it);
    
        curr_pos = curr_elem.getPosition();

        if(it == body.begin())
        {
            switch (dir)
            {
            case LEFT: 
                curr_elem.move(-20, 0);
                break;
            case RIGHT:
                curr_elem.move(20, 0);
                break;
            case DOWN:
                curr_elem.move(0, 20);
                break;
            case UP:
                curr_elem.move(0, -20);
                break;
            } 
        }
        else
        {
            curr_elem.setPosition(prev_pos);
        }

        prev_pos = curr_pos;
        
    }
}
