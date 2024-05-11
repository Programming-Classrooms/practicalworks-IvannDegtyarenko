#ifndef TRAIN_HPP
#define TRAIN_HPP

#include <iostream>
#include <fstream>
#include <typeinfo>
#include <stdexcept>
#include <vector>
#include <string>
#include <algorithm>
#include <iomanip>


enum typesOfTrain
{
    Passenger,
    Express,

};

class Train
{
private: 
    size_t trainNumber;
    std::string destination;
    typesOfTrain trainType;
    double departureTime;
    double travelTime;
public:
    Train(size_t = 1, std::string = "Vitebsk", typesOfTrain = typesOfTrain::Express, double = 19.50, double = 23.59);
    ~Train() {}

    size_t getTrainNumber() const;
    std::string getDestination() const;
    typesOfTrain getTrainType() const;
    double getDepartureTime() const;
    double getTravelTime() const;

    void setTrainNumber(size_t);
    void setDestination(std::string);
    void setTrainType(typesOfTrain);
    void setDepartureTime(double);
    void setTravelTime(double);

    friend std::ostream& operator<<(std::ostream&, const Train&);
};
#endif //TRAIN_HPP