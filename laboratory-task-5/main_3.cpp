/*
	Задание номер 2 из файла "Лаб 5 Подпрограммы"
	Значения будут вычисляться по формуле левых прямоугольников
	и по формуле параболических трапеций (по формуле Симпсона)
	Третий интеграл
*/


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

double thirdIntegral(double x)
{
	return 1 / (x * log(x) * log(x));
}

double getDoubleValue()
{
	double number;
	std::cin >> number;
	while (!checkStream()) {
		std::cout << "Input a number instead of the letter: ";
		std::cin >> number;
	}
	return number;
}

double leftRectanglesMethod(double lb, double ub, double epsilon)
{
	uint64_t splitSegments = 8;
	double jump = 0.0;
	double x = 0.0;
	double integral1 = 0.0;
	double integral2 = thirdIntegral(ub) * (ub - lb);
	while (fabs(integral1 - integral2) >= epsilon) {
		integral1 = integral2;
		integral2 = 0.0;
		splitSegments *= 2;
		jump = (ub - lb) / splitSegments;
		for (size_t step = 1; step <= splitSegments; ++step) {
			x = lb + (step - 1) * jump;
			integral2 += jump * thirdIntegral(x);
		}
	}
	return integral2;
}

double integralSummand(uint64_t splitSegments, double lb, double ub)
{
	double step = (ub - lb) / splitSegments;
	double firstSummand = 0;
	double secondSummand = 0;
	for (uint64_t i = 1; i < splitSegments; ++i) {
		if ((i % 2) == 0) {
			firstSummand += (2 * thirdIntegral(lb + i * step));
		}
		else {
			secondSummand += (4 * thirdIntegral(lb + i * step));
		}
	}
	double result = step / 3 * ((firstSummand)+(secondSummand)+thirdIntegral(splitSegments * step));
	return result;
}

double parabolicTrapezoidMethod(double lb, double ub, double epsilon)
{
	uint64_t splitSegments = 4;
	double x = 0;
	double integral1 = 0;
	double integral2 = integralSummand(splitSegments, lb, ub);
	splitSegments *= 2;
	while (fabs(integral2 - integral1) > epsilon) {
		integral1 = integral2;
		integral2 = integralSummand(splitSegments, lb, ub);
		splitSegments *= 2;
	}
	return integral2;
}

int main()
{
	try {
		std::cout << "Enter the lower limit of integration: ";
		double lowerBound = getDoubleValue();
		std::cout << "Enter the upper limit of integration: ";
		double upperBound = getDoubleValue();
		std::cout << "Enter the epsilon value: ";
		double epsilon = getDoubleValue();
		double result1 = leftRectanglesMethod(lowerBound, upperBound, epsilon);
		std::cout << "Counted integral using left rectangles method = " << result1 << '\n';
		double result2 = parabolicTrapezoidMethod(lowerBound, upperBound, epsilon);
		std::cout << "Counted integral using the method of parabolic trapezoid = " << result2;
	}
	catch (std::exception& error) {
		std::cout << error.what();
		return -1;
	}
	return 0;
}

