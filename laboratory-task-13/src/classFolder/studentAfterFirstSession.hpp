#ifndef STUDENTAFTERFIRSTSESSION_HPP
#define STUDENTAFTERFIRSTSESSION_HPP
#include "studentBeforeSession.hpp"


class StudentAfterFirstSession : public StudentBeforeSession
{
protected:
	size_t* marksArr;
	const static size_t sizeForArr;
public:
	StudentAfterFirstSession() = delete;
	StudentAfterFirstSession(std::string, size_t, size_t, size_t);
	StudentAfterFirstSession(const StudentAfterFirstSession&) = delete;
	StudentAfterFirstSession(const StudentAfterFirstSession&, size_t);
	~StudentAfterFirstSession();

	virtual size_t& operator[](int);

	virtual void getMarks() const;
	virtual void changeMark(const int&, const int&);
	virtual double getAverageMark();

	friend std::ostream& operator<<(std::ostream&, const StudentAfterFirstSession&);
	virtual void print(std::ostream&) const override;
};
#endif // !FIRSTSESSION_HPP
