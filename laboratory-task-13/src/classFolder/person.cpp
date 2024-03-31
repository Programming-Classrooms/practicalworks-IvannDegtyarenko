#include "person.hpp"


Person::Person(const char* init)
{
	if (strlen(init) == 0) {
		throw std::runtime_error("Wrong input! Empty string!");
	}
	fullName = new char[strlen(init) + 1];
	strcpy(fullName, init);
}

Person::Person(const Person& init)
{
	fullName = new char[strlen(init.fullName) + 1];
	strcpy(fullName, init.fullName);
}

Person::~Person()
{
	delete[] fullName;
}

char* Person::getPersonFullName() const
{
	return this->fullName;
}

void Person::setPersonFullName(const char* rhs)
{
	if (strlen(rhs) == 0) {
		throw std::runtime_error("Wrong input! Empty string!\n");
	}
	this->fullName = new char[strlen(rhs) + 1];
	strcpy(this->fullName, rhs);
}

void Person::print(std::ostream& out) const
{
	out << *this;
}

std::istream& operator>>(std::istream& in, Person& rhs)
{
	char temp[2024];
	in.getline(temp, 2024);
	delete[] rhs.fullName;
	rhs.fullName = new char[strlen(temp) + 1];
	strcpy(rhs.fullName, temp);
	return in;
}

std::ostream& operator<<(std::ostream& out, const Person& rhs)
{
	out << rhs.fullName;
	out << '\n';
	return out;
}
