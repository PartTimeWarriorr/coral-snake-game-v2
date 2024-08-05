#pragma once
#include <fstream>
#include <iostream>
#include <string>

using std::ifstream;
using std::ofstream;
using std::fstream;
using std::cout;
using std::cerr;
using std::string;
using std::to_string;
using std::stoi;
using std::getline;

class SaveFile
{

    private:

    static int high_score;

    static bool isEmpty(fstream& input);
    static bool isHSLine(string line);
    static void updateSaveFile(fstream& input, int high_score);

    public:

    static void readSaveFile();
    static void updateSaveFile(int high_score);

    static int getHS();

};