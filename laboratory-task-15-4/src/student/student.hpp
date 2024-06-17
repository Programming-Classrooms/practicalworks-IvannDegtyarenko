#ifndef STUDENT_HPP
#define STUDENT_HPP

#include <iostream>


class Student
{
public:
    std::string studentName;
    size_t course;
    size_t group;

    Student(std::string, size_t, size_t);
    ~Student() {}

    friend std::ostream& operator<<(std::ostream&, const Student&);
};
#endif //STUDENT_HPP