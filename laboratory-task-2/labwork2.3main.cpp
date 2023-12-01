#include <iostream>
#include <exception>


/*
* Написать программу, которая находит в последовательности, 
* состоящей из цифр подряд записанных натуральных чисел, цифру с заданным номером
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


int findDigit(int64_t positionNumber)
{
	int64_t number = 1;
	int64_t digitsInNumber = 1;
	int64_t totalNumber = 1;
	while (positionNumber > totalNumber) {
		++number;
		digitsInNumber = 0;
		int64_t temp = number;
		while (temp > 0) {
			++digitsInNumber;
			temp /= 10;
		}
		totalNumber += digitsInNumber;
	}
	if (positionNumber == totalNumber) {
		return number % 10;
	}
	int64_t difference = totalNumber - positionNumber;
	number /= pow(10, difference);
	return number % 10;
}


int main()
{
	try {
		std::cout << "Enter position number: ";
		int64_t positionNumber = getNumber();
		int64_t digit = findDigit(positionNumber);
		std::cout << "Digit on position " << positionNumber << " is " << digit;
	}
	catch (std::exception& error) {
		std::cout << error.what();
		return -1;
	}
	return 0;
}

