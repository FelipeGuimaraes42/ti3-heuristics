#include "include/InputFile.hpp"

InputFile::InputFile(string fileName)
{
    this->fileName = fileName;
}

InputFile::~InputFile() {}

void InputFile::printVector(const vector<pair<int, int>> graph)
{
    for (int i = 0; i < graph.size(); i++)
    {
        cout << graph.at(i).first << " " << graph.at(i).second << endl;
    }
}

vector<pair<int, int>> InputFile::getFileContent(string &name, string &weightType)
{
    vector<pair<int, int>> points;

    ifstream file;
    file.open(this->fileName);
    string word;
    int x, y;

    while (file >> word)
    {
        if (word == "NODE_COORD_SECTION")
            while (file >> word && word != "EOF")
            {
                string point;
                file >> point;
                x = stoi(point);
                file >> point;
                y = stoi(point);
                points.push_back({x, y});
            }
        if (word == "NAME:")
            file >> name;
        if (word == "EDGE_WEIGHT_TYPE:")
            file >> weightType;
    }
    return points;
}