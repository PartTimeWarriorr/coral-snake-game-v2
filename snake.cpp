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

    // test purposes
    sf::RectangleShape p2(sf::Vector2f(part_size, part_size));
    p2.setPosition(sf::Vector2f(position.x - 20, position.y - 20));
    p2.setFillColor(sf::Color::Yellow);
    body.push_back(p2);

    // eyes
    sf::RectangleShape e_1(sf::Vector2f(eye_size, eye_size));
    sf::RectangleShape e_2(sf::Vector2f(eye_size, eye_size));

    e_1.setFillColor(sf::Color::Black);
    e_2.setFillColor(sf::Color::Black);

    e_1.setPosition(position.x + 2, position.y + 15);
    e_2.setPosition(position.x + (part_size - 2 - eye_size), position.y + 15);

    eye1 = e_1;
    eye2 = e_2;

}

void Snake::positionEyes(sf::Vector2f position)
{

    switch (dir)
    {
    case LEFT:
        eye1.setPosition(position.x + eye_size, position.y + 2);
        eye2.setPosition(position.x + eye_size, position.y + 15);
        break;
    case RIGHT:
        eye1.setPosition(position.x + (part_size - 2 - eye_size), position.y + 2);
        eye2.setPosition(position.x + (part_size - 2 - eye_size), position.y + 15);
        break;
    case DOWN:
        eye1.setPosition(position.x + 2, position.y + 15);
        eye2.setPosition(position.x + (part_size - 2 - eye_size), position.y + 15);
        break;
    case UP:
        eye1.setPosition(position.x + 3, position.y + 2);
        eye2.setPosition(position.x + 15, position.y + 2);
        break;
    }

}

void Snake::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
    for(auto& part : body)
    {
        target.draw(part);
    }

    target.draw(eye1);
    target.draw(eye2);

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

void Snake::loopOver(sf::RectangleShape& part)
{
    sf::Vector2f position = part.getPosition();

    // Loop over horizontally
    if(position.x >= 800)
    {
        part.move(-800, 0);
    }
    else if(position.x < 0)
    {
        part.move(800, 0);
    }

    // Loop over vertically
    if(position.y >= 800)
    {
        part.move(0, -800);
    }
    else if(position.y < 0)
    {
        part.move(0, 800);
    }
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

            positionEyes(curr_elem.getPosition());
        }
        else
        {
            curr_elem.setPosition(prev_pos);
        }

        loopOver(curr_elem);

        prev_pos = curr_pos;
        
    }
}

void Snake::addPart()
{
    sf::RectangleShape new_p(sf::Vector2f(part_size, part_size));
    new_p.setPosition(body.back().getPosition());
    new_p.setFillColor(sf::Color::Black);

    body.push_back(new_p);
}

sf::Vector2f Snake::getHeadPosition()
{
    return body.front().getPosition();
}