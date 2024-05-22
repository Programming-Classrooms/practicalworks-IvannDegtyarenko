#include "functions.hpp"

void checkFile(std::ifstream& file)
{
	if (!file.good())
	{
		throw std::runtime_error("File does not exist.\n");
	}
	if (!file)
	{
		throw std::runtime_error("File is not opened.\n");
	}
	if (file.peek() == EOF)
	{
		throw std::runtime_error("File is empty.\n");
	}
}

void readWords(std::ifstream& fin, std::map<std::string, size_t>& allWords)
{
	std::string line = "";
	std::string delimeters = "!@#$%^&*()-_    =+/.<>,:;{}[]|";
	while (std::getline(fin, line)) {
		std::string::size_type begIndex = line.find_first_not_of(delimeters);
		std::string::size_type endIndex = 0;
		while (endIndex < line.length()) {
			endIndex = line.find_first_of(delimeters, begIndex);
			if (endIndex == std::string::npos) {
				endIndex = line.length();
			}
			std::string word = line.substr(begIndex, (endIndex - begIndex));
			std::string convertWord = word;
			for (size_t i = 0; i < word.length(); ++i) {
				convertWord[i] = std::tolower(word[i]);
			}
			++allWords[convertWord];
			begIndex = line.find_first_not_of(delimeters, endIndex);
		}
		if (fin.peek() == EOF) {
			break;
		}
	}
}

void printInformation(const std::map<std::string, size_t>& rhs)
{
	for (const auto& i : rhs) {
		std::cout << i.first << " " << i.second << '\n';
	}
}
