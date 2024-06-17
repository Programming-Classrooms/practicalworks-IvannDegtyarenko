#include <stdexcept>
#include <gtest/gtest.h>

#include "../Library/Library.hpp"


TEST(testBook, testSettersGetters) 
{
    Book testObj("C++", {"Herman", "Norman"}, 56.4, 34);
    EXPECT_EQ(testObj.getTitle(), "C++");
    std::set<std::string> authors = {"Herman", "Norman"};
    EXPECT_EQ(testObj.getAuthors(), authors);
    EXPECT_DOUBLE_EQ(testObj.getPrice(), 56.4);
    EXPECT_EQ(testObj.getCount(), 34);

    testObj.setISBN("434");
    std::set<std::string> newAuthors = {"Some germans above"};
    testObj.setTitle("Result of C++ is D");
    testObj.setAuthors(newAuthors);
    testObj.setPrice(9999.1);
    testObj.setCount(1);

    EXPECT_EQ(testObj.getISBN(), "434");
    EXPECT_EQ(testObj.getTitle(), "Result of C++ is D");
    EXPECT_EQ(testObj.getAuthors(), newAuthors);
    EXPECT_DOUBLE_EQ(testObj.getPrice(), 9999.1);
    EXPECT_EQ(testObj.getCount(), 1);
}

TEST(testBook, testAddingDeletingAuthors)
{
    std::set<std::string> author = {"You"};
    Book testObj("D", {"You"}, 56.4, 5);
    EXPECT_EQ(testObj.getAuthors(), author);

    std::set<std::string> authors = {"You", "Him"};
    testObj.addAuthor("Him");
    EXPECT_EQ(testObj.getAuthors(), authors);

    testObj.deleteAuthor("Him");
    EXPECT_EQ(testObj.getAuthors(), author);
}

TEST(testLibrary, testWorkWithBooks)
{
    Book test1("C++", {"Herman", "Norman"}, 56.4, 34);
    Book test2("A", {"You"}, 56.4, 5);
    test1.setISBN("1");
    test2.setISBN("2");
    Library testLib;

    testLib.addBook(test2);
    testLib.addBook(test1);
    EXPECT_THROW(testLib.findBook("434"), std::runtime_error);
    EXPECT_EQ(testLib.findBook("1").getTitle(), test1.getTitle());
    EXPECT_EQ(testLib.findBook("2").getPrice(), test2.getPrice());

    testLib.eraseBook("1");
    EXPECT_THROW(testLib.findBook("1"), std::runtime_error);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
