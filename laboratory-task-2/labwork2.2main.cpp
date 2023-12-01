#include <iostream>
#include <exception>


/*
* Написать программу, которая на заданном отрезке [a,b] натурального ряда чисел находит все числа Армстронга
*/


bool checkStream()
{
	if (std::cin.fail()) {
		std::cin.clear();
		std::cin.ignore(32767, '\n');
		return false;
	}
	return true;
}


int getNumber()
{
	int64_t number = 0;
	std::cin >> number;
	if (!checkStream()) {
		throw std::exception("Error in getting number!");
	}
	else {
		if (number <= 0) {
			throw std::exception("Error in getting number!");
		}
	}
	return number;
}


void armstrongNumbers(int64_t number, size_t& counter)
{
	int64_t temp = number;
	int64_t temp2 = number;
	size_t power = 0;
	int64_t numberForCheck = 0;
	bool rule = true;
	while (temp != 0) {
		temp /= 10;
		++power;
	}
	int64_t lastDigit;
	while (temp2 != 0) {
		lastDigit = temp2 % 10;
		temp2 /= 10;
		numberForCheck += pow(lastDigit, power);
	}
	if (number == numberForCheck) {
		++counter;
		rule = true;
	}
	else {
		rule = false;
	}
	if (rule) {
		std::cout << number << " ";
	}
}


int main()
{
	try {
		std::cout << "Input boarders for finding armstrong numbers (down here)\n";
		std::cout << "Enter left boarder: ";
		int64_t leftBoarder = getNumber();
		std::cout << "Enter right boarder: ";
		int64_t rightBoarder = getNumber();
		size_t rule = 0;
		if (leftBoarder > rightBoarder) {
			std::swap(leftBoarder, rightBoarder);
		}
		for (leftBoarder; leftBoarder <= rightBoarder; ++leftBoarder) {
			armstrongNumbers(leftBoarder, rule);
		}
		if (rule == 0) {
			throw std::exception("Can't build new number due to the absence of numbers which are not multiples of the minimum digit");
		}
	}
	catch (std::exception& error) {
		std::cout << error.what();
		return -1;
	}
	return 0;
}

