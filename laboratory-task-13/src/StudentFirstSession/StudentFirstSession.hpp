#ifndef STUDENTFIRSTSESSION_HPP
#define STUDENTFIRSTSESSION_HPP

#include "../StudentBeforeSession/StudentBeforeSession.hpp"


class StudentFirstSession : public StudentBeforeSession
{
protected:
	size_t* marksArr;
	const static size_t sizeForArr;
public:
	StudentFirstSession() = delete;
	StudentFirstSession(std::string, size_t, size_t, size_t);
	StudentFirstSession(const StudentFirstSession&) = delete;
	StudentFirstSession(const StudentFirstSession&, size_t);
	~StudentFirstSession();

	virtual size_t& operator[](int);

	virtual void getMarks() const;
	virtual void changeMark(const int&, const int&);
	virtual double getAverageMark();

	friend std::ostream& operator<<(std::ostream&, const StudentFirstSession&);
	virtual void print(std::ostream&) const override;
};
#endif // !STUDENTFIRSTSESSION_HPP
