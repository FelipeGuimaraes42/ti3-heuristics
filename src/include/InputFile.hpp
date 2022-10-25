#include <fstream>
#include <string>
#include <iostream>
#include <vector>

using namespace std;

class InputFile
{
private:
    string fileName;
    void readLines(vector<string> &lines, int &numLines, int &numColumns);
    void printVector(const vector<pair<int, int>> graph);

public:
    InputFile(string fileName);
    ~InputFile();
    vector<pair<int, int>> getFileContent(string &name, string &weightType);
};