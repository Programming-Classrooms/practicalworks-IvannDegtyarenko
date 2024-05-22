#include "book.hpp"

Book::Book() : UDC(0), bookAuthors(AList()), bookTitle(""), yearOfPublish(2024)
{}

Book::Book(
    const size_t &initUDC,
    const AList &initAuthors,
    const std::string &initTitle,
    const size_t &initYear) : UDC(initUDC), bookAuthors(initAuthors), bookTitle(initTitle), yearOfPublish(initYear)
{}

Book::Book(const Book& src) :
    UDC(src.UDC), bookAuthors(src.bookAuthors), bookTitle(src.bookTitle), yearOfPublish(src.yearOfPublish)
{}

size_t Book::getUDC() const
{
    size_t safe = this->UDC;
    return safe;
}

AList Book::getAuthors() const
{
    AList safe = this->bookAuthors;
    return safe;
}

std::string Book::getBookTitle() const
{
    std::string safe = this->bookTitle;
    return safe;
}

size_t Book::getYearOfPublish() const
{
    size_t safe = this->yearOfPublish;
    return safe;
}

void Book::setUDC(const size_t& init)
{
    this->UDC = init;
}

void Book::setBookAuthors(const AList& init)
{
    this->bookAuthors = init;
}

void Book::setBookTitle(const std::string& init)
{
    this->bookTitle = init;
}

void Book::setYearOfPublish(const size_t& init)
{
    this->yearOfPublish = init;
}

bool Book::operator==(const Book& rhs) const
{
    return this->UDC == rhs.UDC && this->bookAuthors == rhs.bookAuthors && this->bookTitle == rhs.bookTitle && this->yearOfPublish == rhs.yearOfPublish;
}

bool Book::operator<(const Book& rhs) const
{
    return this->bookTitle < rhs.bookTitle;
}

Book &Book::operator=(const Book& src)
{
    if (this != &src) {
        this->UDC = src.UDC;
        this->bookAuthors = src.bookAuthors;
        this->bookTitle = src.bookTitle;
        this->yearOfPublish = src.yearOfPublish;
    }
    return *this;
}

void Book::clear()
{
    this->UDC = 0;
    this->bookAuthors = std::set<Author>();
    this->bookTitle = "";
    this->yearOfPublish = 2024;
}

void Book::addAuthor(const Author& src)
{
    this->bookAuthors.insert(src);
}

void Book::addAuthor(const std::string& initSurename, const std::string& initName, const std::string& initFathername)
{
    this->bookAuthors.emplace(initSurename, initName, initFathername);
}

void Book::eraseAuthor(const std::string& authorSur, const std::string& authorName, const std::string& authorFathern)
{
    this->bookAuthors.erase(authorSur, authorName, authorFathern);
}

std::ostream &operator<<(std::ostream& out, const Book& src)
{
    out << "Book UDC: " << src.UDC << '\n';
    out << "Book Authors: " << src.bookAuthors;
    out << "Book Title: " << src.bookTitle << '\n';
    out << "Year Of Publish: " << src.yearOfPublish << '\n';
    return out;
}

std::istream& operator>>(std::istream& in, Book& dest)
{
    if (in.peek() == EOF) {
        return in;
    }
    std::string line;
    std::getline(in, line, ';');
    dest.UDC = std::stoul(line);
    std::getline(in, line, ';');
    std::stringstream streamForAuthors(line);
    Author temp;
    streamForAuthors >> temp;
    dest.addAuthor(temp);
    std::getline(in, line, ';');
    dest.bookTitle = line;
    std::getline(in, line, ';');
    dest.yearOfPublish = std::stoul(line);
    return in;
}
