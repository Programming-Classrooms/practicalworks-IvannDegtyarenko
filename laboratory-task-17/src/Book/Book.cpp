#include "Book.hpp"


size_t Book::uniqueCounter = rand() % 999;

Book::Book() :
    ISBN(""),
    title(""),
    authors(std::set<std::string>()),
    price(0),
    count(0)
{}

Book::Book(
    const std::string& initTitle, 
    const std::set<std::string>& initAuthors, 
    const double& initPrice, 
    const size_t& initCount
    ) :
    ISBN(std::to_string(rand() % uniqueCounter)),
    title(initTitle),
    authors(initAuthors),
    price(initPrice),
    count(initCount)
{}

Book::Book(const Book& src) :
    ISBN(std::to_string(rand() % uniqueCounter)),
    title(src.title),
    authors(src.authors),
    price(src.price),
    count(src.count)
{}

std::string Book::getISBN() const
{
    std::string safe = this->ISBN;
    return safe;
}

std::string Book::getTitle() const
{
    std::string safe = this->title;
    return safe;
}

std::set<std::string> Book::getAuthors() const
{
    std::set<std::string> safe = this->authors;
    return safe;
}

double Book::getPrice() const
{
    double safe = this->price;
    return safe;
}

size_t Book::getCount() const
{
    size_t safe = this->count;
    return safe;
}

void Book::setISBN(const std::string& init)
{
    this->ISBN = init;
}

void Book::setTitle(const std::string &init)
{
    this->title = init;
}

void Book::setAuthors(const std::set<std::string>& init)
{
    this->authors = init;
}

void Book::setPrice(const double& init)
{
    this->price = init;
}

void Book::setCount(const size_t& init)
{
    this->count = init;
}

void Book::addAuthor(std::string initAuthor)
{
    this->authors.insert(initAuthor);
}

void Book::deleteAuthor(std::string authorToDelete)
{
    this->authors.erase(authorToDelete);
}

Book& Book::operator=(const Book& rhs)
{
    if (this != &rhs) {
        this->ISBN = rhs.ISBN;
        this->title = rhs.title;
        this->authors = rhs.authors;
        this->price = rhs.price;
        this->count = rhs.count;
    }
    return *this;
}

bool Book::operator==(const Book& rhs)
{
    return this->title == rhs.title &&
    this->authors == rhs.authors &&
    this->price == rhs.price &&
    this->count == rhs.count;
}

bool Book::operator<(const Book& rhs)
{
    if (this->title == rhs.title) {
        if (this->price == rhs.price) {
            return this->count < rhs.count;
        }
        return this->price < rhs.price;
    }
    return this->title < rhs.title;
}

std::ostream& operator<<(std::ostream& out, const Book& src)
{
    out << "ISBN: " << src.ISBN << '\n';
    out << "Title: " << src.title << '\n';
    out << "Authors: ";
    for (const auto& i : src.authors) {
        out << i << ";\t";
    }
    out << '\n';
    out << "Price: " << src.price << '\n';
    out << "Count: " << src.count << '\n';
    return out;
}

std::istream& operator>>(std::istream& in, Book& dest)
{
    std::string initTitle = "";
    std::set<std::string> initAuthors;
    double initPrice = 0;
    size_t initCount = 0;
    
    std::cout << "Enter Book Title: ";
    in >> initTitle;

    std::cout << "Enter Authors. To Stop entering Type in 'stop': ";
    std::string line = "";
    in.ignore();
    std::getline(in, line);
    while (line != "stop") {
        initAuthors.insert(line);
        std::getline(in, line);
    }

    std::cout << "Enter Price: ";
    in >> initPrice;

    std::cout << "Enter Count: ";
    in >> initCount;

    Book init(initTitle, initAuthors, initPrice, initCount);
    dest = init;
    return in; 
}
