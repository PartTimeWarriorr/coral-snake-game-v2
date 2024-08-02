#include "food.hpp"
#include <iostream>
using std::cout;
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
    srand(int(snake.getHeadPosition().y * 2));
    int new_x = rand() % 40 * 20;

    srand(int(snake.getHeadPosition().x * 2));
    int new_y = rand() % 40 * 20;

    food.setPosition(new_x, new_y);

    // TODO: change parameters and loop when food isn't spawning in a valid place
    if(snake.getHeadPosition() == food.getPosition())
    {
        cout << "oops\n";
        updatePosition(snake);
    }

}

FoodGenerator::FoodGenerator(sf::Vector2f position)
{
    food = sf::RectangleShape(sf::Vector2f(20.f, 20.f));

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