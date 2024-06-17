#ifndef STUDENT_HPP
#define STUDENT_HPP

#include "../Person/Person.hpp"


class Student final : public Person
{
private:
	int32_t course;
	int32_t group;
public:
	Student();
	Student(const char*, int32_t, int32_t);
	Student(const Student&);

	int32_t getCourse() const;
	int32_t getGroup() const;

	void setCourse(int32_t);
	void setGroup(int32_t);

	friend std::istream& operator>>(std::istream&, Student&);
	friend std::ostream& operator<<(std::ostream&, const Student&);
	void print(std::ostream&) const;
};
#endif // !STUDENT_HPP
