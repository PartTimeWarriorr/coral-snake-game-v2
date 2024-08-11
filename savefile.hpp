#pragma once
#include <fstream>
#include <iostream>
#include <string>
#include <unordered_map>
#include <sstream>
#include <algorithm>

using std::istringstream;
using std::ifstream;
using std::ofstream;
using std::fstream;
using std::cout;
using std::cerr;
using std::string;
using std::to_string;
using std::stoi;
using std::getline;
using std::unordered_map;

class SaveFile
{

    private:

    static int high_score;
    static unordered_map<string, string> info;

    static bool isNum(string value);
    static bool isEmpty(fstream& input);
    static bool isHSLine(string line);
    static void updateSaveFile(fstream& input, int high_score);

    public:
    static void loadMapFromFile();
    static void printMap();

    static void updateSaveFile(int high_score);

    static int getHS();

};