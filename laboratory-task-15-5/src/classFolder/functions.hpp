#include "train.hpp"

#ifndef FUNCTIONS_HPP
#define FUNCTIONS_HPP


void checkFile(std::ifstream&);
void fillTrainVector(std::vector<Train>&, std::ifstream&);
void printTrainsInDepartureTimeRange(const std::vector<Train>&);
double getRightTime();
void printTrainsWSDestination(const std::vector<Train>&);
void printExpressTrainWSDest(const std::vector<Train>&);
void findFastestTrainWSDest(const std::vector<Train>&);
#endif //FUNCTIONS_HPP