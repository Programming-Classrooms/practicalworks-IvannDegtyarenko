#ifndef PROFESSOR_HPP
#define PROFESSOR_HPP
#include "person.hpp"

class Professor final : public Person 
{
private:
	char* department;
public:
	Professor();
	Professor(const char*, const char*);
	Professor(const Professor&);
	virtual ~Professor();

	char* getDepartment() const;

	void setDepartment(const char*);

	friend std::ostream& operator<<(std::ostream&, const Professor&);
	friend std::istream& operator>>(std::istream&, Professor&);
	void print(std::ostream&) const;
};
#endif // !PROFESSOR_HPP
