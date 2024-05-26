#include "StudentSecondSession.hpp"


const size_t StudentSecondSession::sizeForSecArr = 5;

StudentSecondSession::StudentSecondSession(
    std::string initName, 
    size_t initCourse, 
    size_t initGroup, 
    size_t initBook
): 
StudentFirstSession(initName, initCourse, initGroup, initBook)
{
    this->marksArrSec = new size_t[this->sizeForSecArr];
	for (size_t i = 0; i < this->sizeForSecArr; ++i) {
		marksArrSec[i] = rand() % 10 + 1;
	}
}

StudentSecondSession::StudentSecondSession(
    const StudentSecondSession& init, 
    size_t initBook
): StudentFirstSession(init, initBook)
{
    this->marksArrSec = new size_t[this->sizeForSecArr];
	for (size_t i = 0; i < this->sizeForSecArr; ++i) {
		marksArrSec[i] = init.marksArrSec[i];
	}
}

StudentSecondSession::~StudentSecondSession()
{
    delete[] marksArrSec;
}

size_t& StudentSecondSession::operator[](int index)
{
   if (index < 0 || index >= this->sizeForSecArr) {
		throw std::invalid_argument("Wrong input!");
	}
	return marksArrSec[index];
}

void StudentSecondSession::getMarks() const
{
    for (size_t i = 0; i < this->sizeForSecArr; ++i) {
		std::cout << this->marksArrSec[i] << " ";
	}
}

void StudentSecondSession::changeMark(const int& index, const int& mark)
{
    if (index < 0 || index >= this->sizeForSecArr) {
		throw std::invalid_argument("Wrong input!");
	}
    if (mark <= 0 || mark > 10) {
		throw std::invalid_argument("Wrong input of mark!");
	}
	this->marksArrSec[index] = mark;
}

double StudentSecondSession::getAverageMark()
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

void StudentSecondSession::print(std::ostream& out) const
{
    StudentBeforeSession::print(out);
    out << *this;
}

std::ostream &operator<<(std::ostream& out, const StudentSecondSession& rhs)
{
    out << "After 2nd session Student has marks: ";
	rhs.getMarks();
	out << '\n';
	return out;
}
