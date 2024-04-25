#include "../functionsFolder/functions.hpp"


int main()
{
    try {
        std::vector<int32_t> numbers;
        fillVector(numbers);
        printVector(numbers);
        std::cout << "Sum of the elements: " << vElemSum(numbers) << '\n';
        std::cout << "Elements amount: " << vElemAmount(numbers) << '\n';
        std::cout << "Elements amount that are EQ to entered: " << elemAmountEQEntered(numbers) << '\n';
        std::cout << "Elements amount that are higher than entered: " << elemAmountCondSatysfy(numbers) << '\n';
        vReplaceZeros(numbers) /*функция, которая заменит элементы равные нулю на общее среднее*/;
        addSumFromInterval(numbers) /*функция, которая добавит ко всем элементам сумму элементов из интервала вектора*/;
        vReplaceEven(numbers) /*функция, которая заменит четные на разность наибольшего и наименьшего*/;
        deleteEQElem(numbers) /*удаляет все одинаковые элементы кроме первого*/;
        printVector(numbers);
    }
    catch (std::exception& err) {
        std::cerr << "Exception caught: " << err.what() << '\n';
        std::cerr << "Exception type: " << typeid(err).name() << '\n';
    }
    return 0;
}