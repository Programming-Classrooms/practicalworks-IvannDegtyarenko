#include "../functionsFolder/functions.hpp"


int main()
{
    try {
        std::vector<int32_t> numbers;
        fillVector(numbers);
        printVector(numbers);
        std::cout << "Sum of the elements: " << vElemSum(numbers) << '\n';
        std::cout << "Elements amount: " << vElemAmount(numbers) << '\n';
        //std::cout << elemAmountEQEntered(numbers) << '\n';
        //std::cout << elemAmountCondSatysfy(numbers) << '\n';
        //vReplaceZeros(numbers);
        //addSumFromInterval(numbers);
        //vReplaceEven(numbers);
        deleteEQElem(numbers);
        printVector(numbers);
    }
    catch (std::exception& err) {
        std::cerr << "Exception caught: " << err.what() << '\n';
        std::cerr << "Exception type: " << typeid(err).name() << '\n';
    }
    return 0;
}