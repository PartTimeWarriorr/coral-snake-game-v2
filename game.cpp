#include "game.hpp"

Difficulty Game::difficulty = EASY;

void Game::run()
{
    // TODO: Randomize initial snake and food placement (and difficulty)
    Game::runDiffSelectionMenu();

    sf::RenderWindow window(sf::VideoMode(800, 800), "Coral Snake Game V-2", sf::Style::Close);
    window.setFramerateLimit(15u); // Set difficulty
    sf::RectangleShape bg(sf::Vector2f(800.f, 800.f));
    bg.setFillColor(sf::Color::Green);
    Snake snek(sf::Vector2f(400, 400));
    FoodGenerator apple(sf::Vector2f(780, 780), snek);

    while(window.isOpen())
    {

        sf::Event event;
        while(window.pollEvent(event))
        {
            if(event.type == sf::Event::Closed || snek.snakeBump()) // TODO
            {
                // if(snek.getLength() > SaveFile::getHS())
                // {
                //    SaveFile::updateSaveFile(snek.getLength());
                // }
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

void Game::runDiffSelectionMenu()
{

    sf::RenderWindow difficulty_selector(sf::VideoMode(250, 200), "Choose difficulty: ", sf::Style::Close);
    difficulty_selector.setFramerateLimit(10u);
    sf::RectangleShape b(sf::Vector2f(250, 200));
    b.setFillColor(sf::Color::Blue);
    sf::Font font;
    if(!font.loadFromFile("assets/PokemonGb-RAeo.ttf"))
    {
        cout << "Font not loaded\n";
        return;
    }

    sf::Text text;
    text.setFont(font);
    text.setString("Easy\nNormal\nHard");
    text.setCharacterSize(24);
    text.setFillColor(sf::Color::Black);
    text.setPosition(sf::Vector2f(50, 50));

    sf::CircleShape arrow(12, 3);
    arrow.setFillColor(sf::Color::Black);
    arrow.setPosition(45, 100);  // y: 50 - 75 - 100
    arrow.setRotation(90);

    while(difficulty_selector.isOpen())
    {
        sf::Event event;
        while(difficulty_selector.pollEvent(event))
        {
            if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::K) || event.type == sf::Event::Closed)
            {
                difficulty_selector.close();
            }

        }

        moveArrow(arrow);
        difficulty_selector.clear();
        difficulty_selector.draw(b);
        difficulty_selector.draw(arrow);
        difficulty_selector.draw(text);
        difficulty_selector.display();
    }
}

void Game::moveArrow(sf::CircleShape& arrow)
{
    sf::Vector2f curr_pos; 

    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
    {
        arrow.move(0, 25);

        curr_pos = arrow.getPosition();

        if(curr_pos.y > 100)
        {
            arrow.setPosition(curr_pos.x, 50);
        }
        cout << curr_pos.x << ' ' << curr_pos.y << '\n';
    }
    else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
    {
        arrow.move(0, -25);

        curr_pos = arrow.getPosition();

        if(curr_pos.y < 50)
        {
            arrow.setPosition(curr_pos.x, 100);
        }
        cout << curr_pos.x << ' ' << curr_pos.y << '\n';
    }

    // positions: 50:Easy, 75:Normal, 100:Hard
}

void Game::setDifficulty(Difficulty new_diff) 
{
    difficulty = new_diff;
}

Difficulty Game::getDifficulty()
{
    return Game::difficulty;
}