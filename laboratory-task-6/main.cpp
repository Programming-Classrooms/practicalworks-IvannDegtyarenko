/*
	Разработать шаблон функции для сортировки одномерного массива 
	с помощью алгоритма “прямого выбора”.
	Разработать для конкретных динамических массивов типа int, double, char*.
	Для получения входных данных иметь три варианта:
	- непосредственный ввод и запись в текстовый файл;
	- генерирование с помощью датчика случайных чисел и запись в текстовый файл;
	- ввод из текстового файла, а вывод - в консоль.
*/


#include <iostream>
#include <fstream>
#include <cstring>
#include <cctype>
#include <exception>
#include <string>


void checkFile(std::ifstream& file)
{
	if (!file.good())
	{
		throw std::exception("File does not exist.\n");
	}
	if (!file)
	{
		throw std::exception("File is not opened.\n");
	}
	if (file.peek() == EOF)
	{
		throw std::exception("File is empty.\n");
	}
}

bool checkStream()
{
	if (std::cin.fail()) {
		std::cin.clear();
		std::cin.ignore(32767, '\n');
		return false;
	}
	return true;
}

int64_t getArraySize()
{
	std::cout << "Enter the size of an array: ";
	int64_t arraySize = 0;
	std::cin >> arraySize;
	while (!checkStream()) {
		std::cout << "Enter a number instead of the letter: ";
		std::cin >> arraySize;
	}
	while (arraySize <= 0) {
		std::cout << "Wrong input value! Enter right: ";
		std::cin >> arraySize;
		if (!checkStream()) {
			continue;
		}
	}
	return arraySize;
}

template <typename T>
void fillArrayManually(T* arr, const size_t& arraySize)
{
	std::cout << "Enter your numbers to fill array: ";
	for (size_t i = 0; i < arraySize; ++i) {
		std::cin >> arr[i];
		while (!checkStream()) {
			std::cout << "Enter a number instead of the letter: ";
			std::cin >> arr[i];
		}
	}
}

template <>
void fillArrayManually<char>(char* arr, const size_t& arraySize)
{
	std::cout << "Enter your char symbols to fill array: ";
	for (size_t i = 0; i < arraySize; ++i) {
		std::cin >> arr[i];
	}
}

template <>
void fillArrayManually<double>(double* arr, const size_t& arraySize)
{
	std::cout << "Enter your double numbers to fill array: ";
	double numberDouble = 0.0;
	for (size_t i = 0; i < arraySize; ++i) {
		std::cin >> numberDouble;
		while (!checkStream()) {
			std::cout << "Enter a double number instead of the letter: ";
			std::cin >> numberDouble;
		}
		arr[i] = numberDouble;
	}
}

template <typename T>
void selectionSort(T* arr, const size_t& arraySize)
{
	for (size_t i = 0; i < arraySize; ++i) {
		size_t indexOfLowest = i;
		for (size_t j = i + 1; j < arraySize; ++j) {
			if (arr[j] < arr[indexOfLowest]) {
				indexOfLowest = j;
			}
		}
		std::swap(arr[i], arr[indexOfLowest]);
	}
}

template <typename T>
void printArrayToFile(T* arr, const size_t& arraySize)
{
	std::ofstream fileOut("outputFile.txt", std::ios::app);
	if (!fileOut)
	{
		throw std::exception("File is not opened.\n");
	}
	for (size_t i = 0; i < arraySize; ++i) {
		fileOut << arr[i] << " ";
	}
	fileOut << '\n';
	fileOut.close();
}

template <typename T>
void fillArrWithRandNumbers(T* arr, const size_t& arraySize)
{
	srand(time(NULL));
	std::cout << "Enter left boarder then enter right boarder: ";
	int64_t leftBoarder = 0;
	std::cin >> leftBoarder;
	while (!checkStream()) {
		std::cout << "Enter a number instead of the letter: ";
		std::cin >> leftBoarder;
	}
	int64_t rightBoarder = 0;
	std::cin >> rightBoarder;
	while (!checkStream()) {
		std::cout << "Enter a number instead of the letter: ";
		std::cin >> rightBoarder;
	}
	if (leftBoarder > rightBoarder) {
		std::swap(leftBoarder, rightBoarder);
	}
	for (size_t i = 0; i < arraySize; ++i) {
		arr[i] = rand() % (rightBoarder - leftBoarder + 1) + leftBoarder;
	}
}

template <>
void fillArrWithRandNumbers<double>(double* arr, const size_t& arraySize)
{
	srand(time(NULL));
	std::cout << "Enter left boarder then enter right boarder: ";
	double leftBoarder = 0.0;
	std::cin >> leftBoarder;
	while (!checkStream()) {
		std::cout << "Enter a number instead of the letter: ";
		std::cin >> leftBoarder;
	}
	double rightBoarder = 0.0;
	std::cin >> rightBoarder;
	while (!checkStream()) {
		std::cout << "Enter a number instead of the letter: ";
		std::cin >> rightBoarder;
	}
	if (leftBoarder > rightBoarder) {
		std::swap(leftBoarder, rightBoarder);
	}
	for (size_t i = 0; i < arraySize; ++i) {
		arr[i] = static_cast<double>(rand()) / RAND_MAX * (rightBoarder - leftBoarder) + leftBoarder;
	}
}

template <>
void fillArrWithRandNumbers<char>(char* arr, const size_t& arraySize)
{
	srand(time(NULL));
	std::cout << "Enter left boarder then enter right boarder from ASCII table: ";
	int64_t leftBoarder = 0;
	std::cin >> leftBoarder;
	while (!checkStream()) {
		std::cout << "Enter a number instead of the letter: ";
		std::cin >> leftBoarder;
	}
	while (leftBoarder < 0 || leftBoarder > 255) {
		std::cout << "Entered number is out of the range of the ASCII table. Enter right number: ";
		std::cin >> leftBoarder;
		if (!checkStream()) {
			continue;
		}
	}
	int64_t rightBoarder = 0;
	std::cin >> rightBoarder;
	while (!checkStream()) {
		std::cout << "Enter a number instead of the letter: ";
		std::cin >> rightBoarder;
	}
	while (rightBoarder < 0 || rightBoarder > 255) {
		std::cout << "Entered number is out of the range of the ASCII table. Enter right number: ";
		std::cin >> rightBoarder;
		if (!checkStream()) {
			continue;
		}
	}
	if (leftBoarder > rightBoarder) {
		std::swap(leftBoarder, rightBoarder);
	}
	for (size_t i = 0; i < arraySize; ++i) {
		arr[i] = static_cast<char>(rand() % (rightBoarder - leftBoarder + 1) + leftBoarder);
	}
}

template <typename T>
void readArrayFromFile(T* arr, size_t& arraySize)
{
	std::ifstream fileIn("int32_t.txt");
	checkFile(fileIn);
	std::string word = "";
	size_t counter = 0;
	while (fileIn >> word && counter < arraySize) {
		if (isdigit(word[0])) {
			int32_t transition = std::stoi(word);
			arr[counter] = transition;
			++counter;
		}
	}
	fileIn.close();
	arraySize = counter;
}

template <>
void readArrayFromFile<char>(char* arr, size_t& arraySize)
{
	std::ifstream fileIn("char.txt");
	checkFile(fileIn);
	char word = ' ';
	size_t counter = 0;
	while (fileIn >> word && counter < arraySize) {
		arr[counter] = word;
		++counter;
	}
	fileIn.close();
	arraySize = counter;
}

bool isOnlyDigits(std::string word)
{
	size_t length = word.length();
	for (size_t i = 0; i < length; ++i) {
		if (word[i] == '.') {
			continue;
		}
		if (!isdigit(word[i])) {
			return false;
		}
	}
	return true;
}

template <>
void readArrayFromFile<double>(double* arr, size_t& arraySize)
{
	std::ifstream fileIn("double.txt");
	checkFile(fileIn);
	std::string word = "";
	size_t counter = 0;
	while (fileIn >> word && counter < arraySize) {
		if (isOnlyDigits(word)) {
			arr[counter] = std::stof(word);
			++counter;
		}
	}
	fileIn.close();
	arraySize = counter;
}

template <typename T>
void printArray(T* arr, const size_t& arraySize)
{
	for (size_t i = 0; i < arraySize; ++i) {
		std::cout << arr[i] << " ";
	}
}

int main()
{
	try {
		std::cout << "You are given a choice of operating modes\n";
		std::cout << "\t1) Direct input and writing to a text file\n";
		std::cout << "\t2) Generating random numbers and writing to a text file\n";
		std::cout << "\t3) Input from a text file, output to the console\n";
		std::cout << "Choose an operating mode to work: ";
		int64_t userChoice = 0;
		std::cin >> userChoice;
		while (!checkStream()) {
			std::cout << "Enter a number instead of the letter: ";
			std::cin >> userChoice;
		}
		while (userChoice < 1 || userChoice > 3) {
			std::cout << "Wrong input value! Enter right: ";
			std::cin >> userChoice;
			if (!checkStream()) {
				continue;
			}
		}
		switch (userChoice) {
			case 1: {
				std::ofstream fileOut("outputFile.txt", std::ios::trunc);
				if (!fileOut)
				{
					throw std::exception("File is not opened.\n");
				}
				fileOut.close();
				std::cout << "Array: Integer. ";
				size_t integerArraySize = getArraySize();
				int32_t* integerArray = new int32_t[integerArraySize];
				fillArrayManually(integerArray, integerArraySize);
				selectionSort(integerArray, integerArraySize);
				printArrayToFile(integerArray, integerArraySize);
				delete[] integerArray;
				std::cout << "Array: Double. ";
				size_t doubleArraySize = getArraySize();
				double* doubleArray = new double[doubleArraySize];
				fillArrayManually(doubleArray, doubleArraySize);
				selectionSort(doubleArray, doubleArraySize);
				printArrayToFile(doubleArray, doubleArraySize);
				delete[] doubleArray;
				std::cout << "Array: Char. ";
				size_t charArraySize = getArraySize();
				char* charArray = new char[charArraySize];
				fillArrayManually(charArray, charArraySize);
				selectionSort(charArray, charArraySize);
				printArrayToFile(charArray, charArraySize);
				delete[] charArray;
				break;
			}
			case 2: {
				std::ofstream fileOut("outputFile.txt", std::ios::trunc);
				if (!fileOut)
				{
					throw std::exception("File is not opened.\n");
				}
				fileOut.close();
				std::cout << "Array: Integer. ";
				size_t integerArraySize = getArraySize();
				int32_t* integerArray = new int32_t[integerArraySize];
				fillArrWithRandNumbers(integerArray, integerArraySize);
				selectionSort(integerArray, integerArraySize);
				printArrayToFile(integerArray, integerArraySize);
				delete[] integerArray;
				std::cout << "Array: Double. ";
				size_t doubleArraySize = getArraySize();
				double* doubleArray = new double[doubleArraySize];
				fillArrWithRandNumbers(doubleArray, doubleArraySize);
				selectionSort(doubleArray, doubleArraySize);
				printArrayToFile(doubleArray, doubleArraySize);
				delete[] doubleArray;
				std::cout << "Array: Char. ";
				size_t charArraySize = getArraySize();
				char* charArray = new char[charArraySize];
				fillArrWithRandNumbers(charArray, charArraySize);
				selectionSort(charArray, charArraySize);
				printArrayToFile(charArray, charArraySize);
				delete[] charArray;
				break;
			}
			case 3: {
				std::cout << "Array: Integer. ";
				size_t integerArraySize = getArraySize();
				int32_t* integerArray = new int32_t[integerArraySize];
				readArrayFromFile(integerArray, integerArraySize);
				selectionSort(integerArray, integerArraySize);
				std::cout << "Sorted integer array: ";
				printArray(integerArray, integerArraySize);
				delete[] integerArray;
				std::cout << "\nArray: Double. ";
				size_t doubleArraySize = getArraySize();
				double* doubleArray = new double[doubleArraySize];
				readArrayFromFile(doubleArray, doubleArraySize);
				selectionSort(doubleArray, doubleArraySize);
				std::cout << "Sorted double array: ";
				printArray(doubleArray, doubleArraySize);
				delete[] doubleArray;
				std::cout << "\nArray: Char. ";
				size_t charArraySize = getArraySize();
				char* charArray = new char[charArraySize];
				readArrayFromFile(charArray, charArraySize);
				selectionSort(charArray, charArraySize);
				std::cout << "Sorted char array: ";
				printArray(charArray, charArraySize);
				delete[] charArray;
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

