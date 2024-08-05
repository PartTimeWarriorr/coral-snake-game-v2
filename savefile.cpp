#include "savefile.hpp"

int SaveFile::high_score = 0;

void SaveFile::readSaveFile()
{
    fstream input("game_info.txt", fstream::in | fstream::out );
     
    if(!input.is_open())
    {
        std::cerr << "File not found\n";
        return;
    }

    if(isEmpty(input))
    {
        updateSaveFile(input, 0);
        return;
    }

    string buffer;
    int curr_high = 0;

    while(!input.eof())
    {
        getline(input, buffer);

        if(isHSLine(buffer))
        {
            curr_high = stoi(buffer.substr(buffer.find_first_of("0123456789"), buffer.size()));
            high_score = (curr_high > high_score) ? curr_high : high_score; // update high score if new one is better
        }
        else
        {
            updateSaveFile(input, high_score); // TODO ?
        }
    }

    input.close();

}

bool SaveFile::isEmpty(fstream& input)
{
    return input.peek() == fstream::traits_type::eof();
}

bool SaveFile::isHSLine(string line)
{
    string hs = "high_score = ";

    return line.substr(0, hs.size()) == hs;
}

void SaveFile::updateSaveFile(fstream& input, int high_score)
{
    input.close();
    input.open("game_info.txt", fstream::in | fstream::trunc);

    string info = "high_score = " + to_string(high_score);

    input << info; 
}

void SaveFile::updateSaveFile(int high_score)
{
    fstream output("game_info.txt", fstream::out | fstream::trunc );

    if(!output.is_open())
    {
        cerr << "Error opening save file\n";
        return;
    }

    string info = "high_score = " + to_string(high_score);

    output << info; 
    output.close();
}

int SaveFile::getHS()
{
    return high_score;
}
