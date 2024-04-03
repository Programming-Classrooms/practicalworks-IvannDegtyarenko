#ifndef STUDENTAFTERSECONDSESSION_HPP
#define STUDENTAFTERSECONDSESSION_HPP

#include "studentAfterFirstSession.hpp"


class StudentAfterSecondSession final : public StudentAfterFirstSession
{
private:
    size_t* marksArrSec;
    const static size_t sizeForSecArr;
public:
    StudentAfterSecondSession() = delete;
    StudentAfterSecondSession(std::string, size_t, size_t, size_t);
    StudentAfterSecondSession(const StudentAfterSecondSession&, size_t);
    ~StudentAfterSecondSession();

    virtual size_t& operator[](int) override;
    
    virtual void getMarks() const override;
    virtual void changeMark(const int&, const int&) override;
    virtual double getAverageMark() override;

    friend std::ostream& operator<<(std::ostream&, const StudentAfterSecondSession&);
    virtual void print(std::ostream&) const override;
};
#endif // !STUDENTAFTERSECONDSESSION_HPP