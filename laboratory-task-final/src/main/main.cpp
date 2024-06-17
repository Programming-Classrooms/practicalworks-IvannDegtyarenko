#include "../BusesMap/BusesMap.hpp"


void checkFile(std::ifstream& file)
{
    if (!file.good()) {
        throw std::runtime_error("File does not open");
    }
    if (!file) {
        throw std::runtime_error("File is not exist");
    }
    if (file.peek() == EOF) {
        throw std::runtime_error("File is empty");
    }
}

int main()
{
    try {
        std::ifstream fin("src/info/buses.txt");
        checkFile(fin);
        Buses allBuses;
        fin >> allBuses;
        std::cout << "Presenting all Buses:\n";
        std::cout << allBuses;
        allBuses.sortByBusRouteNumber();

        BusesMap myMapBuses;
        std::queue<Bus> temp = allBuses.getBuses();
        myMapBuses.fillMap(temp);
        std::cout << "All Buses on Route 100:\n";
        myMapBuses.printAllBusesOnRoute(100);
        std::cout << "All Drivers on Bus Mark: Maz\n";
        myMapBuses.printAllDriversOnMark(BusMarks::MAZ);

        myMapBuses.deleteBusesByRoute(100);
    }
    catch (std::exception& err) {
        std::cerr << "Exception caught: " << err.what() << '\n';
        std::cerr << "Type of caughted exception: " << typeid(err).name() << '\n';
    }
    return 0;
}
//Плаки-плаки или нармалдаки
