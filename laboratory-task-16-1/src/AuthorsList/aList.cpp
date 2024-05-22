#include "aList.hpp"

AList::AList() : authorsList(std::set<Author>())
{}

AList::AList(const std::set<Author> &init) : authorsList(init)
{}

AList::AList(const AList& src) : authorsList(src.authorsList)
{}

void AList::insert(const Author& src)
{
    this->authorsList.insert(src);
}

void AList::emplace(const std::string& initSurename, const std::string& initName, const std::string& initFathername)
{
    this->authorsList.emplace(initSurename, initName, initFathername);
}

AList &AList::operator=(const AList& src)
{
    if (this != &src) {
        this->authorsList = src.authorsList;
    }
    return *this;
}

bool AList::operator==(const AList& rhs) const
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

void AList::erase(const std::string& dSurename, const std::string& dName, const std::string& dFathername)
{
    std::set<Author>::iterator elemToDelete = authorsList.find(Author(dSurename, dName, dFathername));
    if (elemToDelete == authorsList.end()) {
        return;
    }
    authorsList.erase(elemToDelete);
}

bool AList::find(const Author& elemToFind)
{
    return authorsList.find(elemToFind) != authorsList.end(); 
}

std::ostream& operator<<(std::ostream& out, const AList& src)
{
    for (const auto& i : src.authorsList) {
        out << i;
    }
    return out;
}
