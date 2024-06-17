#include "student.hpp"

Student::Student(std::string initName, size_t initCourse, size_t initGroup): studentName(initName)
{
    if (initCourse <= 0) {
        throw std::invalid_argument("Wrong number of student's course. Check your file");
    }
    this->course = initCourse;

    if (initGroup <= 0) {
        throw std::invalid_argument("Wrong number of student's group. Check your file");
    }
    this->group = initGroup;
}

std::ostream &operator<<(std::ostream & out, const Student & src)
{
    out << src.studentName << src.course << src.group << '\n';
    return out;
}
