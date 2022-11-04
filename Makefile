compile:
	cd src && g++ -o main main.cpp InputFile.cpp TSPSolution.cpp VND.cpp GRASP.cpp

run:
	cd src && ./main ../testCases/kroA100.tsp

all:
	cd src && g++ -o main main.cpp InputFile.cpp TSPSolution.cpp VND.cpp GRASP.cpp && ./main ../testCases/berlin52.tsp