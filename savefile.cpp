#include "savefile.hpp"

int SaveFile::high_score = 0;
unordered_map<string, string> SaveFile::info = {{"high_score", ""}};

// TODO: refactor this whole mess to represent local data better (hashmap? assume save file is always valid? if not valid.. oh well)

void SaveFile::loadMapFromFile()
{
    fstream in("game_info.txt", fstream::in);

    string buffer;

    while(getline(in, buffer))
    {
        istringstream ss(buffer);
        string key;

        if(getline(ss, key, '='))
        {
            string val;
            if(getline(ss, val) && info.count(key))
            {
                info[key] = val;
            }
        }
    }

    in.close();
}

bool SaveFile::isNum(string value)
{
    return all_of(value.begin(), value.end(), ::isdigit);
}

void SaveFile::printMap()
{
    for(auto& elem : SaveFile::info)
    {
        cout << elem.first << ' ' << elem.second << '\n';
    }
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
    input.open("game_info.txt", fstream::trunc); // change to trunc to entirely replace file contents 

    string info = "high_score = " + to_string(high_score);

    input << info; 

    input.close();
    input.open("game_info.txt", fstream::in | fstream::out); // change back to io to continue stream operations
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
