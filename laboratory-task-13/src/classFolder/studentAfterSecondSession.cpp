#include "studentAfterSecondSession.hpp"


const size_t StudentAfterSecondSession::sizeForSecArr = 5;

StudentAfterSecondSession::StudentAfterSecondSession(
    std::string initName, 
    size_t initCourse, 
    size_t initGroup, 
    size_t initBook
): 
StudentAfterFirstSession(initName, initCourse, initGroup, initBook)
{
    this->marksArrSec = new size_t[this->sizeForSecArr];
	for (size_t i = 0; i < this->sizeForSecArr; ++i) {
		marksArrSec[i] = rand() % 10 + 1;
	}
}

StudentAfterSecondSession::StudentAfterSecondSession(
    const StudentAfterSecondSession& init, 
    size_t initBook
): StudentAfterFirstSession(init, initBook)
{
    this->marksArrSec = new size_t[this->sizeForSecArr];
	for (size_t i = 0; i < this->sizeForSecArr; ++i) {
		marksArrSec[i] = init.marksArrSec[i];
	}
}

StudentAfterSecondSession::~StudentAfterSecondSession()
{
    delete[] marksArrSec;
}

size_t& StudentAfterSecondSession::operator[](int index)
{
   if (index < 0 || index >= this->sizeForSecArr) {
		throw std::invalid_argument("Wrong input!");
	}
	return marksArrSec[index];
}

void StudentAfterSecondSession::getMarks() const
{
    for (size_t i = 0; i < this->sizeForSecArr; ++i) {
		std::cout << this->marksArrSec[i] << " ";
	}
}

void StudentAfterSecondSession::changeMark(const int& index, const int& mark)
{
    if (index < 0 || index >= this->sizeForSecArr) {
		throw std::invalid_argument("Wrong input!");
	}
    if (mark <= 0 || mark > 10) {
		throw std::invalid_argument("Wrong input of mark!");
	}
	this->marksArrSec[index] = mark;
}

double StudentAfterSecondSession::getAverageMark()
{
    double averageMark = 0.0;
	for (size_t i = 0; i < this->sizeForArr; ++i) {
		averageMark += this->marksArr[i];
	}
    for (size_t i = 0; i < this->sizeForSecArr; ++i) {
        averageMark += this->marksArrSec[i];
    }
	averageMark /= (this->sizeForArr + this->sizeForSecArr);
	return averageMark;
}

void StudentAfterSecondSession::print(std::ostream& out) const
{
    StudentBeforeSession::print(out);
    out << *this;
}

std::ostream &operator<<(std::ostream& out, const StudentAfterSecondSession& rhs)
{
    out << "After 2nd session Student has marks: ";
	rhs.getMarks();
	out << '\n';
	return out;
}
