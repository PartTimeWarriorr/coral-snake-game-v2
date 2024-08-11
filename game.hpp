#pragma once

#include <iostream>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include "food.hpp"
#include "savefile.hpp"

enum Difficulty 
{
    EASY,
    NORMAL,
    HARD
};

class Game
{
    private:

    static Difficulty difficulty;
    static void runDiffSelectionMenu();
    static void moveArrow(sf::CircleShape& arrow);

    public:

    static void run();
    static void setDifficulty(Difficulty new_diff);
    static Difficulty getDifficulty();
};
