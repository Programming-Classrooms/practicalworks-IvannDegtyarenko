#include "StudentFirstSession.hpp"


const size_t StudentFirstSession::sizeForArr = 4;

StudentFirstSession::StudentFirstSession(
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

StudentFirstSession::StudentFirstSession(const StudentFirstSession& init, size_t initBook): StudentBeforeSession(init, initBook)
{
	this->marksArr = new size_t[this->sizeForArr];
	for (size_t i = 0; i < this->sizeForArr; ++i) {
		marksArr[i] = init.marksArr[i];
	}
}

StudentFirstSession::~StudentFirstSession()
{
	delete[] marksArr;
}

size_t& StudentFirstSession::operator[](int index)
{
	if (index < 0 || index >= this->sizeForArr) {
		throw std::invalid_argument("Wrong input!");
	}
	return marksArr[index];
}

void StudentFirstSession::getMarks() const
{
	for (size_t i = 0; i < this->sizeForArr; ++i) {
		std::cout << this->marksArr[i] << " ";
	}
}

void StudentFirstSession::changeMark(const int& index, const int& mark)
{
	if (index < 0 || index >= this->sizeForArr) {
		throw std::invalid_argument("Wrong input!");
	}
	if (mark <= 0 || mark > 10) {
		throw std::invalid_argument("Wrong input of mark!");
	}
	this->marksArr[index] = mark;
}

double StudentFirstSession::getAverageMark()
{
	double averageMark = 0.0;
	for (size_t i = 0; i < this->sizeForArr; ++i) {
		averageMark += this->marksArr[i];
	}
	averageMark /= this->sizeForArr;
	return averageMark;
}

void StudentFirstSession::print(std::ostream& out) const
{
	StudentBeforeSession::print(out);
	out << *this;
}

std::ostream& operator<<(std::ostream& out, const StudentFirstSession& rhs)
{
	out << "After 1st session Student has marks: ";
	rhs.getMarks();
	out << '\n';
	return out;
}
