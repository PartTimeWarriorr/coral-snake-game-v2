#include "game.hpp"

void Game::run()
{

    sf::RenderWindow window(sf::VideoMode(800, 800), "Snake v-2", sf::Style::Close);

    sf::RectangleShape bg(sf::Vector2f(800.f, 800.f));
    bg.setFillColor(sf::Color::Blue);

    Snake snek(sf::Vector2f(400, 400), window);


    while(window.isOpen())
    {
        sf::Event event;
        while(window.pollEvent(event))
        {
            if(event.type == sf::Event::Closed)
            {
                window.close();
            }
        }

        window.clear();
        window.draw(bg);
        window.draw(snek.tempDraw);
        window.display();
    }
}

