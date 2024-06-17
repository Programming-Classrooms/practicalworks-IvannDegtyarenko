#ifndef FUNCTIONS_HPP
#define FUNCTIONS_HPP

#include <iostream>
#include <iomanip>
#include <vector>
#include <stdexcept>
#include <typeinfo>
#include <algorithm>
#include <numeric>


bool checkStream();
int getRandomNumber(const int64_t&, const int64_t&);
int getPositiveNumber();
void getBoundaries(int64_t&, int64_t&);
void fillMtrx(std::vector<std::vector<int>>&, const int64_t&, const int64_t&);
void printMtrx(const std::vector<std::vector<int>>&);
void eraseRowColWithMaxElem(std::vector<std::vector<int>>&);
void sortMtrx(std::vector<std::vector<int>>&);
#endif //FUNCTIONS_HPP