#ifndef LIBRARY_HPP
#define LIBRARY_HPP

#include <vector>

#include "../Book/Book.hpp"


class Library {
private:
    std::map<std::string, Book> library;
public:
    Library();
    Library(const Library&);
    ~Library() = default;

    void addBook(const Book&);
    Book findBook(const std::string&);
    void eraseBook(const std::string&);
    void viewBooks();
    void addAuthor(const std::string&, const std::string&);
    void deleteAuthor(const std::string&, const std::string&);
    void sortByTitle();
};
#endif //LIBRARY_HPP
