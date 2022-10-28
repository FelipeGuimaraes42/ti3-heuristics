#ifndef TSP_SOLUTION_HPP
#define TSP_SOLUTION_HPP

#include <vector>

#define INF 0x3f3f3f3f

using namespace std;

class TSPSolution
{
private:
    double solutionValue;
    vector<pair<int, int>> solutionPoints;

public:
    TSPSolution();
    TSPSolution(double solutionValue, vector<pair<int, int>> solutionPoints);
    ~TSPSolution();

    void setValue(double value);
    void setPoints(vector<pair<int, int>> points);

    double getValue();
    vector<pair<int, int>> getPoints();
};

#endif