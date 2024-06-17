#include <typeinfo>

#include "../functions/functions.hpp"


int main()
{
    try {
        std::string pathToSurenames = "src/info/strings.txt";
		std::string pathToNumbers = "src/info/numbers.txt";
		std::string pathToOutInTxt = "src/info/result.txt";
		std::string pathToOutInBin = "src/info/result.bin";

		std::string delimsToSurenames = getDelimiters(pathToSurenames);
		std::string textToSureNames = getMainText(pathToSurenames);
		size_t sizeArrToSurename = getSizeForArrSurenames(textToSureNames, delimsToSurenames);
		std::string* allSurenames = new std::string[sizeArrToSurename];

		if (sizeArrToSurename == 0) {
			std::cout << "Task not have solution..." << std::endl;
		}
		else {

			fillingArr(allSurenames, textToSureNames, delimsToSurenames);
			printArr(allSurenames, sizeArrToSurename);
			qsortString(allSurenames, 0, sizeArrToSurename - 1);
			printArr(allSurenames, sizeArrToSurename);

			std::string delimToNumber = getDelimiters(pathToNumbers);
			std::string textToNumbers = getMainText(pathToNumbers);
			size_t sizeArrToNumbers = getSizeForArrNumbers(textToNumbers, delimToNumber);
			int32_t* allNumbers = new int32_t[sizeArrToNumbers];
			int32_t* allSortNumbers = new int32_t[sizeArrToNumbers];

			if (sizeArrToNumbers == 0) {
				std::cout << "Task have not solution...";
			}
			else {
				fillingArr(allNumbers, textToNumbers, delimToNumber);
				printArr(allNumbers, sizeArrToNumbers);
				copySortArrays(allNumbers, allSortNumbers, sizeArrToNumbers);
				printArr(allSortNumbers, sizeArrToNumbers);
			}

			Employee* employees = new Employee[sizeArrToSurename];
			fillingArrOfStruct(employees, allNumbers, allSurenames, sizeArrToSurename, sizeArrToNumbers);

			printArr(employees, sizeArrToSurename);
			menu(employees, sizeArrToSurename);
			printArr(employees, sizeArrToSurename);

			std::cout << "##########" << std::endl;

			printArr(employees, sizeArrToSurename);
			std::ofstream foutStuctTxt(pathToOutInTxt);	

			writeArrOfStruct(foutStuctTxt, employees, sizeArrToSurename);

			foutStuctTxt.close();

			std::ofstream foutToStruct(pathToOutInBin, std::ios::binary);

			writeArrOfStructToBin(foutToStruct, employees, sizeArrToSurename);

			foutToStruct.close();

			std::ifstream fin(pathToOutInBin, std::ios::binary);

			Employee employeeLast, employeeFirst;
			size_t pointerToLast = getPointerLast(fin, employeeLast, employeeFirst);
			fin.close();

			std::ofstream fout(pathToOutInBin, std::ios::binary | std::ios::app);
			swapLinesInBinaryFile(fout, pointerToLast, employeeLast, employeeFirst);
			fout.close();

			delete[] employees;
			delete[] allSortNumbers;
			delete[] allNumbers;
			delete[] allSurenames;
        }
    }
    catch (std::exception& err) {
        std::cerr << "Exception caught: " << err.what() << '\n';
        std::cerr << "Exception type: " << typeid(err).name() << '\n';
    }
    return 0;
}
