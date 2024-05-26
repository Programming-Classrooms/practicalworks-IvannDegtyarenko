#ifndef BOOK_HPP
#define BOOK_HPP

#include <iostream>
#include <typeinfo>
#include <stdexcept>
#include <string>
#include <map>
#include <set>
#include <ctime>
#include <algorithm>


class Book {
private:
    std::string ISBN;
    static size_t uniqueCounter;
    std::string title;
    std::set<std::string> authors;
    double price;
    size_t count;
public:
    Book();
    Book(const std::string&, const std::set<std::string>&, const double&, const size_t&);
    Book(const Book&);
    ~Book() = default;

    std::string getISBN() const;
    std::string getTitle() const;
    std::set<std::string> getAuthors() const;
    double getPrice() const;
    size_t getCount() const;

    void setISBN(const std::string&);
    void setTitle(const std::string&);
    void setAuthors(const std::set<std::string>&);
    void setPrice(const double&);
    void setCount(const size_t&);

    void addAuthor(std::string);
    void deleteAuthor(std::string);

    Book& operator=(const Book&);

    bool operator==(const Book&);
    bool operator<(const Book&);

    friend std::ostream& operator<<(std::ostream&, const Book&);
    friend std::istream& operator>>(std::istream&, Book&);
};
#endif //BOOK_HPP