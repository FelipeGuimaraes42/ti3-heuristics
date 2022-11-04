#include <iostream>
#include <string>
#include <vector>
#include "include/InputFile.hpp"
#include "include/VND.hpp"
#include "include/GRASP.hpp"

using namespace std;

int main(int argc, char **argv)
{
    string name, weightType;
    string fileName(argv[1]);

    InputFile inputFile(fileName);
    vector<pair<int, int>> points = inputFile.getFileContent(name, weightType);

    VND vnd(points, weightType);
    TSPSolution constructiveSolution = vnd.getConstructiveSolution();
    TSPSolution solution = vnd.vnd(constructiveSolution);

    GRASP grasp(weightType, points);

    for (int i = 0; i < 10; i++)
    {
        TSPSolution graspSolution = grasp.grasp(solution);
        TSPSolution newSolution = vnd.vnd(graspSolution);

        if (newSolution.getValue() < solution.getValue())
        {
            solution = newSolution;
        }
    }

    cout << name << " " << weightType << " " << solution.getValue() << endl;
    for (auto i : solution.getPoints())
    {
        cout << i.first << "," << i.second << "   ";
    }
    cout << endl;

    return 0;
}