#ifndef LIBRARY_HPP
#define LIBRARY_HPP

#include <map>
#include <algorithm>
#include <stdexcept>
#include <fstream>
#include <typeinfo>

#include "../Book/Book.hpp"


class Library{
private:
    std::multimap<std::string, Book> library;
public:
    Library() = default;
    Library(const Library&);
    ~Library() = default;

    void insertBook(const Book&);
    void eraseBook(const Book&);

    void insertAuthor(Book&, const Author&);
    void eraseAuthor(Book&, const Author&);

    friend std::ostream& operator<<(std::ostream&, const Library&);
};
#endif //LIBRARY_HPP
