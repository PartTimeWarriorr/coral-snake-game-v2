#include "game.hpp"

void Game::run()
{

    sf::RenderWindow window(sf::VideoMode(800, 800), "Snake v-2", sf::Style::Close);

    window.setFramerateLimit(15u);

    sf::RectangleShape bg(sf::Vector2f(800.f, 800.f));
    bg.setFillColor(sf::Color::Green);

    Snake snek(sf::Vector2f(400, 400));


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

        snek.move();
        window.clear();
        window.draw(bg);
        window.draw(snek);
        window.display();
    }
}

