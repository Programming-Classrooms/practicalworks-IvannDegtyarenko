#include "library.hpp"

Library::Library(const Library& src) : library(src.library)
{}

void Library::insertBook(const Book& initBook)
{
    this->library.insert(std::pair<std::string, Book>(initBook.getBookTitle(), initBook));
}

void Library::eraseBook(const Book& deleteBook)
{
    this->library.erase(deleteBook.getBookTitle());
}

void Library::insertAuthor(Book& dest, const Author& initAuthor)
{
    this->library.find(dest.getBookTitle())->second.addAuthor(initAuthor);
}

void Library::eraseAuthor(Book& dest, const Author& deleteAuthor)
{
    this->library.find(dest.getBookTitle())->second.eraseAuthor(deleteAuthor.getSurename(), deleteAuthor.getName(), deleteAuthor.getFathername());
}

std::ostream& operator<<(std::ostream& out, const Library& src)
{
    for (const auto& i : src.library) {
        std::cout << i.second << '\n';
    }
    std::cout << '\n';
    return out;
}
