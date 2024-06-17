#ifndef AUTHOR_HPP
#define AUTHOR_HPP

#include <iostream>
#include <string>
#include <stdexcept>
#include <algorithm>


class Author {
private:
    std::string surename;
    std::string name;
    std::string fathername;
public:
    Author() = default;
    Author(std::string, std::string, std::string);
    Author(const Author&);
    virtual ~Author() {}

    std::string getSurename() const;
    std::string getName() const;
    std::string getFathername() const;

    void setSurename(const std::string&);
    void setName(const std::string&);
    void setFathername(const std::string&);

    bool operator==(const Author&) const;
    bool operator<(const Author&) const;
    bool operator>(const Author&) const;

    Author& operator=(const Author&);

    friend std::ostream& operator<<(std::ostream&, const Author&);
    friend std::istream& operator>>(std::istream&, Author&);
};
#endif //AUTHOR_HPP
