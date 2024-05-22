#include "author.hpp"

Author::Author(std::string initSurename, std::string initName, std::string initFathername)
{
    if (initSurename.length() == 0) {
        throw std::invalid_argument("Empty string in Surename. Can't Initialize");
    }
    this->surename = initSurename;
    if (initName.length() == 0) {
        throw std::invalid_argument("Empty string in Name. Can't Initialize");
    }
    this->name = initName;
    if (initFathername.length() == 0) {
        throw std::invalid_argument("Empty string in Fathername. Can't Initialize");
    }
    this->fathername = initFathername;
}

Author::Author(const Author& src) : surename(src.surename), name(src.name), fathername(src.fathername) 
{}

std::string Author::getSurename() const
{
    std::string safe = this->surename;
    return safe;
}

std::string Author::getName() const
{
    std::string safe = this->name;
    return safe;
}

std::string Author::getFathername() const
{
    std::string safe = this->fathername;
    return safe;
}

void Author::setSurename(const std::string& src)
{
    if (src.length() == 0) {
        throw std::invalid_argument("Can't Initialize From empty string");
    }
    this->surename = src;
}

void Author::setName(const std::string& src)
{
    if (src.length() == 0) {
        throw std::invalid_argument("Can't Initialize From empty string");
    }
    this->name = src;
}

void Author::setFathername(const std::string& src)
{
    if (src.length() == 0) {
        throw std::invalid_argument("Can't Initialize From empty string");
    }
    this->fathername = src;
}

bool Author::operator==(const Author& rhs) const
{
    return this->surename == rhs.surename && this->name == rhs.name && this->fathername == rhs.fathername;
}

bool Author::operator<(const Author& rhs) const
{
    if (this->surename == rhs.surename) {
        if (this->name == rhs.name) {
            return this->fathername < rhs.fathername;
        }
        return this->name < rhs.name;
    }
    return this->surename < rhs.surename;
}

bool Author::operator>(const Author& rhs) const
{
    return !(*this < rhs) && !(*this == rhs);
}

Author& Author::operator=(const Author& src)
{
    if (this != &src) {
        this->surename = src.surename;
        this->name = src.name;
        this->fathername = src.fathername;
    }
    return *this;
}

std::ostream& operator<<(std::ostream& out, const Author& src)
{
    out << src.surename << src.name << src.fathername << '\n';
    return out;
}

std::istream &operator>>(std::istream& in, Author& dest)
{
    std::string line;
    std::getline(in, line, ',');

    dest.surename = line;
    std::getline(in, line, ',');
    
    dest.name = line;
    std::getline(in, line, ';');

    dest.fathername = line;
    return in;
}
