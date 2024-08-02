#include "food.hpp"
#include <cmath>

void FoodGenerator::checkIfEaten(Snake& snake)
{
    if(snake.getHeadPosition() == food.getPosition())
    {
        snake.addPart();
        updatePosition(snake);
    }
}

void FoodGenerator::updatePosition(Snake& snake)
{   

    int random_index = 2;
    
    while(snakeCollide(snake))
    {
        srand(ceil(time(NULL)));
        int new_x = rand() % 39 * 20;

        srand(ceil(snake.getHeadPosition().x * random_index));
        int new_y = rand() % 39 * 20;

        food.setPosition(new_x, new_y);

        random_index += 2;
    }

}

FoodGenerator::FoodGenerator(sf::Vector2f position, Snake& snake)
{
    float size = snake.getPartSize();

    food = sf::RectangleShape(sf::Vector2f(size, size));

    food.setFillColor(sf::Color(0xF10083FF));

    food.setPosition(position);
}

void FoodGenerator::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    target.draw(food);
}


sf::Vector2f FoodGenerator::getFoodPosition()
{
    return food.getPosition();
}


bool FoodGenerator::snakeCollide(Snake& snake)
{
    list<sf::RectangleShape> b = snake.getSnakePosition();

    for(auto& p : b)
    {
        if(getFoodPosition() == p.getPosition())
        {
            return true;
        }
    }

    return false;
}