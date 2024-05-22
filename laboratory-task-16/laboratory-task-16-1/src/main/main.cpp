#include "../Library/library.hpp"


void checkFile(std::ifstream& file)
{
    if (!file.good()) {
        throw std::runtime_error("File does not exist!");
    }
    if (!file) {
        throw std::runtime_error("File is not opened!");
    }
    if (file.peek() == EOF) {
        throw std::runtime_error("File is empty!");
    }
}

int main()
{
    try {
        std::ifstream fin("src/info/books.txt");
        checkFile(fin);

        Library myLibrary;
        Book insertBook;
        while (fin >> insertBook) {
            myLibrary.insertBook(insertBook);
            insertBook.clear();
            if (fin.peek() == EOF) {
                break;
            }
        }
        std::cout << myLibrary;
    }
    catch (std::exception& err) {
        std::cerr << "Exception caught: " << err.what() << '\n';
        std::cerr << "Exception type: " << typeid(err).name() << '\n';
    }
    return 0;
}
