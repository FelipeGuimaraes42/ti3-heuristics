#include <iostream>
#include <string>
#include <vector>
#include "include/InputFile.hpp"
#include "include/VND.hpp"

using namespace std;

int main(int argc, char **argv)
{
    string name, weightType;
    string fileName(argv[1]);

    InputFile inputFile(fileName);
    vector<pair<int, int>> graph = inputFile.getFileContent(name, weightType);

    VND vnd(graph, weightType);
    double cicleSize = vnd.tsp();

    cout << name << " " << weightType << " " << cicleSize << endl;

    return 0;
}