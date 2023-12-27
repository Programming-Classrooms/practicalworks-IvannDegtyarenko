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

bool compareChar(char& firstChar, char& secondChar)
{
	if (firstChar == secondChar)
		return true;
	else if (std::toupper(firstChar) == std::toupper(secondChar))
		return true;
	return false;
}

bool StringCompare(std::string& firstString, std::string& secondString)
{
	return ((firstString.size() == secondString.size()) &&
		std::equal(firstString.begin(), firstString.end(), secondString.begin(), &compareChar));
}

void checkFrequency(std::ifstream& file, std::string word, size_t& frequency)
{
	std::string tempWord;
	file.seekg(0);
	while (file >> tempWord) {
		bool result = StringCompare(tempWord, word);
		if (result) {
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
		file.open("input.txt");
		file.seekg(startPosition);
	}
	return mostFreqWord;
}

int main()
{
	try {
		std::ifstream fileIn("input.txt");
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

