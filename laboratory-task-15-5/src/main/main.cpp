#include "../classFolder/train.hpp"
#include "../classFolder/functions.hpp"


int main()
{
    try {
        std::vector<Train> trains;
        std::ifstream fileIn("src/files/Trains.txt");
        checkFile(fileIn);
        fillTrainVector(trains, fileIn);
        for (auto i : trains) {
            std::cout << i << "####################\n";
        }
        std::cout << "Trains that will leave at entered time range:\n";
        printTrainsInDepartureTimeRange(trains);
        printTrainsWSDestination(trains);
        printExpressTrainWSDest(trains);
        findFastestTrainWSDest(trains);
    }
    catch (std::exception& err) {
        std::cerr << "Exception caught: " << err.what() << '\n';
        std::cerr << "Exception type: " << typeid(err).name() << '\n';
    }
    return 0;
}