/*
* Вариант 2
* В целочисленной квадратной матрице найти:
* - в первой строке первый нулевой элемент и столбец с этим элементом
* поменять местами с первым столбцом матрицы
* - найти максимальный элемент верхнего правого треугольника полученной
* матрицы.
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


void checkMatrix(const size_t columns, const size_t rows)
{
	if (columns != rows) {
		throw std::exception("Error in building square matrix!");
	}
}


void memory(int32_t**& mtrx, const size_t columns, const size_t rows)
{
	mtrx = new int* [rows];
	for (size_t i = 0; i < rows; ++i) {
		mtrx[i] = new int[columns];
	}
}


void deleteMatrix(int32_t**& mtrx, const size_t rows)
{
	for (size_t i = 0; i < rows; ++i) {
		delete[]mtrx[i];
	}
	delete[]mtrx;
}


void randomInput(int32_t**& mtrx, const size_t columns, const size_t rows)
{
	srand(time(NULL));
	std::cout << "Enter the boundaries for finding random numbers: ";
	int64_t min = 0;
	std::cin >> min;
	int64_t max = 0;
	std::cin >> max;
	if (!checkStream()) {
		throw std::exception("Error in getting number!");
	}
	if (max == min) {
		throw std::exception("These numbers can't be used as boundaries!");
	}
	if (max < min) {
		std::swap(max, min);
	}
	for (size_t i = 0; i < rows; ++i) {
		for (size_t j = 0; j < columns; ++j) {
			mtrx[i][j] = rand() % (max - min + 1) + min;
		}
	}
}


void keyboardInput(int32_t**& mtrx, const size_t columns, const size_t rows)
{
	for (size_t i = 0; i < rows; ++i) {
		std::cout << '\n';
		for (size_t j = 0; j < columns; ++j) {
			std::cin >> mtrx[i][j];
		}
	}
}


void inputChoice(int32_t**& mtrx, const size_t columns, const size_t rows)
{
	std::cout << "Choose the type of input: 1) Automatically  2) Manually: ";
	int64_t inputType = getNumber();
	if (inputType < 1 || inputType>2) {
		throw std::exception("Wrong value!");
	}
	switch (inputType) {
	case 1: {
		randomInput(mtrx, columns, rows);
		break;
	}
	case 2: {
		std::cout << "Enter your own numbers: ";
		keyboardInput(mtrx, columns, rows);
		break;
	}
	}
}


void matrixOutput(int32_t** mtrx, const size_t columns, const size_t rows)
{
	for (size_t i = 0; i < rows; ++i) {
		std::cout << '\n';
		for (size_t j = 0; j < columns; ++j) {
			std::cout << std::setw(5) << mtrx[i][j];
		}
	}
}


void swapColumns(int32_t**& mtrx, const size_t columns, const size_t rows)
{
	size_t nullColumn = -1;
	for (size_t i = 0; i < columns; ++i) {
		if (mtrx[0][i] == 0) {
			nullColumn = i;
			break;
		}
	}
	if (nullColumn == -1) {
		throw std::exception("Can't end the task. Can't find the column with zero element\n");
		
	}
	if (nullColumn == 0) {
		std::cout << "Due to the position of first null element no need in changing matrix\n";
	}
	else {
		for (size_t i = 0; i < rows; ++i) {
			std::swap(mtrx[i][0], mtrx[i][nullColumn]);
		}
	}
}


void findMaxElem(int32_t** mtrx, const size_t columns, const size_t rows, int64_t& maxElement)
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
		const size_t rows = getNumber();
		std::cout << "Enter the number of columns for square matrix: ";
		const size_t columns = getNumber();
		checkMatrix(columns, rows);
		int32_t** matrix = nullptr;
		memory(matrix, columns, rows);
		inputChoice(matrix, columns, rows);
		matrixOutput(matrix, columns, rows);
		std::cout << '\n';
		system("pause");
		system("cls");
		swapColumns(matrix, columns, rows);
		matrixOutput(matrix, columns, rows);
		int64_t maxElement = matrix[0][0];
		findMaxElem(matrix, columns, rows, maxElement);
		std::cout << "\nMax element in the up right triangle: " << maxElement;
		deleteMatrix(matrix, rows);
	}
	catch (std::exception& error) {
		std::cout << error.what();
		return -1;
	}
	return 0;
}

