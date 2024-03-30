#include "usualFraction.hpp"


UsualFraction::UsualFraction(int initN, int initD) : numerator(initN), denominator(initD)
{
	if (initD == 0) {
		throw std::invalid_argument("Invalid argument exception caught: Can't use 0 as denominator");
	}
	if (initD < 0) {
		denominator *= -1;
		numerator *= -1;
	}
}

UsualFraction::UsualFraction(const UsualFraction& rhsInit) : numerator(rhsInit.numerator), denominator(rhsInit.denominator)
{}

int UsualFraction::getNumerator() const
{
	return this->numerator;
}

int UsualFraction::getDenominator() const
{
	return this->denominator;
}

void UsualFraction::getUsualFraction() const
{
	UsualFraction rhsCopy(this->simplifyFraction());
	if (rhsCopy.denominator != 1) {
		std::cout << rhsCopy.numerator << "/" << rhsCopy.denominator << '\n';
	}
	else {
		std::cout << rhsCopy.numerator << '\n';
	}
}

void UsualFraction::setNumerator(int init)
{
	this->numerator = init;
}

void UsualFraction::setDenominator(int init)
{
	if (init == 0) {
		throw std::invalid_argument("Invalid argument exception caught: Can't use 0 as denominator");
	}
	if (init < 0) {
		init *= -1;
		this->denominator = init;
		this->numerator *= -1;
	}
}

UsualFraction UsualFraction::simplifyFraction() const
{
	int fractionDivisor = std::gcd(this->numerator, this->denominator);
	return UsualFraction(this->numerator / fractionDivisor, this->denominator / fractionDivisor);
}

UsualFraction UsualFraction::operator+(const UsualFraction& rhs) const
{
	return UsualFraction(this->numerator * rhs.denominator + rhs.numerator * this->denominator, 
						this->denominator * rhs.denominator).simplifyFraction();
}

UsualFraction UsualFraction::operator-(const UsualFraction& rhs) const
{
	return UsualFraction(this->numerator * rhs.denominator - rhs.numerator * this->denominator,
						this->denominator * rhs.denominator).simplifyFraction();
}

UsualFraction UsualFraction::operator*(const UsualFraction& rhs) const
{
	return UsualFraction(this->numerator * rhs.numerator, this->denominator * rhs.denominator).simplifyFraction();
}

UsualFraction UsualFraction::operator/(const UsualFraction& rhs) const
{
	return UsualFraction(this->numerator * rhs.denominator, this->denominator * rhs.numerator).simplifyFraction();
}

bool UsualFraction::operator!=(const UsualFraction& rhs)
{
	UsualFraction lhsCopy(this->simplifyFraction());
	UsualFraction rhsCopy(rhs.simplifyFraction());
	return lhsCopy.numerator != rhsCopy.numerator || lhsCopy.denominator != rhsCopy.denominator;
}

bool UsualFraction::operator<(const UsualFraction& rhs)
{
	UsualFraction lhsCopy(this->simplifyFraction());
	UsualFraction rhsCopy(rhs.simplifyFraction());
	if (lhsCopy.denominator == rhsCopy.denominator) {
		return lhsCopy.numerator < rhsCopy.numerator;
	}
	if (lhsCopy.numerator == rhsCopy.numerator) {
		return lhsCopy.denominator > rhsCopy.denominator;
	}
	return lhsCopy.numerator * rhsCopy.denominator < rhsCopy.numerator * lhsCopy.denominator;
}

UsualFraction& UsualFraction::operator++()
{
	*this = UsualFraction(numerator + denominator, denominator);
	return *this;
}

UsualFraction& UsualFraction::operator--()
{
	*this = UsualFraction(numerator - denominator, denominator);
	return *this;
}

UsualFraction UsualFraction::operator++(int)
{
	UsualFraction copy(*this);
	*this = UsualFraction(numerator + denominator, denominator);
	return copy;
}

UsualFraction UsualFraction::operator--(int)
{
	UsualFraction copy(*this);
	*this = UsualFraction(numerator - denominator, denominator);
	return copy;
}

UsualFraction UsualFraction::operator-() const
{
	return UsualFraction(-(this->numerator), this->denominator);
}

UsualFraction UsualFraction::operator!() const
{
	if (this->numerator == 0) {
		throw std::invalid_argument("Invalid argument exception caught: Can't use 0 as denominator");
	}
	return UsualFraction(this->denominator, this->numerator);
}

UsualFraction& UsualFraction::operator=(const UsualFraction& rhs)
{
	if (this != &rhs) {
		this->numerator = rhs.numerator;
		this->denominator = rhs.denominator;
	}
	return *this;
}

UsualFraction& UsualFraction::operator+=(const UsualFraction& rhs)
{
	*this = *this + rhs;
	return *this;
}

UsualFraction& UsualFraction::operator-=(const UsualFraction& rhs)
{
	*this = *this - rhs;
	return *this;
}

UsualFraction& UsualFraction::operator*=(const UsualFraction& rhs)
{
	*this = *this * rhs;
	return *this;
}

UsualFraction& UsualFraction::operator/=(const UsualFraction& rhs)
{
	*this = *this / rhs;
	return *this;
}

UsualFraction::operator double() const
{
	return (static_cast<double>(this->numerator) / static_cast<double>(this->denominator));
}

std::ostream& operator<<(std::ostream& out, const UsualFraction& rhs)
{
	UsualFraction rhsCopy(rhs.simplifyFraction());
	if (rhsCopy.denominator != 1) {
		out << rhsCopy.numerator << "/" << rhsCopy.denominator << '\n';
		return out;
	}
	else {
		out << rhsCopy.numerator << '\n';
		return out;
	}
}

std::istream& operator>>(std::istream& in, UsualFraction& rhs)
{
	std::cout << "Enter numerator: ";
	in >> rhs.numerator;
	std::cout << "Enter denominator: ";
	in >> rhs.denominator;
	while (rhs.denominator == 0) {
		std::cout << "Enter right value: ";
		in >> rhs.denominator;
	}
	if (rhs.denominator < 0) {
		rhs.denominator *= -1;
		rhs.numerator *= -1;
	}
	return in;
}
