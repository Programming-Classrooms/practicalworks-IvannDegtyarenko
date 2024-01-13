/*
	В массиве, состоящем из п целых элементов, вычислить:
	- сумму элементов массива с нечетными номерами;
	- произведение элементов массива, расположенных между первым и последним
	положительными элементами.
	Сжать массив, удалив из него все элементы, модуль которых больше числа N.
	Освободившиеся в конце массива элементы заполнить нулями.
*/


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

int getRandomNumber(const int64_t& leftBound, const int64_t& rightBound)
{
	return (rand() % (rightBound - leftBound + 1) + leftBound);
}

int getArraySize()
{
	int64_t arraySize = 0;
	std::cout << "Enter your size: ";
	std::cin >> arraySize;
	while (!checkStream()) {
		std::cout << "Enter a number instead of the letter: ";
		std::cin >> arraySize;
	}

	while (arraySize <= 0 || arraySize >= 255) {
		std::cout << "Wrong value! Enter right: ";
		std::cin >> arraySize;
		if (!checkStream()) {
			continue;
		}
	}
	return arraySize;
}

void fillArrayRand(int32_t* arr, const size_t& arraySize)
{
	srand(time(NULL));
	int64_t min = 0;
	int64_t max = 0;
	std::cout << "\nEnter the boundaries for finding random numbers: ";

	while (1) {
		std::cin >> min;
		if (checkStream()) {
			break;
		}
	}
	while (1) {
		std::cin >> max;
		if (checkStream()) {
			break;
		}
	}

	if (max < min) {
		int64_t temp = min;
		min = max;
		max = temp;
	}
	for (size_t i = 0; i < arraySize; ++i) {
		arr[i] = getRandomNumber(min, max);
	}
}

uint32_t getInputType()
{
	std::cout << "Choose the type of input: 1-automatically, 2-manually: ";
	uint32_t inputType = 0;
	std::cin >> inputType;

	while (!checkStream()) {
		std::cout << "Enter a number instead of the letter: ";
		std::cin >> inputType;
	}

	while (inputType <= 0 || inputType > 2) {
		std::cout << "Wrong value! Enter right: ";
		std::cin >> inputType;
		if (!checkStream()) {
			continue;
		}
	}

	return inputType;
}

void switchInputType(int32_t* arr, const size_t& arraySize, const uint32_t& inputType)
{
	switch (inputType) {
	case 1: {
		fillArrayRand(arr, arraySize);
		break;
	}
	case 2: {
		std::cout << "\nInput your own numbers: ";
		for (size_t i = 0; i < arraySize; ++i) {
			std::cin >> arr[i];
			while (!checkStream()) {
				std::cout << "Enter a number instead of the letter: ";
				std::cin >> arr[i];
			}
		}
		break;
	}
	}
}

void fillArrChoice(int32_t* arr, const size_t& arraySize)
{
	uint32_t inputType = getInputType();
	switchInputType(arr, arraySize, inputType);
}

void printArray(int32_t* arr, const size_t& arraySize)
{
	for (size_t i = 0; i < arraySize; ++i) {
		std::cout << arr[i] << " ";
	}
}

int sumOfTheElements(int32_t* arr, const size_t& arraySize)
{
	int64_t sum = 0;
	for (size_t i = 1; i < arraySize; i += 2) {
		sum += arr[i];
	}
	return sum;
}

int firstPosDigInd(int32_t* arr, const size_t& arraySize)
{
	int32_t firstPositiveDigit = -1;
	for (size_t i = 0; i < arraySize; ++i) {
		if (arr[i] > 0) {
			firstPositiveDigit = i;
			break;
		}
	}
	if (firstPositiveDigit == -1) {
		return -1;
	}
	else {
		return firstPositiveDigit;
	}
}

int lastPosDigInd(int32_t* arr, const size_t& arraySize)
{
	int32_t lastPositiveDigit = firstPosDigInd(arr, arraySize);
	for (size_t i = firstPosDigInd(arr, arraySize); i < arraySize; ++i) {
		if (arr[i] > 0 && i > lastPositiveDigit) {
			lastPositiveDigit = i;
		}
	}

	if (lastPositiveDigit == firstPosDigInd(arr, arraySize)) {
		return -1;
	}
	else {
		return lastPositiveDigit;
	}
}

int32_t elemMultiplication(int32_t* arr, int32_t firstPositiveDigitIndx, int32_t lastPositiveDigitIndx)
{
	int32_t multiplication = 1;
	if (firstPositiveDigitIndx == -1 || lastPositiveDigitIndx == -1) {
		throw std::exception("\nCan't provide multiplication");
	}
	for (size_t i = firstPositiveDigitIndx; i <= lastPositiveDigitIndx; ++i) {
		multiplication *= arr[i];
	}
	return multiplication;
}

void changeArray(int32_t* arr, const size_t& arraySize)
{
	std::cout << "\nEnter your number for changing rule: ";
	int32_t userNumber = 0;
	std::cin >> userNumber;
	while (!checkStream()) {
		std::cout << "Enter a number instead of the letter: ";
		std::cin >> userNumber;
	}

	while (userNumber < 0) {
		std::cout << "Wrong value! Enter right: ";
		std::cin >> userNumber;
		if (!checkStream()) {
			continue;
		}
	}

	for (size_t i = 0; i < arraySize; ++i) {
		if (abs(arr[i]) > userNumber) {
			arr[i] = 0;
			int32_t j = i;
			for (j; j < (arraySize - 1); ++j) {
				std::swap(arr[j], arr[j + 1]);
			}
			i = -1;
			j = -1;
		}
		else {
			continue;
		}
	}
}

int main()
{
	const size_t maxSize = 255;
	int32_t arr[maxSize];
	try {
		uint64_t arraySize = getArraySize();
		fillArrChoice(arr, arraySize);
		std::cout << "Your array: ";
		printArray(arr, arraySize);
		std::cout << "\nThe sum of the elements of the array with odd numbers = " << sumOfTheElements(arr, arraySize);

		try {
			int32_t firstPositiveDigitIndx = firstPosDigInd(arr, arraySize);
			int32_t lastPositiveDigitIndx = lastPosDigInd(arr, arraySize);
			std::cout << "\nMultiplication of elements between the first and last positive number = ";
			std::cout << elemMultiplication(arr, firstPositiveDigitIndx, lastPositiveDigitIndx);
		}
		catch (std::exception& error) {
			std::cout << error.what();
		}

		std::cout << "\nChanging in progress . . ." << '\n';

		std::cout << "Your array before changing: ";
		printArray(arr, arraySize);
		changeArray(arr, arraySize);
		std::cout << "\nYour array after changing: ";
		printArray(arr, arraySize);
	}
	catch (std::exception& error) {
		std::cerr << error.what();
		return -1;
	}
	return 0;
}

