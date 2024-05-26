#include "Library.hpp"

Library::Library() : library(std::map<std::string, Book>())
{}

Library::Library(const Library& src) : library(src.library)
{}

void Library::addBook(const Book& init)
{
    this->library.insert(std::pair<std::string, Book>(init.getISBN(), init));
}

Book Library::findBook(const std::string& ISBN)
{
    if (this->library.find(ISBN) != this->library.end()) {
        auto object = this->library.find(ISBN);
        return object->second;
    }
    else {
        throw std::runtime_error("There is not Book with such ISBN");
    }
}

void Library::eraseBook(const std::string& ISBN)
{
    if (this->library.find(ISBN) != this->library.end()) {
        this->library.erase(ISBN);
    }
    else {
        std::cout << "There is not Book with such ISBN\n";
    }
}

void Library::viewBooks()
{
    for (const auto& i : this->library) {
        std::cout << i.second << "#########\n";
    }
}

void Library::addAuthor(const std::string& ISBN, const std::string& initAuthor)
{
    if (this->library.find(ISBN) != this->library.end()) {
        auto object = this->library.find(ISBN);
        object->second.addAuthor(initAuthor);
    }
    else {
        throw std::runtime_error("There is not Book with such ISBN");
    }
}

void Library::deleteAuthor(const std::string& ISBN, const std::string& authorToDelete)
{
    if (this->library.find(ISBN) != this->library.end()) {
        auto object = this->library.find(ISBN);
        object->second.deleteAuthor(authorToDelete);
    }
    else {
        throw std::runtime_error("There is not Book with such ISBN");
    }
}

void Library::sortByTitle()
{
    std::vector<Book> books;
    for (const auto& i : this->library) {
        books.push_back(i.second);
    }
    std::sort(books.begin(), books.end(),
    [](const Book& lhs, const Book& rhs){return lhs.getTitle() < rhs.getTitle();});
    std::cout << "Books sorted by Title:\n";
    for (const auto& i : books) {
        std::cout << i << "#########\n";
    }
}