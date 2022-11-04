#include "include/GRASP.hpp"

GRASP::GRASP(string weightType, vector<pair<int, int>> points)
{
	this->weightType = weightType;
	this->points = points;
}

GRASP::GRASP() {}

GRASP::~GRASP() {}

double GRASP::getDistance(const pair<int, int> xiYi, const pair<int, int> xjYj)
{
	double xd = xiYi.first - xjYj.first;
	double yd = xiYi.second - xjYj.second;

	if (this->weightType == "EUC_2D")
	{
		return floor(sqrt(xd * xd + yd * yd));
	}

	double rij = sqrt((xd * xd + yd * yd) / 10.0);
	double tij = floor(rij);

	if (tij < rij)
	{
		return tij + 1.0;
	}
	return tij;
}

double GRASP::getCycleSize(vector<pair<int, int>> points)
{
	int size = points.size();
	double cycleSize = 0;

	for (int i = 0; i < points.size() - 1; i++)
	{
		cycleSize += this->getDistance(points.at(i), points.at(i + 1));
	}
	cycleSize += this->getDistance(points.at(size - 1), points.at(0));

	return cycleSize;
}

TSPSolution GRASP::grasp(TSPSolution previousSolution)
{
	double alpha = 0.6;

	int randomInt = rand() % this->points.size();

	set<int> candidates;
	for (int i = 0; i < previousSolution.getPoints().size(); i++)
	{
		candidates.insert(i);
	}
	candidates.erase(randomInt);

	vector<pair<int, int>> graspPoints;
	graspPoints.push_back(points.at(randomInt));

	while (candidates.size() > 0)
	{
		vector<int> restrictedPoints;
		map<int, double> greedy;

		int k = graspPoints.size();

		for (int v : candidates)
		{
			greedy[v] = this->getDistance(this->points.at(k - 1), this->points.at(v));
		}

		double cMin = INF, cMax = -INF;
		for (auto mapElement : greedy)
		{
			cMin = min(cMin, mapElement.second);
			cMax = max(cMax, mapElement.second);
		}

		for (auto mapElement : greedy)
		{
			if (candidates.find(mapElement.first) != candidates.end())
			{
				if (mapElement.second <= (cMin + (alpha * (cMax - cMin))))
				{
					restrictedPoints.push_back(mapElement.first);
				}
			}
		}

		int choice = rand() % restrictedPoints.size();
		graspPoints.push_back(points.at(restrictedPoints.at(choice)));
		candidates.erase(restrictedPoints.at(choice));
	}

	TSPSolution newSolution;
	newSolution.setPoints(graspPoints);

	double graspValue = this->getCycleSize(graspPoints);
	newSolution.setValue(graspValue);

	return newSolution;
}