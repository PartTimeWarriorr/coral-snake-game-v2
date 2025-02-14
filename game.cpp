#include "game.hpp"

void Game::run()
{
    // TODO: Randomize initial snake and food placement 

    sf::RenderWindow window(sf::VideoMode(800, 800), "Coral Snake Game V-2", sf::Style::Close);

    window.setFramerateLimit(15u);

    sf::RectangleShape bg(sf::Vector2f(800.f, 800.f));
    bg.setFillColor(sf::Color::Green);

    Snake snek(sf::Vector2f(400, 400));
    FoodGenerator apple(sf::Vector2f(780, 780), snek);

    SaveFile::readSaveFile();

    while(window.isOpen())
    {
        sf::Event event;
        while(window.pollEvent(event))
        {
            if(event.type == sf::Event::Closed || snek.snakeBump()) // TODO
            {
                if(snek.getLength() > SaveFile::getHS())
                {
                   SaveFile::updateSaveFile(snek.getLength());
                }
                window.close();
            }
        }

        snek.move();
        apple.checkIfEaten(snek);
        window.clear();
        window.draw(bg);
        window.draw(snek);
        window.draw(apple);
        window.display();
    }
}

