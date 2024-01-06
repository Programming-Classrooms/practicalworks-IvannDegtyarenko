/*
	Строка состоит из слов. За один просмотр символов строки найти все
	самые длинные слова и занести их в новую строку. Слова в новой строке
	должны разделяться точкой с запятой и одним пробелом
*/


#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <exception>
#include <cstring>


bool isStringFull(char* string)
{
	bool isFull = true;
	if (strlen(string) == 0) {
		return false;
	}
	for (size_t i = 0; i < strlen(string); ++i) {
		if (isalnum(string[i])) {
			return true;
		}
		else {
			isFull = false;
		}
	}
	if (!isFull) {
		return false;
	}
}

bool checkStream()
{
	if (std::cin.fail()) {
		std::cin.clear();
		std::cin.ignore(32767, '\n');
		return false;
	}
	return true;
}

int getPositiveNumber()
{
	int64_t number = 0;
	std::cin >> number;
	while (!checkStream()) {
		std::cout << "Enter a number instead of the letter: ";
		std::cin >> number;
	}
	while (number <= 0) {
		std::cout << "Wrong value! Enter right: ";
		std::cin >> number;
		if (!checkStream()) {
			continue;
		}
	}
	return number;
}

void maxWordsToNewString(char* string, char* separators, char* newString)
{
	char workString[300];
	strcpy(workString, string);
	size_t maxLength = 0;
	size_t currentLength = 0;
	char* maxWord = strtok(string, separators);
	while (maxWord != NULL) {
		currentLength = strlen(maxWord);
		if (currentLength > maxLength) {
			maxLength = currentLength;
		}
		maxWord = strtok(NULL, separators);
	}
	char* word = strtok(workString, separators);
	while (word != NULL) {
		if (strlen(word) == maxLength) {
			strcat(newString, word);
			strcat(newString, "; ");
		}
		word = strtok(NULL, separators);
	}
}

void getSeparators(char* separators, const size_t maxSize)
{
	std::cout << "\nEnter your own separators: ";
	std::cin.getline(separators, 300);
	for (size_t i = 0; i < strlen(separators); ++i) {
		if (isalnum(separators[i])) {
			throw std::exception("Separators can't contain numbers or letters");
		}
	}
}

int main()
{
	try {
		const size_t maxSize = 300;
		std::cout << "Enter your string: ";
		char userString[maxSize];
		std::cin.getline(userString, 300);
		if (!isStringFull(userString)) {
			throw std::exception("Your string is empty or contains symbols of incorrect input");
		}
		char string[maxSize];
		strcpy(string, userString);
		char separators[maxSize];
		getSeparators(separators, maxSize);
		char newString[maxSize] = "";
		maxWordsToNewString(userString, separators, newString);
		system("cls");
		std::cout << "Your entered line: " << string;
		std::cout << "\nString that contains only words with max length: " << newString;
	}
	catch (std::exception& error) {
		std::cout << error.what();
		return -1;
	}
	return 0;
}

