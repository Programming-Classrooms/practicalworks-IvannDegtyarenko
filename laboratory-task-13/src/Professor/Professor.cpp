#include "Professor.hpp"


Professor::Professor() : Person("Professor's Name")
{
	const char* a = "Dekanat";
	department = new char[strlen(a) + 1];
	strcpy(department, a);
}

Professor::Professor(
	const char* initName, 
	const char* initDepartment
): Person(initName)
{
	if (strlen(initDepartment) == 0) {
		throw std::runtime_error("Wrong input! Empty string!");
	}
	department = new char[strlen(initDepartment) + 1];
	strcpy(department, initDepartment);
}

Professor::Professor(const Professor& init): Person(init), department(init.department)
{
	department = new char[strlen(init.department) + 1];
	strcpy(department, init.department);
}

Professor::~Professor()
{
	delete[] department;
}

char* Professor::getDepartment() const
{
	return this->department;
}

void Professor::setDepartment(const char* rhs)
{
	if (strlen(rhs) == 0) {
		throw std::runtime_error("Wrong input! Empty string!\n");
	}
	this->department = new char[strlen(rhs) + 1];
	strcpy(this->department, rhs);
}

void Professor::print(std::ostream& out) const
{
	out << *this;
}

std::ostream& operator<<(std::ostream& out, const Professor& rhs)
{
	out << "Professor's Name: " << Person(rhs);
	out << "Professor's Department: " << rhs.department;
	return out;
}

std::istream& operator>>(std::istream& in, Professor& rhs)
{
	std::cout << "\nEnter Professor's name: ";
	char temp[2024];
	in.getline(temp, 2024);
	rhs.setPersonFullName(temp);
	std::cout << "\nEnter Professors's department: ";
	in.getline(temp, 2024);
	rhs.setDepartment(temp);
	return in;
}
