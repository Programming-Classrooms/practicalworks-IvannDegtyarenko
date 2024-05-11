#include "train.hpp"

Train::Train(
    size_t initNumber, 
    std::string initDestination, 
    typesOfTrain initType, 
    double initDeparture, 
    double initTravel
) : trainNumber(initNumber), trainType(initType)
{
    if (initDestination.length() == 0) {
        throw std::invalid_argument("Wrong input! String is empty");
    }
    destination = initDestination;
    if (initDeparture < 0.0 || initDeparture > 23.59) {
        throw std::invalid_argument("Wrong input! Wrong time input in 24h system");
    }
    if ((initDeparture - static_cast<int>(initDeparture)) > 0.59) {
        throw std::invalid_argument("Wrong input! Wrong time input in minutes");
    }
    departureTime = initDeparture;
    if (initTravel < 0.0 || initTravel > 23.59) {
        throw std::invalid_argument("Wrong input! Wrong time input in 24h system");
    }
    if ((initTravel - static_cast<int>(initTravel)) > 0.59) {
        throw std::invalid_argument("Wrong input! Wrong time input in minutes");
    }
    travelTime = initTravel;
}

size_t Train::getTrainNumber() const
{
    size_t safe = this->trainNumber;
    return safe;
}

std::string Train::getDestination() const
{
    std::string safe = this->destination;
    return safe;
}

typesOfTrain Train::getTrainType() const
{
    typesOfTrain safe = this->trainType;
    return safe;
}

double Train::getDepartureTime() const
{
    double safe = this->departureTime;
    return safe;
}

double Train::getTravelTime() const
{
    double safe = this->travelTime;
    return safe;
}

void Train::setTrainNumber(size_t init)
{
    this->trainNumber = init;
}

void Train::setDestination(std::string init)
{
    if (init.length() == 0) {
        throw std::invalid_argument("Wrong input! String is empty");
    }
    this->destination = init;
}

void Train::setTrainType(typesOfTrain init)
{
    this->trainType = init;
}

void Train::setDepartureTime(double init)
{
    if (init < 0.0 || init > 23.59) {
        throw std::invalid_argument("Wrong input! Wrong time input in 24h system");
    }
    if ((init - static_cast<int>(init)) > 0.59) {
        throw std::invalid_argument("Wrong input! Wrong time input in minutes");
    }
    this->departureTime = init;
}

void Train::setTravelTime(double init)
{
    if (init < 0.0 || init > 23.59) {
        throw std::invalid_argument("Wrong input! Wrong time input in 24h system");
    }
    if ((init - static_cast<int>(init)) > 0.59) {
        throw std::invalid_argument("Wrong input! Wrong time input in minutes");
    }
    this->travelTime = init;
}

std::ostream &operator<<(std::ostream & out, const Train& rhs)
{
    out << "Train Number: " << rhs.trainNumber << '\n';
    out << "Train Destination: " << rhs.destination << '\n';
    if (rhs.trainType == typesOfTrain::Express) {
        out << "Train Type: Express\n";
    }
    else {
        out << "Train Type: Passenger\n";
    }

    out << "Train leaves at " << (static_cast<int>(rhs.departureTime)) << ":";
    if (rhs.departureTime - static_cast<int>(rhs.departureTime) == 0.0) {
        out << "00\n";
    }
    else {
        out << ((rhs.departureTime - static_cast<int>(rhs.departureTime))*100) << '\n';
    }
    
    out << "Train travel time will be " << (static_cast<int>(rhs.travelTime)) << ":";
    if (rhs.travelTime - static_cast<int>(rhs.travelTime) < 0.10) {
        out << "0" << ((rhs.travelTime - static_cast<int>(rhs.travelTime))*100) << '\n';
    }
    else  if (rhs.travelTime - static_cast<int>(rhs.travelTime) == 0.0) {
        out << "00\n";
    }
    else {
        out << ((rhs.travelTime - static_cast<int>(rhs.travelTime))*100) << '\n';
    }
    return out;
}
