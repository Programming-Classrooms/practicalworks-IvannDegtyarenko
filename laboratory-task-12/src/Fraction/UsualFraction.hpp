#ifndef USUALFRACTION_HPP
#define USUALFRACTION_HPP

#include <iostream>
#include <cmath>
#include <exception>
#include <numeric>


class UsualFraction
{
private:
	int numerator;
	int denominator;
public:
	UsualFraction(int = 0, int = 1);
	UsualFraction(const UsualFraction&);
	~UsualFraction() {}

	int getNumerator() const;
	int getDenominator() const;
	void getUsualFraction() const;

	void setNumerator(int);
	void setDenominator(int);

	UsualFraction simplifyFraction() const;

	UsualFraction operator+(const UsualFraction&) const;
	UsualFraction operator-(const UsualFraction&) const;
	UsualFraction operator*(const UsualFraction&) const;
	UsualFraction operator/(const UsualFraction&) const;

	bool operator!=(const UsualFraction&);
	bool operator<(const UsualFraction&);

	UsualFraction& operator++();
	UsualFraction& operator--();
	UsualFraction operator++(int);
	UsualFraction operator--(int);

	UsualFraction operator-() const;
	UsualFraction operator!() const;
	
	UsualFraction& operator=(const UsualFraction&);
	UsualFraction& operator+=(const UsualFraction&);
	UsualFraction& operator-=(const UsualFraction&);
	UsualFraction& operator*=(const UsualFraction&);
	UsualFraction& operator/=(const UsualFraction&);

	friend std::ostream& operator<<(std::ostream&, const UsualFraction&);
	friend std::istream& operator>>(std::istream&, UsualFraction&);

	explicit operator double() const;
};
#endif // USUALFRACTION_HPP
