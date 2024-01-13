/*
	Вариант 2
	В целочисленной квадратной матрице найти:
	- в первой строке первый нулевой элемент и столбец с этим элементом
	поменять местами с первым столбцом матрицы
	- найти максимальный элемент верхнего правого треугольника полученной
	матрицы.
*/


#include <iostream>
#include <exception>
#include <iomanip>


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

void mtrxMemoryAllocation(int32_t**& mtrx, const size_t& rows, const size_t& columns)
{
	mtrx = new int* [rows];
	for (size_t i = 0; i < rows; ++i) {
		mtrx[i] = new int[columns];
	}
}

void mtrxMemoryCleaning(int32_t**& mtrx, const size_t& rows)
{
	for (size_t i = 0; i < rows; ++i) {
		delete[] mtrx[i];
	}
	delete[] mtrx;
}

void fillMtrxWithRandomNumbers
(
	int32_t** mtrx,
	const size_t& rows,
	const size_t& columns,
	const int64_t& rightBoarder,
	const int64_t& leftBoarder
)
{
	for (size_t i = 0; i < rows; ++i) {
		for (size_t j = 0; j < columns; ++j) {
			mtrx[i][j] = getRandomNumber(leftBoarder, rightBoarder);
		}
	}
}

void fillMtrxManually(int32_t** mtrx, const size_t& rows, const size_t& columns)
{
	for (size_t i = 0; i < rows; ++i) {
		std::cout << '\n';
		for (size_t j = 0; j < columns; ++j) {
			std::cout << "Enter your number in matrix position (" << i << "," << j << "): ";
			std::cin >> mtrx[i][j];
			while (!checkStream()) {
				std::cout << "Enter a number instead of the letter: ";
				std::cin >> mtrx[i][j];
			}
		}
	}
}

uint32_t getInputType()
{
	std::cout << "Choose the type of input: 1) Automatically  2) Manually: ";
	uint32_t inputType = getPositiveNumber();
	while (inputType < 1 || inputType > 2) {
		std::cout << "Wrong choice! Enter right number: ";
		inputType = getPositiveNumber();
	}
	return inputType;
}

void switchInputType(int32_t** mtrx, const size_t& rows, const size_t& columns, const uint32_t& inputType)
{
	switch (inputType) {
	case 1: {
		std::cout << "Enter the boundaries for finding random numbers: ";
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
		if (rightBoarder < leftBoarder) {
			std::swap(rightBoarder, leftBoarder);
		}
		fillMtrxWithRandomNumbers(mtrx, columns, rows, rightBoarder, leftBoarder);
		break;
	}
	case 2: {
		std::cout << "Enter your own numbers: ";
		fillMtrxManually(mtrx, columns, rows);
		break;
	}
	}
}

void fillMtrxChoice(int32_t** mtrx, const size_t& rows, const size_t& columns)
{
	uint32_t inputType = getInputType();
	switchInputType(mtrx, rows, columns, inputType);
}

void matrixPrint(int32_t** mtrx, const size_t& rows, const size_t& columns, const int32_t& width)
{
	for (size_t i = 0; i < rows; ++i) {
		std::cout << '\n';
		for (size_t j = 0; j < columns; ++j) {
			std::cout << std::setw(width) << mtrx[i][j];
		}
	}
}

int32_t getMaxElem(int32_t** mtrx, const size_t& rows, const size_t& columns)
{
	int32_t maxElement = mtrx[0][0];
	for (size_t i = 0; i < rows; ++i) {
		for (size_t j = i; j < columns; ++j) {
			if (mtrx[i][j] > maxElement) {
				maxElement = mtrx[i][j];
			}
		}
	}
	return maxElement;
}

int main()
{
	srand(time(NULL));
	try {
		int32_t width = 5;
		std::cout << "Enter the number of rows for square matrix: ";
		size_t rows = getPositiveNumber();
		std::cout << "Enter the number of columns for square matrix: ";
		size_t columns = getPositiveNumber();

		while (columns != rows) {
			std::cout << "This numbers can't be used in building square matrix! Please enter right numbers below.\n";
			std::cout << "The number of columns: ";
			columns = getPositiveNumber();
			std::cout << "The number of rows: ";
			rows = getPositiveNumber();
		}

		int32_t** matrix = nullptr;
		mtrxMemoryAllocation(matrix, rows, columns);
		fillMtrxChoice(matrix, rows, columns);
		matrixPrint(matrix, rows, columns, width);
		std::cout << '\n';

		size_t nullColumn = -1;
		for (size_t i = 0; i < columns; ++i) {
			if (matrix[0][i] == 0) {
				nullColumn = i;
				break;
			}
		}

		if (nullColumn == -1) {
			mtrxMemoryCleaning(matrix, rows);
			throw std::exception("Can't end the task. Can't find the column with zero element\n");

		}
		if (nullColumn == 0) {
			std::cout << "Due to the position of first null element no need in changing matrix\n";
		}
		else {
			for (size_t i = 0; i < rows; ++i) {
				std::swap(matrix[i][0], matrix[i][nullColumn]);
			}
		}

		matrixPrint(matrix, rows, columns, width);
		std::cout << "\nMax element in the up right triangle: " << getMaxElem(matrix, rows, columns);
		mtrxMemoryCleaning(matrix, rows);
	}
	catch (std::exception& error) {
		std::cerr << error.what();
		return -1;

	}
	return 0;
}

