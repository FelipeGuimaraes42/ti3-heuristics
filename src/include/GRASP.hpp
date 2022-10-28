#include <algorithm>
#include <cmath>
#include <map>
#include <set>
#include <string>
#include <vector>
#include "TSPSolution.hpp"

using namespace std;

class GRASP
{
private:
    string weightType;
    vector<pair<int, int>> points;
    double getDistance(const pair<int, int> xiYi, const pair<int, int> xjYj);
    double getCycleSize(vector<pair<int, int>> points);

public:
    GRASP(string weightType, vector<pair<int, int>> points);
    GRASP();
    ~GRASP();
    TSPSolution grasp(TSPSolution previousSolution);
};
