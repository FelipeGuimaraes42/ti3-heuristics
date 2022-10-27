#include "include/GRASP.hpp"

GRASP::GRASP(string weightType, int numberOfPoints)
{
	this->weightType = weightType;
	this->numberOfPoints = numberOfPoints;
}

GRASP::GRASP() {}

GRASP::~GRASP() {}

TSPSolution GRASP::grasp(TSPSolution previousSolution)
{
    double alpha = 1.0;
	int startVertex = rand() % this->numberOfPoints;
	TSPSolution newSolution;

	// TODO implement GRASP

	return newSolution;
}
