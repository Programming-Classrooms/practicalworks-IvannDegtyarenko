#include "functions.hpp"

bool checkStream()
{
    if (std::cin.fail()) {
        std::cin.clear();
        std::cin.ignore(32767, '\n');
        return false;
    }
    return true;
}

int getRandomNumber(const int64_t &lb, const int64_t &rb)
{
    return (rand() % (rb - lb + 1) + lb);
}

int getPositiveNumber()
{
    int64_t number = 0;
	std::cin >> number;
	while (!checkStream()) {
		std::cout << "Enter a number instead of the letter: ";
		std::cin >> number;
	}
	while (number <= 0) {
		std::cout << "Wrong value! Enter right: ";
		std::cin >> number;
		if (!checkStream()) {
			continue;
		}
	}
	return number;
}

void getBoundaries(int64_t& lb, int64_t& rb)
{
    std::cout << "Enter the boundaries for finding random numbers: ";
	
	std::cin >> lb;
	while (!checkStream()) {
		std::cout << "Enter a number instead of the letter: ";
		std::cin >> lb;
	}

	std::cin >> rb;
	while (!checkStream()) {
		std::cout << "Enter a number instead of the letter: ";
		std::cin >> rb;
	}

    if (rb < lb) {
	    std::swap(rb, lb);
	}
}

void fillMtrx(std::vector<std::vector<int>>& mtrx, const int64_t& lb, const int64_t& rb)
{
    for (auto& i : mtrx) {
        for (auto& j : i) {
            j = getRandomNumber(lb, rb);
        }
    }
}

void printMtrx(const std::vector<std::vector<int>>& mtrx)
{
    for (auto i : mtrx) {
        std::cout << '\n';
        for (auto j : i) {
            std::cout << std::setw(5) << j;
        }
    }
    std::cout << '\n';
}

void eraseRowColWithMaxElem(std::vector<std::vector<int>>& mtrx)
{
    int32_t maxElement = mtrx[0][0];
    size_t rowToDelete = 0, columnToDelete = 0;
    size_t rowCounter = 0, columnCounter = 0;
    
    for (auto i : mtrx) {
        for (auto j : i) {
            if (j > maxElement) {
                maxElement = j;
                rowToDelete = rowCounter;
                columnToDelete = columnCounter;
            }
            ++columnCounter;
        }
        ++rowCounter;
        columnCounter = 0;
    }

    mtrx.erase(mtrx.begin() + rowToDelete);
    for (auto& i : mtrx) {
        i.erase(i.begin() + columnToDelete);
    }
}

void sortMtrx(std::vector<std::vector<int>>& mtrx)
{
    for (size_t i = 0; i < mtrx.size(); ++i) {
        for (size_t j = i; j < mtrx.size(); ++j) {
            if (std::accumulate(mtrx[i].begin(), mtrx[i].end(), 0) > std::accumulate(mtrx[j].begin(), mtrx[j].end(), 0)) {
                std::swap(mtrx[i], mtrx[j]);
            }
        }
    }
}