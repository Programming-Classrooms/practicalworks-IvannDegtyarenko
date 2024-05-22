#ifndef FUNCTIONS_HPP
#define FUNCTIONS_HPP

#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <stdexcept>
#include <typeinfo>


void checkFile(std::ifstream&);
void readWords(std::ifstream&, std::map<std::string, size_t>&);
void printInformation(const std::map<std::string, size_t>&);
#endif //FUNCTIONS_HPP
