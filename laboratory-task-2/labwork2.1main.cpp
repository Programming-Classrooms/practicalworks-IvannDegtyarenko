#include <iostream>
#include <exception>


/*
*Написать программу, которая для заданного натурального числа удаляет из записи числа все цифры, кратные минимальной цифре 
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


int findLowestNumber(int32_t userNumber)
{
	size_t lastDigit;
	size_t lowestNumber = 9;
	while (userNumber != 0) {
		lastDigit = userNumber % 10;
		userNumber /= 10;
		if (lastDigit < lowestNumber && lastDigit != 0) {
			lowestNumber = lastDigit;
		}
	}
	return lowestNumber;
}


int makeNewNumber(int32_t userNumber, size_t lowestNumber)
{
	size_t power = 1;
	size_t lastDigit;
	size_t newNumber = 0;
	while (userNumber != 0) {
		lastDigit = userNumber % 10;
		if (lastDigit % lowestNumber != 0) {
			newNumber += lastDigit * power;
			power *= 10;
		}
		userNumber /= 10;
	}
	if (newNumber == 0) {
		throw std::exception("Can't build new number due to the absence of numbers which are not multiples of the minimum digit");
	}
	return newNumber;
}


int main()
{
	try {
		std::cout << "Enter your number: ";
		int32_t userNumber = getNumber();
		size_t lowestNumber = findLowestNumber(userNumber);
		size_t newNumber = makeNewNumber(userNumber, lowestNumber);
		system("cls");
		std::cout << "The number you entered: " << userNumber;
		std::cout << "\nNew number: " << newNumber;
	}
	catch (std::exception& error) {
		std::cout << error.what();
		return -1;
	}
	return 0;
}

