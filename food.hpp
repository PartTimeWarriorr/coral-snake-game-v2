#pragma once
#include <SFML/Graphics.hpp>
#include "snake.hpp"
#include <stdlib.h>

class FoodGenerator : public sf::Drawable 
{
    private:
    sf::RectangleShape food;

    void updatePosition(Snake& snake);
    virtual void draw(sf::RenderTarget &target, sf::RenderStates states) const override;
    bool snakeCollide(Snake& snake);

    public:
    void checkIfEaten(Snake& snake); 
    FoodGenerator(sf::Vector2f position, Snake& snake);
    sf::Vector2f getFoodPosition();
};