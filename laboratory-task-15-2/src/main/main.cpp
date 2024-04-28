#include "../functionsFolder/functions.hpp"


int main()
{
    try {
        std::ifstream fileIn("src/files/strings.txt");
        checkFile(fileIn);
        std::vector<std::string> text;
        fillVector(fileIn, text);
        printVector(text);
        char startSymbol = '\0';
        std::cout << "Enter a symbol to find words that start from it and delete them: ";
        std::cin >> startSymbol;
        deleteWordsWithStartSymbol(text, startSymbol);
        printVector(text);
    }
    catch (std::exception& err) {
        std::cerr << "Exception caught: " << err.what() << '\n';
        std::cerr << "Exception type: " << typeid(err).name() << '\n';
    }
    return 0;
}