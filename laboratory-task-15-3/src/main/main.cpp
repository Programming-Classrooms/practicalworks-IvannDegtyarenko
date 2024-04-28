#include "../functionsFolder/functions.hpp"


int main()
{
    try {
        srand(time(NULL));
        std::cout << "Enter the number of rows for matrix: ";
		size_t rows = getPositiveNumber();
		std::cout << "Enter the number of columns for matrix: ";
		size_t columns = getPositiveNumber();
        std::vector<std::vector<int>> mtrx(rows, std::vector<int>(columns));
        int64_t leftBoundary = 0, rightBouandary = 0;
        getBoundaries(leftBoundary, rightBouandary);
        fillMtrx(mtrx, leftBoundary, rightBouandary);
        printMtrx(mtrx);
        eraseRowColWithMaxElem(mtrx);
        printMtrx(mtrx);
        sortMtrx(mtrx);
        printMtrx(mtrx);
    }
    catch (std::exception& err) {
        std::cerr << "Exception caught: " << err.what() << '\n';
        std::cerr << "Exception type: " << typeid(err).name() << '\n';
    }
}