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

void memoryAllocation(int32_t**& mtrx, const size_t& columns, const size_t& rows)
{
	mtrx = new int32_t* [rows];
	for (size_t i = 0; i < rows; ++i) {
		mtrx[i] = new int32_t[columns];
	}
}

void memoryCleaning(int32_t**& mtrx, const size_t& rows)
{
	for (size_t i = 0; i < rows; ++i) {
		delete[] mtrx[i];
	}
	delete[] mtrx;
}

void fillingWithRandomNumbers
(
	int32_t**& mtrx,
	const size_t& columns,
	const size_t& rows,
	const int64_t& rightBoarder,
	const int64_t& leftBoarder
)
{
	srand(time(NULL));
	for (size_t i = 0; i < rows; ++i) {
		for (size_t j = 0; j < columns; ++j) {
			mtrx[i][j] = rand() % (rightBoarder - leftBoarder + 1) + leftBoarder;
		}
	}
}

void fillingManually(int32_t**& mtrx, const size_t& columns, const size_t& rows)
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

void inputChoice(int32_t**& mtrx, const size_t& columns, const size_t& rows)
{
	std::cout << "Choose the type of input: 1) Automatically  2) Manually: ";
	int64_t inputType = getPositiveNumber();
	while (inputType < 1 || inputType > 2) {
		std::cout << "Wrong choice! Enter right number: ";
		inputType = getPositiveNumber();
	}
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
		fillingWithRandomNumbers(mtrx, columns, rows, rightBoarder, leftBoarder);
		break;
	}
	case 2: {
		std::cout << "Enter your own numbers: ";
		fillingManually(mtrx, columns, rows);
		break;
	}
	}
}

void matrixPrint(int32_t** mtrx, const size_t& columns, const size_t& rows)
{
	int64_t width = 5;
	std::cout << "Do you want to change the input width (1-yes/2-no)? ";
	int64_t choice = getPositiveNumber();
	while (choice < 1 || choice > 2) {
		std::cout << "Wrong choice! Enter right number: ";
		choice = getPositiveNumber();
	}
	if (choice == 1) {
		std::cout << "Enter your input width: ";
		width = getPositiveNumber();
	}
	else {
		width = 5;
	}
	for (size_t i = 0; i < rows; ++i) {
		std::cout << '\n';
		for (size_t j = 0; j < columns; ++j) {
			std::cout << std::setw(width) << mtrx[i][j];
		}
	}
}

void findMaxElem(int32_t** mtrx, const size_t& columns, const size_t& rows, int64_t& maxElement)
{
	for (size_t i = 0; i < rows; ++i) {
		for (size_t j = i; j < columns; ++j) {
			if (mtrx[i][j] > maxElement) {
				maxElement = mtrx[i][j];
			}
		}
	}
}

int main()
{
	try {
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
		memoryAllocation(matrix, columns, rows);
		inputChoice(matrix, columns, rows);
		matrixPrint(matrix, columns, rows);
		std::cout << '\n';
		system("pause");
		system("cls");
		size_t nullColumn = -1;
		for (size_t i = 0; i < columns; ++i) {
			if (matrix[0][i] == 0) {
				nullColumn = i;
				break;
			}
		}
		if (nullColumn == -1) {
			memoryCleaning(matrix, rows);
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
		matrixPrint(matrix, columns, rows);
		int64_t maxElement = matrix[0][0];
		findMaxElem(matrix, columns, rows, maxElement);
		std::cout << "\nMax element in the up right triangle: " << maxElement;
		memoryCleaning(matrix, rows);
	}
	catch (std::exception& error) {
		std::cout << error.what();
		return -1;

	}
	return 0;
}

