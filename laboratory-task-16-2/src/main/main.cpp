#include "../functions/functions.hpp"

int main()
{
    try {
        std::ifstream fin("src/info/data.txt");
        checkFile(fin);
        std::map<std::string, size_t> allWords;
        readWords(fin, allWords);
        printInformation(allWords);
    }
    catch (std::exception& err) {
        std::cerr << "Exception caught: " << err.what() << '\n';
        std::cerr << "Type of exception: " << typeid(err).name() << '\n';
    }
    return 0;
}
