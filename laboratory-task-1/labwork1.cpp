#include <iostream>
#include <exception>
#include <cmath>


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


void getFuncResult(double x)
{
	double funcResult = (pow(exp(1), x) + pow(exp(1), (x * -1))) / 2;
	std::cout << "Value using standard functions = " << funcResult;
}


void getCloseResult(double x, int64_t k)
{
	double result = 1.0;
	double eps = pow(10, -k);
	uint64_t step = 3;
	double summand = (x * x) / 2;
	while (fabs(summand) >= eps) {
		result += summand;
		summand = (summand * x * x) / (step * (step + 1));
		step += 2;
	}
	std::cout << "Approximate value = " << result << '\n';
}


int main()
{
	try {
		std::cout << "Enter 'x' value: ";
		double x;
		std::cin >> x;
		std::cout << "Enter 'k' value that should be more than 1: ";
		int64_t k = getNumber();
		if (k <= 1) {
			throw std::exception("Error value of 'k'");
		}
		getCloseResult(x, k);
		getFuncResult(x);
	}
	catch (std::exception& error) {
		std::cout << error.what();
		return -1;
	}
	return 0;
}

