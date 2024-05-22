#ifndef BOOK_HPP
#define BOOK_HPP

#include "../AuthorsList/aList.hpp"
#include <sstream>


class Book {
private:
    size_t UDC;
    AList bookAuthors;
    std::string bookTitle;
    size_t yearOfPublish;
public:
    Book();
    Book(const size_t&, const AList&, const std::string&, const size_t&);
    Book(const Book&);
    ~Book() = default;

    size_t getUDC() const;
    AList getAuthors() const;
    std::string getBookTitle() const;
    size_t getYearOfPublish() const;

    void setUDC(const size_t&);
    void setBookAuthors(const AList&);
    void setBookTitle(const std::string&);
    void setYearOfPublish(const size_t&);

    bool operator==(const Book&) const;
    bool operator<(const Book&) const;

    Book& operator=(const Book&);
    void clear();

    void addAuthor(const Author&);
    void addAuthor(const std::string&, const std::string&, const std::string&);
    void eraseAuthor(const std::string&, const std::string&, const std::string&);

    friend std::ostream& operator<<(std::ostream&, const Book&);
    friend std::istream& operator>>(std::istream&, Book&);
};
#endif //BOOK_HPP
