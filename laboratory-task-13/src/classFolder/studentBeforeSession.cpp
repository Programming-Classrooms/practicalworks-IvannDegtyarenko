#include "studentBeforeSession.hpp"


size_t StudentBeforeSession::counterID = 0;

StudentBeforeSession::StudentBeforeSession(
	std::string initName, 
	size_t initCourse,
	size_t initGroup, 
	size_t initBook
): uniqueID(++counterID), group(initGroup), bookNumber(initBook) 
{
	if (initName.length() == 0) {
		throw std::invalid_argument("Empty 'Name' string");
	}
	else {
		this->name = initName;
	}
	if (initCourse < 0 || initCourse > 5) {
		throw std::logic_error("Too gigantic number for course");
	}
	else {
		this->course = initCourse;
	}
}

StudentBeforeSession::StudentBeforeSession(const StudentBeforeSession& init, size_t initBook):
	uniqueID(++counterID),
	name(init.name),
	course(init.course),
	group(init.group),
	bookNumber(initBook)
{}

size_t StudentBeforeSession::getUniqueID() const
{
	return this->uniqueID;
}

std::string StudentBeforeSession::getName() const
{
	return this->name;
}

size_t StudentBeforeSession::getGroup() const
{
	return this->group;
}

size_t StudentBeforeSession::getCourse() const
{
	return this->course;
}

size_t StudentBeforeSession::getBookNumber() const
{
	return this->bookNumber;
}

void StudentBeforeSession::setNewName(std::string rhs)
{
	if (rhs.length() == 0) {
		throw std::invalid_argument("Empty 'Name' string");
	}
	else
	{
		this->name = rhs;
	}
}

void StudentBeforeSession::setNewGroup(size_t rhs)
{
	this->group = rhs;
}

void StudentBeforeSession::setNewCourse(size_t rhs)
{
	if (rhs < 0 || rhs > 5) {
		throw std::logic_error("Too gigantic number for course");
	}
	else {
		this->course = rhs;
	}
}

void StudentBeforeSession::print(std::ostream& out) const
{
	out << *this;
}

std::ostream& operator<<(std::ostream& out, const StudentBeforeSession& rhs)
{
	out << "Student's uniqueID: " << rhs.uniqueID << '\n';
	out << "Student's Name: " << rhs.name << '\n';
	out << "Student's Course: " << rhs.course << '\n';
	out << "Student's Group: " << rhs.group << '\n';
	out << "Student's Book Number: " << rhs.bookNumber << '\n';
	return out;
}
