#ifndef CLASSMATRIX_H
#define CLASSMATRIX_H

#include <iostream>
#include <iomanip>
#include <cmath>
#include <ctime>
#include <exception>


class Matrix 
{
private:
	double** mtrx;
	int rows;
	int columns;
	void fillMatrix();
public:
	Matrix(int = 1, int = 1);
	Matrix(const Matrix&);
	~Matrix();

	int getRows() const;
	int getColumns() const;
	void getMatrix() const;
	double& getMatrixElement(int, int) const;

	void setRows(int);
	void setColumns(int);
	
	Matrix& operator=(const Matrix&);
	Matrix& operator+=(const Matrix&);
	Matrix& operator-=(const Matrix&);
	Matrix& operator*=(const Matrix&);

	Matrix operator*(const int&);
	Matrix operator/(const int&);
	Matrix operator+(const Matrix&);
	Matrix operator-(const Matrix&);
	Matrix operator*(const Matrix&);

	bool operator!=(const Matrix&);

	friend Matrix operator*(const int&, const Matrix&);
	friend std::ostream& operator<<(std::ostream&, const Matrix&);
	friend std::istream& operator>>(std::istream&, const Matrix&);
};
#endif // CLASSMATRIX_H