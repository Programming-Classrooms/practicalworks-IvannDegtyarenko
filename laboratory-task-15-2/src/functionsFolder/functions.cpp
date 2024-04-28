#include "functions.hpp"

void checkFile(std::ifstream &file)
{
    if (!file.good()) {
        throw std::runtime_error("File does not exist!");
    }
    if (!file) {
        throw std::runtime_error("File is not opened!");
    }
    if (file.peek() == EOF) {
        throw std::runtime_error("File is empty!");
    }
}

void fillVector(std::ifstream &file, std::vector<std::string> &vector)
{
    std::string::size_type begIndex;
    std::string::size_type endIndex;
    std::string wordLine;

    while (std::getline(file, wordLine)) {
        begIndex = wordLine.find_first_not_of(" ");
        
        while (begIndex != std::string::npos) {
            endIndex = wordLine.find_first_of(" ", begIndex);
            
            if (endIndex == std::string::npos) {
                endIndex = wordLine.length();
            }
            
            std::string word = wordLine.substr(begIndex, endIndex - begIndex);
            vector.push_back(word);

            begIndex = wordLine.find_first_not_of(" ", endIndex);
        }
    }
}

void printVector(const std::vector<std::string> &vector)
{
    std::cout << "Your vector: ";
    for (std::string i : vector) {
        std::cout << i << " ";
    }
    std::cout << '\n';
}

bool compStrings(const std::string &lhs, const std::string &rhs)
{
    if (lhs.length() != rhs.length()) {
        return false;
    }
    for (size_t i = 0; i < lhs.length(); ++i) {
        if (std::tolower(lhs[i]) != std::tolower(rhs[i])) {
            return false;
        }
    }
    return true;
}

void printWordsWithStartSymbol(const std::vector<std::string> &vector, char symbol)
{
    bool vectorHasWords = false;
    for (std::string i : vector) {
        if(i[0] == symbol) {
            std::cout << i << " ";
            vectorHasWords = true;
        }
    }
    if (!vectorHasWords) {
        std::cout << "Vector does not contain words that start with entered symbol\n";
    }
    std::cout << '\n';
}

void deleteWordsWithStartSymbol(std::vector<std::string> &vector, char symbol)
{
    bool vectorHasWords = false;
    for (size_t i = 0; i < vector.size(); ++i) {
        if (vector[i][0] == symbol) {
            vector.erase(vector.begin() + i);
            vectorHasWords = true;
        }
    }
    if (!vectorHasWords) {
        std::cout << "Vector does not contain words that start with entered symbol. Nothing to delete\n";
    }
}
