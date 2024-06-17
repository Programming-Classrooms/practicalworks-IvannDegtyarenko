#ifndef STUDENTSECONDSESSION_HPP
#define STUDENTSECONDSESSION_HPP

#include "../StudentFirstSession/StudentFirstSession.hpp"


class StudentSecondSession final : public StudentFirstSession
{
private:
    size_t* marksArrSec;
    const static size_t sizeForSecArr;
public:
    StudentSecondSession() = delete;
    StudentSecondSession(std::string, size_t, size_t, size_t);
    StudentSecondSession(const StudentSecondSession&) = delete;
    StudentSecondSession(const StudentSecondSession&, size_t);
    ~StudentSecondSession();

    virtual size_t& operator[](int) override;
    
    virtual void getMarks() const override;
    virtual void changeMark(const int&, const int&) override;
    virtual double getAverageMark() override;

    friend std::ostream& operator<<(std::ostream&, const StudentSecondSession&);
    virtual void print(std::ostream&) const override;
};
#endif // !STUDENTSECONDSESSION_HPP
