#include "Student.hpp"


Student::Student(): Person("Student's Name"), course(1), group(7121)
{}

Student::Student(
	const char* initFullName, 
	int32_t InitCourse, 
	int32_t initGroup
):  Person(initFullName), course(InitCourse), group(initGroup)
{
	if (InitCourse < 1 || InitCourse > 5) {
		throw std::invalid_argument("Wronge course number\n");
	}
}

Student::Student(const Student& init): Person(init), course(init.course), group(init.group)
{}

int32_t Student::getCourse() const
{
	return this->course;
}

int32_t Student::getGroup() const
{
	return this->group;
}

void Student::setCourse(int32_t rhs)
{
	if (rhs < 1 || rhs > 5) {
		throw std::invalid_argument("Wrong course number\n");
	}
	this->course = rhs;
}

void Student::setGroup(int32_t rhs)
{
	this->group = rhs;
}

void Student::print(std::ostream& out) const
{
	out << *this;
}

std::istream& operator>>(std::istream& in, Student& rhs)
{
	std::cout << "\nEnter Student's name: ";
	char temp[2024];
	in.getline(temp, 2024);
	rhs.setPersonFullName(temp);
	std::cout << "\nEnter Student's course: ";
	in >> rhs.course;
	if (rhs.course < 1 || rhs.course > 5) {
		throw std::invalid_argument("Wronge course number\n");
	}
	std::cout << "\nEnter Student's group: ";
	in >> rhs.group;
	return in;
}

std::ostream& operator<<(std::ostream& out, const Student& rhs)
{
	out << "Student's Name: " << Person(rhs);
	out << "Studen is studying on " << rhs.course;
	if (rhs.course == 1) {
		out << "st course";
	}
	else {
		if (rhs.course == 2) {
			out << "nd course";
		}
		else {
			if (rhs.course == 3) {
				out << "rd course";
			}
			else {
				out << "th course";
			}
		}
	}
	out << "\nStudent's group number: " << rhs.group;
	return out;
}
