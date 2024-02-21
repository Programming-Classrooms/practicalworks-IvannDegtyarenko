#include "Fraction.hpp"
#include <iostream>
#include <cstring>
#include <cctype>
#define _CRT_SECURE_NO_WARNINGS

MyString::MyString() {
	myString = nullptr;
	size = 0;
}

MyString::MyString(const char* string) {
	size = strlen(string);
	if (size == 0) {
		throw std::invalid_argument("Wrong value of size");
	}
	std::cout << "constructor\n";
	myString = new char[size + 1];
	strcpy(myString, string);
}

MyString::MyString(const MyString& string) {
	std::cout << "constructor of copy\n";
	size = string.size;
	myString = new char[size + 1];
	strcpy(myString, string.myString);
}

MyString::~MyString() {
	std::cout << "destructor\n";
	delete[] myString;
}

size_t MyString::getSize() const
{
	return size;
}

const char* MyString::getCString() const
{
	return myString;
}

MyString& MyString::operator=(const MyString& right) {
	if (this != &right) {
		delete[] myString;
		size = right.size;
		myString = new char[size + 1];
		strcpy(myString, right.myString);
	}
	return *this;
}

MyString& MyString::operator+=(const MyString& right) {
	char* temp = myString;
	size += right.size;
	myString = new char[size + 1];
	strcpy(myString, temp);
	strcat(myString, right.myString);
	delete[] temp;
	return *this;
}

std::istream& operator>>(std::istream& in, MyString& right) {
	char temp[2024];
	in.getline(temp, 2024);
	delete[] right.myString;
	right.size = strlen(temp);
	right.myString = new char[right.size + 1];
	strcpy(right.myString, temp);
	return in;
}

void MyString::toLowerCase() {
	for (size_t i = 0; i < size; ++i) {
		myString[i] = tolower(myString[i]);
	}
}

void MyString::toUpperCase() {
	for (size_t i = 0; i < size; ++i) {
		myString[i] = toupper(myString[i]);
	}
}

std::ostream& operator<<(std::ostream& out, const MyString& right) {
	out << right.myString;
	out << '\n';
	return out;
}

char& MyString::operator[](int index) {
	if (index < 0 || index >= size) {
		throw::std::out_of_range("Wrong index\n");
	}
	return myString[index];
}

void MyString::printString() {
	std::cout << this->myString << '\n';
}

bool MyString::operator==(const MyString& string) {
	if (strcmp(this->myString, string.myString)) {
		return false;
	}
	else {
		return true;
	}
}
