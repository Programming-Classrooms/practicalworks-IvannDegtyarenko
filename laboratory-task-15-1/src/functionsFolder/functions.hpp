#ifndef FUNCTIONS_HPP
#define FUNCTIONS_HPP
#include <iostream>
#include <stdexcept>
#include <vector>
#include <typeinfo>


void clearStream();

void fillVector(std::vector<int32_t>& vector);

void printVector(const std::vector<int32_t>& vector);

int32_t vElemSum(const std::vector<int32_t>& vector);

size_t vElemAmount(const std::vector<int32_t>& vector);

size_t elemAmountEQEntered(const std::vector<int32_t>& vector);

size_t elemAmountCondSatysfy(const std::vector<int32_t>& vector);

void vReplaceZeros(std::vector<int32_t>& vector);

void intervalBoarderInput(const std::vector<int32_t>& vector, int32_t& leftBoarder, int32_t& rightBoarder);

void addSumFromInterval(std::vector<int32_t>& vector);

bool isEven(int32_t number);

int getVMaxElement(const std::vector<int32_t>& vector);

int getVLowestElement(const std::vector<int32_t>& vector);

void vReplaceEven(std::vector<int32_t>& vector);

void deleteEQElem(std::vector<int32_t>& vector);
#endif //FUNCTIONS_HPP