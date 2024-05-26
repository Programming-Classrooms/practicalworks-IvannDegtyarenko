#include "../Book/Book.hpp"
#include "../Library/Library.hpp"


int main()
{
    try {
        srand(time(0));
        Book obj("The C++ Programming Language", {"Bjarne Stroustrup"}, 100, 10);
        Book obj2("Effective Modern C++", {"Scott Meyers"}, 150, 5);
        Book obj3("Design Patterns: Elements of Reusable Object-Oriented Software", 
                     {"Erich Gamma", "Richard Helm", "Ralph Johnson", "John Vlissides"}, 200, 7);
        obj.setISBN("1");
        obj2.setISBN("2");
        obj3.setISBN("3");
        
        Library myLib;
        myLib.addBook(obj);
        myLib.addBook(obj2);
        myLib.addBook(obj3);
        myLib.viewBooks();
        myLib.sortByTitle();

        Book j = myLib.findBook("1");
    }
    catch (std::exception& err) {
        std::cerr << "Exception caught: " << err.what() << '\n';
        std::cerr << "Exception type: " << typeid(err).name() << '\n';
    }
    return 0;
}