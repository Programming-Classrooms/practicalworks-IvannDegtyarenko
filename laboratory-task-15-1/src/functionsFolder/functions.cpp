#include "functions.hpp"


void clearStream()
{
    std::cin.clear();
    std::cin.ignore(32767, '\n');
}

void fillVector(std::vector<int32_t>& vector)
{
    std::cout << "Enter your numbers to the vector.\n";
    std::cout << "Type any other digit to stop entering: ";
    int32_t number;
    while (std::cin >> number) {
        vector.push_back(number);
    }
    if (vector.empty()) {
        throw std::runtime_error("Vector is empty!");
    }
    else {
        std::cout << "Done! Vector is filled\n";
        clearStream();
    }
}

void printVector(const std::vector<int32_t>& vector) 
{
    std::cout << "Your vector: ";
    for (int i : vector) {
        std::cout << i << " ";
    }
    std::cout << '\n';
}

int32_t vElemSum(const std::vector<int32_t>& vector)
{
    int32_t elementsSum = 0;
    for (int32_t i : vector) {
        elementsSum += i;
    }
    return elementsSum;
}

size_t vElemAmount(const std::vector<int32_t>& vector)
{
    return vector.size();
}

size_t elemAmountEQEntered(const std::vector<int32_t>& vector)
{
    std::cout << "Enter an integer number to find amount of equals: ";
    int32_t number = 0;
    size_t counter = 0;
    std::cin >> number;
    for (int i : vector) {
        if (i == number) {
            ++counter;
        }
    }
    return counter;
}

size_t elemAmountCondSatysfy(const std::vector<int32_t>& vector) 
{
    std::cout << "Enter an integer number to find amount of elements that higher: ";
    int32_t number = 0;
    size_t counter = 0;
    std::cin >> number;
    for (int i : vector) {
        if (number < i) {
            ++counter;
        }
    }
    return counter;
}

void vReplaceZeros(std::vector<int32_t>& vector) 
{
    int32_t average = vElemSum(vector)/vElemAmount(vector);
    for (size_t i = 0; i < vector.size(); ++i) {
        if (vector[i] == 0) {
            vector[i] = average;
        }
    }
}

void intervalBoarderInput(const std::vector<int32_t>& vector, int32_t& leftBoarder, int32_t& rightBoarder)
{
    std::cout << "Enter left boarder of the interval: ";
    std::cin >> leftBoarder;
    while (leftBoarder < 0 || leftBoarder >= vector.size()) {
        std::cout << "Wrong input! Try again input: ";
        std::cin >> leftBoarder;
    }
    std::cout << "Enter right boarder of the interval: ";
    std::cin >> rightBoarder;
    while (rightBoarder < 0 || rightBoarder >= vector.size()) {
        std::cout << "Wrong input! Try again input: ";
        std::cin >> rightBoarder;
    }
    if (leftBoarder > rightBoarder) {
        std::swap(leftBoarder, rightBoarder);
    }
}

void addSumFromInterval(std::vector<int32_t>& vector)
{
    int32_t leftBoarder = 0, rightBoarder = 0;
    intervalBoarderInput(vector, leftBoarder, rightBoarder);
    int32_t intervalSum = 0;
    for (leftBoarder; leftBoarder <= rightBoarder; ++leftBoarder) {
        intervalSum += vector[leftBoarder];
    }
    for (size_t i = 0; i < vector.size(); ++i) {
        vector[i] += intervalSum;
    }
}

bool isEven(int32_t number)
{
    if (number % 2 == 0) {
        return true;
    }
    return false;
}

int getVMaxElement(const std::vector<int32_t>& vector)
{
    int32_t maxElement = vector[0];
    for (int32_t i : vector) {
        if (i > maxElement) {
            maxElement = i;
        }
    }
    return maxElement;
}

int getVLowestElement(const std::vector<int32_t>& vector)
{
    int32_t lowestElement = vector[0];
    for (int32_t i : vector) {
        if (i < lowestElement) {
            lowestElement = i;
        }
    }
    return lowestElement;
}

void vReplaceEven(std::vector<int32_t>& vector)
{
    int lowMaxDiff = getVMaxElement(vector) - getVLowestElement(vector);
    for (size_t i = 0; i < vector.size(); ++i) {
        if (isEven(vector[i])) {
            vector[i] = lowMaxDiff;
        }
    }
}

void deleteEQElem(std::vector<int32_t>& vector)
{
    for (size_t i = 0; i < vector.size(); ++i) {
        for (size_t j = i+1; j < vector.size(); ++j) {
            if (vector[i] == vector[j]) {
                vector.erase(vector.begin() + j);
            }
        }
    }
}