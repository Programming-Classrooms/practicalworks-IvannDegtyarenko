#include <stdexcept>
#include <gtest/gtest.h>

#include "../Library/Library.hpp"


TEST(testAuthor, testSettersGetters) 
{
    Author test("Zubenko", "Mikhail", "Petrovich");
    EXPECT_EQ(test.getSurename(), "Zubenko");
    EXPECT_EQ(test.getName(), "Mikhail");
    EXPECT_EQ(test.getFathername(), "Petrovich");

    test.setSurename("1");
    test.setName("Not 1");
    test.setFathername("2 Maybe");

    EXPECT_EQ(test.getSurename(), "1");
    EXPECT_EQ(test.getName(), "Not 1");
    EXPECT_EQ(test.getFathername(), "2 Maybe");
}

TEST(testAuthorsList, testMethods)
{
    AuthorList test;
    Author first("Surename", "Name", "Fathername");
    test.insert(first);
    test.emplace("Why I", "Should Write", "Tests");
    
    EXPECT_TRUE(test.find(first));
    EXPECT_TRUE(test.find(Author("Why I", "Should Write", "Tests")));
    
    test.erase("Surename", "Name", "Fathername");
    EXPECT_FALSE(test.find(first));
}

TEST(testBook, testSettersGetters)
{
    Author first("Surename", "Name", "Fathername");
    AuthorList authors;
    authors.insert(first);
    Book test(434, authors, "Us", 1867);

    EXPECT_EQ(test.getUDC(), 434);
    EXPECT_EQ(test.getAuthors(), authors);
    EXPECT_EQ(test.getBookTitle(), "Us");
    EXPECT_EQ(test.getYearOfPublish(), 1867);

    test.setUDC(42);
    test.setBookTitle("Can't Be");
    test.setYearOfPublish(2023);
    
    EXPECT_EQ(test.getUDC(), 42);
    EXPECT_EQ(test.getAuthors(), authors);
    EXPECT_EQ(test.getBookTitle(), "Can't Be");
    EXPECT_EQ(test.getYearOfPublish(), 2023);
}

TEST(testBook, testAddingErasingAuthor)
{
    AuthorList authors;
    Book test(111, authors, "Tests...", 2024);

    Author first("Surename", "Name", "Fathername");
    test.addAuthor(first);
    test.addAuthor("One Lab", "Was Approved", "Without Tests");
    
    authors.insert(first);
    authors.emplace("One Lab", "Was Approved", "Without Tests");
    EXPECT_EQ(test.getAuthors(), authors);

    test.eraseAuthor("Surename", "Name", "Fathername");
    EXPECT_NE(test.getAuthors(), authors);
    authors.erase("Surename", "Name", "Fathername");
    EXPECT_EQ(test.getAuthors(), authors);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
