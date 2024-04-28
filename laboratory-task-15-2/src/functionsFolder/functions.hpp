#ifndef FUNCTIONS_HPP
#define FUNCTIONS_HPP
#include <fstream>
#include <string>
#include <algorithm>
#include <stdexcept>
#include <iostream>
#include <vector>


void checkFile(std::ifstream& file);
void fillVector(std::ifstream& file, std::vector<std::string>& vector);
void printVector(const std::vector<std::string>& vector);
bool compStrings(const std::string& lhs, const std::string& rhs);
void printWordsWithStartSymbol(const std::vector<std::string>& vector, char symbol);
void deleteWordsWithStartSymbol(std::vector<std::string>& vector, char symbol);

#endif //FUNCTIONS_HPP