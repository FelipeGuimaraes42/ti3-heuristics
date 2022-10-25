#include "include/TSPSolution.hpp"

TSPSolution::TSPSolution()
{
    this->solutionValue = 0;
    this->solutionPoints;
}

TSPSolution::TSPSolution(double solutionValue, vector<pair<int, int>> solutionPoints)
{
    this->solutionValue = solutionValue;
    this->solutionPoints = solutionPoints;
}

TSPSolution::~TSPSolution() {}

void TSPSolution::setValue(double value)
{
    this->solutionValue = value;
}
void TSPSolution::setPoints(vector<pair<int, int>> points)
{
    this->solutionPoints = points;
}

double TSPSolution::getValue()
{
    return this->solutionValue;
}

vector<pair<int, int>> TSPSolution::getPoints()
{
    return this->solutionPoints;
}