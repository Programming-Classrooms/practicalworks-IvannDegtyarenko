/*
	Строки текстового файла input.txt состоят из слов,
	разделенных одним  или несколькими пробелами.
	Перед первым, а также после последнего слова строки пробелы могут отсутствовать.
	Требуется определить слово,
	которое чаще всего встречается в файле.
	Результат вывести на консоль в форме, удобной для чтения
*/


#include <iostream>
#include <fstream>
#include <exception>
#include <string>
#include <cctype>


void checkFile(std::ifstream& file)
{
	if (!file.good())
	{
		throw std::exception("File does not exist.\n");
	}
	if (!file)
	{
		throw std::exception("File is not opened.\n");
	}
	if (file.peek() == EOF)
	{
		throw std::exception("File is empty.\n");
	}
}

bool stringCompare(const std::string& firstString, const std::string& secondString)
{
	if (firstString.length() != secondString.length()) {
		return false;
	}

	size_t bothWordsLength = firstString.length();
	for (size_t i = 0; i < bothWordsLength; ++i) {
		if (std::tolower(firstString[i]) != std::tolower(secondString[i])) {
			return false;
		}
	}
	return true;
}

void checkFrequency(std::ifstream& file, std::string word, size_t& frequency)
{
	std::string tempWord;
	file.seekg(0);
	while (file >> tempWord) {
		if (stringCompare(tempWord, word)) {
			++frequency;
		}
	}
}

std::string mostFrequentWord(std::ifstream& file)
{
	size_t currentFreq = 0;
	size_t maxFreq = 0;
	std::string mostFreqWord = "";
	size_t startPosition = 0;
	std::string word = "";

	while (file >> word) {
		startPosition = file.tellg();
		checkFrequency(file, word, currentFreq);
		if (currentFreq > maxFreq) {
			maxFreq = currentFreq;
			mostFreqWord = word;
			currentFreq = 0;
		}
		else {
			currentFreq = 0;
		}
		file.close();
		file.open("in.txt");
		file.seekg(startPosition);
	}
	return mostFreqWord;
}

int main()
{
	try {
		std::ifstream fileIn("in.txt");
		checkFile(fileIn);
		std::cout << "Most frequent word (or number) is " << mostFrequentWord(fileIn);
		fileIn.close();
	}
	catch (std::exception& error) {
		std::cout << error.what();
		return -1;
	}
	return 0;
}

