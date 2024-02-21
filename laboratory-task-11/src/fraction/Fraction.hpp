#ifndef MYSTRING_HPP
#define MYSTRING_HPP
#define _CRT_SECURE_NO_WARNINGS
#include <string>
#include <iostream>
#include <cstring>
#include <cctype>

class MyString
{
private:
    size_t size;
    char* myString;
public:
    MyString();
    MyString(const char*);
    MyString(const MyString&);
    ~MyString();
    size_t getSize() const;
    void printString();
    const char* getCString() const;
    void toLowerCase();
    void toUpperCase();
    char& operator[](int);
    MyString& operator=(const MyString& right);
    MyString& operator+=(const MyString& right);
    bool operator==(const MyString&);
    friend std::istream& operator>>(std::istream& in, MyString& right);
    friend std::ostream& operator<<(std::ostream& out, const MyString& right);
};

#endif
