#include "studentAfterFirstSession.hpp"


const size_t StudentAfterFirstSession::sizeForArr = 4;

StudentAfterFirstSession::StudentAfterFirstSession(
	std::string initName, 
	size_t initCourse, 
	size_t initGroup, 
	size_t initBook
): StudentBeforeSession(initName, initCourse, initGroup, initBook)
{
	this->marksArr = new size_t[this->sizeForArr];
	for (size_t i = 0; i < this->sizeForArr; ++i) {
		marksArr[i] = rand() % 10 + 1;
	}
}

StudentAfterFirstSession::StudentAfterFirstSession(const StudentAfterFirstSession& init, size_t initBook): StudentBeforeSession(init, initBook)
{
	this->marksArr = new size_t[this->sizeForArr];
	for (size_t i = 0; i < this->sizeForArr; ++i) {
		marksArr[i] = init.marksArr[i];
	}
}

StudentAfterFirstSession::~StudentAfterFirstSession()
{
	delete[] marksArr;
}

size_t& StudentAfterFirstSession::operator[](int index)
{
	if (index < 0 || index >= this->sizeForArr) {
		throw std::invalid_argument("Wrong input!");
	}
	return marksArr[index];
}

void StudentAfterFirstSession::getMarks() const
{
	for (size_t i = 0; i < this->sizeForArr; ++i) {
		std::cout << this->marksArr[i] << " ";
	}
}

void StudentAfterFirstSession::changeMark(const int& index, const int& mark)
{
	if (index < 0 || index >= this->sizeForArr) {
		throw std::invalid_argument("Wrong input!");
	}
	if (mark <= 0 || mark > 10) {
		throw std::invalid_argument("Wrong input of mark!");
	}
	this->marksArr[index] = mark;
}

double StudentAfterFirstSession::getAverageMark()
{
	double averageMark = 0.0;
	for (size_t i = 0; i < this->sizeForArr; ++i) {
		averageMark += this->marksArr[i];
	}
	averageMark /= this->sizeForArr;
	return averageMark;
}

void StudentAfterFirstSession::print(std::ostream& out) const
{
	StudentBeforeSession::print(out);
	out << *this;
}

std::ostream& operator<<(std::ostream& out, const StudentAfterFirstSession& rhs)
{
	out << "After 1st session Student has marks: ";
	rhs.getMarks();
	out << '\n';
	return out;
}
