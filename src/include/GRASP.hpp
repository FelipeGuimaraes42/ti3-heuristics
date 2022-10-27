#include <string>
#include <vector>
#include "TSPSolution.hpp"

using namespace std;

class GRASP
{
private:
    string weightType;
    int numberOfPoints;

public:
    GRASP(string weightType, int numberOfPoints);
    GRASP();
    ~GRASP();
    TSPSolution grasp(TSPSolution previousSolution);
};
