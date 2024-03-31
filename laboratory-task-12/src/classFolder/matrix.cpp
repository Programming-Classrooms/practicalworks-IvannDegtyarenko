#include "matrix.hpp"


bool checkStream()
{
	if (std::cin.fail()) {
		std::cin.clear();
		std::cin.ignore(32767, '\n');
		return false;
	}
	return true;
}

void Matrix::fillMatrix()
{
	
	for (size_t i = 0; i < rows; ++i) {
		for (size_t j = 0; j < columns; ++j) {
			mtrx[i][j] = rand() % 10 - 1;
		}
	}
}

Matrix::Matrix(int initR, int initC) : mtrx(new double*[initR]), rows(initR), columns(initC)
{
	if (initC <= 0) {
		throw std::invalid_argument("Invalid argument exception caught: Can't use 0 value or less as amount of Columns");
	}

	if (initR <= 0) {
		throw std::invalid_argument("Invalid argument exception caught: Can't use 0 value or less as amount of Rows");
	}

	for (size_t i = 0; i < initR; ++i) {
		mtrx[i] = new double[initC];
	}

	fillMatrix();
}

Matrix::Matrix(const Matrix& rhsInit) : mtrx(new double*[rhsInit.rows]), rows(rhsInit.rows), columns(rhsInit.columns)
{
	for (size_t i = 0; i < rhsInit.rows; ++i) {
		mtrx[i] = new double[rhsInit.columns];
	}
	fillMatrix();
}

Matrix::~Matrix()
{
	for (size_t i = 0; i < rows; ++i) {
		delete[] mtrx[i];
	}
	delete[] mtrx;
}

int Matrix::getRows() const
{
	return this->rows;
}

int Matrix::getColumns() const
{
	return this->columns;
}

void Matrix::getMatrix() const
{
	for (size_t i = 0; i < rows; ++i) {
		std::cout << '\n';
		for (size_t j = 0; j < columns; ++j) {
			std::cout << std::setw(7) << mtrx[i][j];
		}
	}
	std::cout << '\n';
}

double& Matrix::getMatrixElement(int indexR, int indexC) const
{
	if (indexR < 0 || indexR >= rows) {
		throw std::out_of_range("Out of range exception caught: Invalid index for Rows");
	}

	if (indexC < 0 || indexC >= columns) {
		throw std::out_of_range("Out of range exception caught: Invalid index for Columns");
	}

	return mtrx[indexR][indexC];
}

void Matrix::setRows(int initR)
{
	for (size_t i = 0; i < rows; ++i) {
		delete[] mtrx[i];
	}
	delete[] mtrx;
	this->rows = initR;
	mtrx = new double* [initR];
	for (size_t i = 0; i < initR; ++i) {
		mtrx[i] = new double[columns];
	}
	fillMatrix();
}

void Matrix::setColumns(int initC)
{
	for (size_t i = 0; i < rows; ++i) {
		delete[] mtrx[i];
	}
	delete[] mtrx;
	this->columns = initC;
	mtrx = new double* [rows];
	for (size_t i = 0; i < rows; ++i) {
		mtrx[i] = new double[initC];
	}
	fillMatrix();
}

Matrix& Matrix::operator=(const Matrix& rhs)
{
	if (this != &rhs) {
		for (size_t i = 0; i < rows; ++i) {
			delete[] mtrx[i];
		}
		delete[] mtrx;
		this->rows = rhs.rows;
		this->columns = rhs.columns;
		mtrx = new double* [rows];
		for (size_t i = 0; i < rows; ++i) {
			mtrx[i] = new double[columns];
		}
		for (size_t i = 0; i < rows; ++i) {
			for (size_t j = 0; j < columns; ++j) {
				mtrx[i][j] = rhs.mtrx[i][j];
			}
		}
	}
	return *this;
}

Matrix& Matrix::operator+=(const Matrix& rhs)
{
	if (rows != rhs.rows || columns != rhs.columns) {
		throw std::runtime_error("Runtime error exception caught: It is not possible to add matrices of different sizes");
	}

	for (size_t i = 0; i < rows; ++i) {
		for (size_t j = 0; j < columns; ++j) {
			mtrx[i][j] += rhs.mtrx[i][j];
		}
	}
	return *this;
}

Matrix& Matrix::operator-=(const Matrix& rhs)
{
	if (rows != rhs.rows || columns != rhs.columns) {
		throw std::runtime_error("Runtime error exception caught: It is not possible to substract matrices of different sizes");
	}

	for (size_t i = 0; i < rows; ++i) {
		for (size_t j = 0; j < columns; ++j) {
			mtrx[i][j] -= rhs.mtrx[i][j];
		}
	}
	return *this;
}

Matrix& Matrix::operator*=(const Matrix& rhs)
{
	if (columns != rhs.rows) {
		throw std::runtime_error("Runtime error exception caught: The matrix data cannot be multiplied");
	}

	Matrix multipliedMatrix(rows, rhs.columns);
	for (size_t i = 0; i < rows; ++i) {
		for (size_t j = 0; j < rhs.columns; ++j) {
			multipliedMatrix.mtrx[i][j] = 0;
			for (size_t k = 0; k < columns; ++k) {
				multipliedMatrix.mtrx[i][j] += (mtrx[i][k] * rhs.mtrx[k][j]);
			}
		}
	}
	*this = multipliedMatrix;
	return *this;
}

Matrix Matrix::operator*(const int& scalar)
{
	Matrix copy(*this);
	for (size_t i = 0; i < rows; ++i) {
		for (size_t j = 0; j < columns; ++j) {
			mtrx[i][j] *= scalar;
		}
	}
	return copy;
}

Matrix Matrix::operator/(const int& scalar)
{
	if (scalar == 0) {
		throw std::invalid_argument("Invalid argument exception caught: Can't use 0 value for division operation");
	}

	Matrix copy(*this);
	for (size_t i = 0; i < rows; ++i) {
		for (size_t j = 0; j < columns; ++j) {
			mtrx[i][j] /= scalar;
		}
	}
	return copy;
}

Matrix Matrix::operator+(const Matrix& rhs)
{
	return Matrix(*this += rhs);
}

Matrix Matrix::operator-(const Matrix& rhs)
{
	return Matrix(*this -= rhs);
}

Matrix Matrix::operator*(const Matrix& rhs)
{
	return Matrix(*this *= rhs);
}

bool Matrix::operator!=(const Matrix& rhs)
{
	if (rows != rhs.rows && columns != rhs.columns) {
		throw std::runtime_error("Runtime error exception caught: Can't check matrices of different size");
	}
	for (size_t i = 0; i < rows; ++i) {
		for (size_t j = 0; j < columns; ++j) {
			if (mtrx[i][j] != rhs.mtrx[i][j]) {
				return true;
			}
		}
	}
	return false;
}

Matrix operator*(const int& scalar, const Matrix& rhs)
{
	for (size_t i = 0; i < rhs.rows; ++i) {
		for (size_t j = 0; j < rhs.columns; ++j) {
			rhs.mtrx[i][j] *= scalar;
		}
	}
	return rhs;
}

std::ostream& operator<<(std::ostream& out, const Matrix& rhs)
{
	for (size_t i = 0; i < rhs.rows; ++i) {
		out << '\n';
		for (size_t j = 0; j < rhs.columns; ++j) {
			out << std::setw(7) << rhs.mtrx[i][j];
		}
	}
	out << '\n';
	return out;
}

std::istream& operator>>(std::istream& in, const Matrix& rhs)
{
	for (size_t i = 0; i < rhs.rows; ++i) {
		std::cout << '\n';
		for (size_t j = 0; j < rhs.columns; ++j) {
			std::cout << "Enter your number in matrix position (" << i << "," << j << "): ";
			in >> rhs.mtrx[i][j];
			while (!checkStream()) {
				std::cout << "Enter a number instead of the letter: ";
				std::cin >> rhs.mtrx[i][j];
			}
		}
	}
	return in;
}
