#ifndef PERSON_HPP
#define PERSON_HPP
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>

class Person {
protected:
	char* fullName;
public:
	Person() = delete;
	Person(const char*);
	Person(const Person&);
	virtual ~Person();

	char* getPersonFullName() const;

	void setPersonFullName(const char*);
	
	friend std::istream& operator>>(std::istream&, Person&);
	friend std::ostream& operator<<(std::ostream&, const Person&);
	virtual void print(std::ostream&) const;
};
#endif // !PERSON_HPP