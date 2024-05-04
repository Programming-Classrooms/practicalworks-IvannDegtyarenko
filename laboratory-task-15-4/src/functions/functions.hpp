#ifndef FUNCTIONS_HPP
#define FUNCTIONS_HPP

#include <iostream>
#include <string>
#include <fstream>
#include <stdexcept>
#include <typeinfo>
#include <vector>
#include <algorithm>
#include "../student/student.hpp"


void checkInputFile(std::ifstream&);
void checkOutputFile(std::ofstream&);
void readDataFromFile(std::vector<Student>&, std::ifstream&);
void writeDataToFile(const std::vector<Student>&, std::ofstream&);

#endif //FUNCTIONS_HPP