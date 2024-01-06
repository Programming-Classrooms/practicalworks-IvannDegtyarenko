/*
	Строка состоит из слов, разделенных одним или несколькими
	пробелами. Среди слов, состоящих только из цифр, найти слово, найти
	максимальное и поставить его в начало строки. Если таких слов больше
	одного, взять предпоследнее из них
*/


#include <iostream>
#include <string>
#include <cstring>
#include <exception>

bool isOnlyDigits(std::string number)
{
	size_t length = number.length();
	for (size_t i = 0; i < length; ++i) {
		if (!isdigit(number[i])) {
			return false;
		}
	}
	return true;
}

bool isNextWordHasSameLen(std::string userLine, size_t beginIndex, size_t endIndex, size_t maxLength) 
{
	endIndex = userLine.find_first_of(" ", beginIndex);
	if (endIndex == std::string::npos) {
		return false;
	}
	std::string number = userLine.substr(beginIndex, (endIndex - beginIndex));
	if (isOnlyDigits(number)) {
		size_t currentLength = number.length();
		if (currentLength == maxLength) {
			return true;
		}
		else {
			return false;
		}
	}
	beginIndex = userLine.find_first_not_of(" ", endIndex);
}

void putWordWithMaxLenAtBeg(std::string userLine, std::string& stringNew)
{
	size_t beginIndex = userLine.find_first_not_of(" ");
	size_t endIndex = 0;
	size_t maxLength = 0;
	size_t beginPosition = 0;
	size_t endPosition = 0;
	size_t repeatCounter = 1;

	while (endIndex < userLine.length()) {
		endIndex = userLine.find_first_of(" ", beginIndex);
		if (endIndex == std::string::npos) {
			endIndex = userLine.length();
		}
		std::string number = userLine.substr(beginIndex, (endIndex - beginIndex));
		if (isOnlyDigits(number)) {
			size_t currentLength = number.length();
			if (currentLength > maxLength) {
				maxLength = currentLength;
				beginPosition = beginIndex;
				endPosition = endIndex;
			}
			else {
				if (currentLength == maxLength) {
					if (isNextWordHasSameLen(userLine, beginIndex, endIndex, maxLength)) {
						beginPosition = beginIndex;
						endPosition = endIndex;
					}
				}
			}
		}
		beginIndex = userLine.find_first_not_of(" ", endIndex);
	}

	if (maxLength == 0) {
		throw std::exception("Can't find numbers in the entered line");
	}

	stringNew = userLine.substr(beginPosition, (endPosition - beginPosition));
	userLine.erase(beginPosition, (endPosition - beginPosition));
	stringNew += " ";
	stringNew += userLine;
}

int main()
{
	try {
		std::cout << "Enter your line: ";
		std::string userLine;
		std::getline(std::cin, userLine);
		if (userLine.length() == 0) {
			throw std::exception("Entered line is empty");
		}
		std::string stringNew;
		putWordWithMaxLenAtBeg(userLine, stringNew);
		std::cout << stringNew;
	}
	catch (std::exception& error) {
		std::cout << error.what();
		return -1;
	}
	return 0;
}

