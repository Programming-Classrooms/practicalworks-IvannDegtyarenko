#include "../myString/myString.hpp"
#include <gtest/gtest.h>
#include <stdexcept>

TEST(testConstructors, testDefaultConstructor)
{
    MyString testStr;
    EXPECT_EQ(testStr.getSize(), 0);
}

TEST(testConstructors, testParameterConstructor)
{
    EXPECT_THROW(MyString wrongStr(""), std::invalid_argument);
    MyString testStr("test");
    EXPECT_EQ(testStr.getSize(), 4);
}

TEST(testConstructors, testCopyConstructor)
{
    MyString firstTestStr("red");
    MyString secondTestStr(firstTestStr);

    EXPECT_EQ(firstTestStr.getSize(), secondTestStr.getSize());
    for(size_t i = 0; i < firstTestStr.getSize(); ++i){
        EXPECT_EQ(firstTestStr[i], secondTestStr[i]);
    }
}

TEST(testTransformMethods, testToLower)
{
    MyString str1("red");
    MyString str2("RED");
    for(size_t i = 0; i < str1.getSize(); ++i){
        EXPECT_NE(str1[i], str2[i]);
    }
    str2.toLowerCase();
    for(size_t i = 0; i < str1.getSize(); ++i){
        EXPECT_EQ(str1[i], str2[i]);
    }
}

TEST(testTransformMethods, testToUpper)
{
    MyString str1("red");
    MyString str2("RED");
    for(size_t i = 0; i < str1.getSize(); ++i){
        EXPECT_NE(str1[i], str2[i]);
    }
    str1.toUpperCase();
    for(size_t i = 0; i < str1.getSize(); ++i){
        EXPECT_EQ(str1[i], str2[i]);
    }
}

TEST(testOperators, testIndexingOperator)
{
    MyString str("findItHere");
    EXPECT_THROW(str[56], std::out_of_range);
    EXPECT_NO_THROW(str[3]);
    EXPECT_EQ(str[4], 'I');
    EXPECT_NE(str[0], 'g');
}

TEST(testOperators, testEqualsOperator)
{
    MyString str1("red");
    MyString str2("green");
    EXPECT_NE(str1.getSize(), str2.getSize());
    for(size_t i = 0; i < str1.getSize(); ++i){
        EXPECT_NE(str1[i], str2[i]);
    }
    str1 = str2;
    EXPECT_EQ(str1.getSize(), str2.getSize());
    for(size_t i = 0; i < str1.getSize(); ++i){
        EXPECT_EQ(str1[i], str2[i]);
    }
}

TEST(testOperators, testPlusEQOperator)
{
    MyString testStr("red");
    EXPECT_EQ(testStr.getSize(), 3);
    MyString str1("green");
    testStr += str1;
    EXPECT_NE(testStr.getSize(), 3);
    EXPECT_EQ(testStr.getSize(), 8);
    MyString checkStr("redgreen");
    for(size_t i = 0; i < testStr.getSize(); ++i) {
        EXPECT_EQ(testStr[i], checkStr[i]);
    }
}

TEST(testBoolOperators, testEqualToEqual)
{
    MyString testStr("red");
    MyString checkStr("RED");
    EXPECT_FALSE(testStr == checkStr);
    testStr.toUpperCase();
    EXPECT_TRUE(testStr == checkStr);
}

TEST(testBoolOperators, testLess)
{
    MyString testStr("abc");
    MyString checkStr("abf");
    EXPECT_TRUE(testStr < checkStr);
    MyString anotherCheckString("abb");
    EXPECT_FALSE(testStr < anotherCheckString);
}