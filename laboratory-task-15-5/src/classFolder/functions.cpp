#include "functions.hpp"

void checkFile(std::ifstream& file)
{
    if (!file.good()) {
        throw std::runtime_error("File does not exist!");
    }
    if (!file) {
        throw std::runtime_error("File is not opened!");
    }
    if (file.peek() == EOF) {
        throw std::runtime_error("File is empty!");
    }
}

void fillTrainVector(std::vector<Train>& vector, std::ifstream& file)
{
    size_t trainNumber = 1;
    std::string destination = "Vitebsk", trainType = "Express";
    double departureTime = 0.0, travelTime = 0.0;
    while (file >> trainNumber) {
        file >> destination >> trainType >> departureTime >> travelTime;
        if (trainType == "Express") {
        vector.push_back(Train(trainNumber, destination, typesOfTrain::Express, departureTime, travelTime));
    }
    else if (trainType == "Passenger") {
        vector.push_back(Train(trainNumber, destination, typesOfTrain::Passenger, departureTime, travelTime));
    }
    else {
        continue;
    }    
    }
    std::sort(vector.begin(), vector.end(), [](const Train& lhs, const Train& rhs){return lhs.getDepartureTime() < rhs.getDepartureTime();});
}

void printTrainsInDepartureTimeRange(const std::vector<Train>& vector)
{
    double leftTimeBound = 0.0, rightTimeBound = 0.0;
    bool isTrain = false;
    std::cout << "Enter left bound for departure time range: ";
    leftTimeBound = getRightTime();
    std::cout << "Enter right bound for departure time range: ";
    rightTimeBound = getRightTime();
    if (rightTimeBound < leftTimeBound) {
        std::swap(rightTimeBound, leftTimeBound);
    }
    for (auto i : vector) {
        if (i.getDepartureTime() >= leftTimeBound && i.getDepartureTime() <= rightTimeBound) {
            std::cout << i << "#############\n"; 
            isTrain = true;
        }
    }
    if (!isTrain) {
        std::cout << "There are not any trains that leave at the entered time range\n";
    }
}

double getRightTime()
{
    double time = 0.0;
    std::cin >> time;
    while (time < 0.0 || time > 23.59 || (time - static_cast<int>(time)) > 0.59) {
        std::cout << "Wrong input! Wrong time input in 24h system. Enter right value: ";
        std::cin >> time;
    }
    return time;
}

void printTrainsWSDestination(const std::vector<Train>& vector)
{
    bool isTrain = false;
    std::string destination = "";
    std::cout << "Enter destination to find trains that has it: ";
    std::cin >> destination;
    while (destination.length() == 0) {
        std::cout << "Wrong input. Empty string. Try again: ";
        std::cin >> destination;
    }
    std::cout << "Trains with " << destination << " destination:\n"; 
    for (auto i : vector) {
        if (i.getDestination() == destination) {
            std::cout << i << "###################\n";
            isTrain = true;
        }
    }
    if (!isTrain) {
        std::cout << "There are not any trains that travel to the entered destination\n";
    }
}

void printExpressTrainWSDest(const std::vector<Train>& vector)
{
    bool isTrain = false;
    std::string destination = "";
    std::cout << "Enter destination to find Express Trains that has it: ";
    std::cin >> destination;
    while (destination.length() == 0) {
        std::cout << "Wrong input. Empty string. Try again: ";
        std::cin >> destination;
    }
    std::cout << "Exprees Trains with " << destination << " destination:\n"; 
    for (auto i : vector) {
        if (i.getDestination() == destination && i.getTrainType() == typesOfTrain::Express) {
            std::cout << i << "###################\n";
            isTrain = true;
        }
    }
    if (!isTrain) {
        std::cout << "There are not any Express Trains that travel to the entered destination\n";
    }
}

void findFastestTrainWSDest(const std::vector<Train>& vector)
{
    Train fastestTrain;
    bool isTrain = false;
    std::string destination = "";
    std::cout << "Enter destination to find The Fastest train to it: ";
    std::cin >> destination;
    while (destination.length() == 0) {
        std::cout << "Wrong input. Empty string. Try again: ";
        std::cin >> destination;
    }
    for (auto i : vector) {
        if (i.getDestination() == destination && i.getTravelTime() < fastestTrain.getTravelTime()) {
            fastestTrain = i;
            isTrain = true;
        }
    }
    if (!isTrain) {
        std::cout << "There are not any Trains that travel to the entered destination\n";
    }
    else{
        std::cout << "Fastest Train to the " << destination << ":\n" << fastestTrain;
    }
}