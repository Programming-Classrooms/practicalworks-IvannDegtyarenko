#include <iostream>
#include <exception>
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
		std::exception globalError("Error in getting number!");
		throw globalError;
	}
	else {
		if (number <= 0) {
			std::exception globalError("Error in getting number!");
			throw globalError;
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
	size_t newNumber=0;
	while (userNumber != 0) {
		lastDigit = userNumber % 10;
		if (lastDigit % lowestNumber != 0) {
			newNumber += lastDigit * power;
			power *= 10;
		}
		userNumber /= 10;
	}
	if (newNumber == 0) {
		throw "Can't build new number due to the absence of numbers which are not multiples of the minimum digit";
	}
	return newNumber;
}
void exerciseEighteen()
{
	std::cout << "Enter position number: ";
	int64_t positionNumber = getNumber();
	int64_t digit=findDigit(positionNumber);
	std::cout << "Digit on position " << positionNumber << " is " << digit;
}
void exerciseTwo()
{
	std::cout << "Enter your number: ";
	int32_t userNumber = getNumber();
	size_t lowestNumber = findLowestNumber(userNumber);
	size_t newNumber = makeNewNumber(userNumber, lowestNumber);
	system("cls");
	std::cout << "The number you entered: " << userNumber;
	std::cout << "\nNew number: " << newNumber;
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
void exerciseTwelve()
{
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
		std::exception errorArmstrong("No armstrong numbers between this boarders");
		throw errorArmstrong;
	}
}
int main()
{
	try {
		std::cout << "Choose the task (down below) 1)Number Two  2)Number Twelve  3)Number Eighteen\n";
		std::cout << "Enter the number: ";
		int64_t choice = getNumber();
		if (choice > 3) {
			std::exception errorChoice("Error in getting number!");
			throw errorChoice;
		}
		switch (choice) {
		case 1: {
			exerciseTwo();
			break;
		}
		case 2: {
			exerciseTwelve();
			break;
		}
		case 3: {
			exerciseEighteen();
			break;
		}
		}
	}
	catch (std::exception& error) {
		std::cout << error.what();
		return -1;
	}
	return 0;
}