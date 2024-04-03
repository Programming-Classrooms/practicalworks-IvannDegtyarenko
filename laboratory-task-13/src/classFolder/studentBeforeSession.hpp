#ifndef STUDENTBEFORESESSION_HPP
#define STUDENTBEFORESESSION_HPP
#include <iostream>
#include <string>
#include <typeinfo>
#include <ctime>


class StudentBeforeSession
{
protected:
	const size_t uniqueID;
	static size_t counterID;
	std::string name;
	size_t course;
	size_t group;
	const size_t bookNumber;
public:
	StudentBeforeSession() = delete;
	StudentBeforeSession(std::string, size_t, size_t, size_t);
	StudentBeforeSession(const StudentBeforeSession&) = delete;
	StudentBeforeSession(const StudentBeforeSession&, size_t);
	~StudentBeforeSession() {}

	size_t getUniqueID() const;
	std::string getName() const;
	size_t getGroup() const;
	size_t getCourse() const;
	size_t getBookNumber() const;

	void setNewName(std::string);
	void setNewGroup(size_t);
	void setNewCourse(size_t);

	friend std::ostream& operator<<(std::ostream&, const StudentBeforeSession&);
	virtual void print(std::ostream&) const;
};
#endif // !STUDENTBEFORESESSION_HPP
