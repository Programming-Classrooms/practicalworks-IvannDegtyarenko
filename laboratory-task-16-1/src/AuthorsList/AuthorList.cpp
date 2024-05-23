#include "AuthorList.hpp"

AuthorList::AuthorList() : authorsList(std::set<Author>())
{}

AuthorList::AuthorList(const std::set<Author> &init) : authorsList(init)
{}

AuthorList::AuthorList(const AuthorList& src) : authorsList(src.authorsList)
{}

void AuthorList::insert(const Author& src)
{
    this->authorsList.insert(src);
}

void AuthorList::emplace(const std::string& initSurename, const std::string& initName, const std::string& initFathername)
{
    this->authorsList.emplace(initSurename, initName, initFathername);
}

AuthorList& AuthorList::operator=(const AuthorList& src)
{
    if (this != &src) {
        this->authorsList = src.authorsList;
    }
    return *this;
}

bool AuthorList::operator==(const AuthorList& rhs) const
{
    if (this->authorsList.size() != rhs.authorsList.size()) {
        return false;
    }
    for (const auto& i : this->authorsList) {
        if (rhs.authorsList.find(i) == rhs.authorsList.end()) {
            return false;
        }
    }
    return true;
}

void AuthorList::erase(const std::string& dSurename, const std::string& dName, const std::string& dFathername)
{
    std::set<Author>::iterator elemToDelete = authorsList.find(Author(dSurename, dName, dFathername));
    if (elemToDelete == authorsList.end()) {
        return;
    }
    authorsList.erase(elemToDelete);
}

bool AuthorList::find(const Author& elemToFind)
{
    return authorsList.find(elemToFind) != authorsList.end(); 
}

std::ostream& operator<<(std::ostream& out, const AuthorList& src)
{
    for (const auto& i : src.authorsList) {
        out << i;
    }
    return out;
}
