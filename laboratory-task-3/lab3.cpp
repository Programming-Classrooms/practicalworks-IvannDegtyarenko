#include <iostream>
/*
В массиве, состоящем из п целых элементов, вычислить:
- сумму элементов массива с нечетными номерами;
- произведение элементов массива, расположенных между первым и последним 
положительными элементами.
Сжать массив, удалив из него все элементы, модуль которых больше числа N.
Освободившиеся в конце массива элементы заполнить нулями.
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
int getArraySize()
{
	int64_t arraySize = 0;
	std::cout << "Enter your size: ";
	std::cin >> arraySize;
	if (!checkStream()) {
		throw "Error!";
	}
	else {
		if (arraySize <= 0 || arraySize >= 100) {
			throw "Error!";
		}
		else {
			return arraySize;
		}
	}
}
void getRandomNumber(int32_t* arr, const size_t arraySize)
{
	srand(time(NULL));
	int64_t min = 0, max = 0;
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
		arr[i] = rand() % (max - min + 1) + min;
	}
}
void getInputType(int32_t* arr, const size_t arraySize)
{
	std::cout << "Choose the type of input: 1-automatically, 2-manually: ";
	uint64_t inputType = 0;
	std::cin >> inputType;
	if (!checkStream()) {
		throw "Error!";
	}
	else {
		if (inputType <= 0 || inputType >= 3) {
			throw "Error!";
		}
	}
	switch (inputType) {
	case 1: {
		getRandomNumber(arr, arraySize);
		break;
	}
	case 2: {
		std::cout << "\nInput your own numbers: ";
		for (size_t i = 0; i < arraySize; ++i) {
			std::cin >> arr[i];
		}
		break;
	}
	}
}
void arrayOutput(int32_t* arr, const size_t arraySize)
{
	for (size_t i = 0; i < arraySize; ++i) {
		std::cout << arr[i] << " ";
	}
}
void sumOfTheElements(int32_t* arr, const size_t arraySize)
{
	int64_t sum = 0;
	for (size_t i = 1; i < arraySize;) {
		sum += arr[i];
		i += 2;
	}
	std::cout << "\nThe sum of the elements of the array with odd numbers = " << sum;
}
int firstPositive(int32_t* arr, const size_t arraySize)
{
	int32_t firstPositiveDigit = -1;
	for (size_t i = 0; i < arraySize; ++i) {
		if (arr[i] > 0) {
			firstPositiveDigit = i;
			break;
		}
	}
	if (firstPositiveDigit == -1) {
		throw "The necessary positive values is missing...";
	}
	else {
		return firstPositiveDigit;
	}
}
int lastPositive(int32_t* arr, const size_t arraySize)
{
	int32_t lastPositiveDigit = firstPositive(arr, arraySize);
	for (size_t i = firstPositive(arr,arraySize); i < arraySize; ++i) {
		if (arr[i] > 0 && i > lastPositiveDigit) {
			lastPositiveDigit = i;
		}
	}
	if (lastPositiveDigit == firstPositive(arr, arraySize)) {
		throw "The necessary second positive value is missing...";
	}
	else {
		return lastPositiveDigit;
	}
}
void multiplicationOfElementsBetweenTheFirstAndLastPositiveNumber(int32_t* arr, const size_t arraySize)
{
	int32_t firstPositiveDigit = firstPositive(arr, arraySize)
    int32_t lastPositiveDigit = lastPositive(arr, arraySize);
	int64_t multiplication = 1;
	for (size_t i = firstPositiveDigit; i <= lastPositiveDigit; ++i) {
		multiplication *= arr[i];
	}
	std::cout << "\nMultiplication of elements between the first and last positive number = " << multiplication;
}
void arrayMinimizing(int32_t* arr, const size_t arraySize)
{
	std::cout << "\nEnter your number for minimizing rule: ";
	int32_t userNumber;
	std::cin >> userNumber;
	if (!checkStream()) {
		throw "Error!";
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
		getInputType(arr, arraySize);
		std::cout << "Your array: ";
		arrayOutput(arr, arraySize);
		sumOfTheElements(arr, arraySize);
		try {
			multiplicationOfElementsBetweenTheFirstAndLastPositiveNumber(arr, arraySize);
		}
		catch (const char* e) {
			std::cout << e;
			return -1;
		}
		std::cout << "\nMinimizing in progress . . ." << '\n';
		system("pause");
		system("cls");
		std::cout << "Your array before minimizing: ";
		arrayOutput(arr, arraySize);
		arrayMinimizing(arr, arraySize);
		std::cout << "\nYour array after minimizing: ";
		arrayOutput(arr, arraySize);
	}
	catch (const char* e) {
		std::cout << e;
		return -1;
	}
	return 0;
}