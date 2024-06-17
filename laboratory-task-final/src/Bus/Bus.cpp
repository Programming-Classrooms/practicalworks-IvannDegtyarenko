#include "Bus.hpp"

Bus::Bus() //конструктор по умолчанию
    :   routeNumber(1), 
    driver("Vitalya"), 
    busNumber(1), 
    busMark(BusMarks::KAMAZ)
{}

Bus::Bus(
    int32_t initRouteNum, 
    std::string initDriver, 
    int32_t initBusNum, 
    BusMarks initBusMark
) : busMark(initBusMark) //конструктор с параметрами
{
    if (initRouteNum < 0) {
        throw std::invalid_argument("Wrong input Route Number for Bus. Value is under zero");
    }
    this->routeNumber = initRouteNum;
    if (initDriver.length() == 0) {
        throw std::runtime_error("Wrong input Driver for Bus. String is empty");
    }
    this->driver = initDriver;
    if (initBusNum < 0) {
        throw std::invalid_argument("Wrong input Bus Number for Bus. Value is under zero");
    }
    this->busNumber = initBusNum;
}

Bus::Bus(const Bus& src) //конструктор копирования
    : routeNumber(src.routeNumber), 
    driver(src.driver), 
    busNumber(src.busNumber),
    busMark(src.busMark)
{}

int32_t Bus::getRouteNumber() const //получение номера маршрута
{
    int32_t safe = this->routeNumber;
    return safe;
}

std::string Bus::getBusDriver() const //получение имени/фамилии водителя
{
    std::string safe = this->driver;
    return driver;
}

int32_t Bus::getBusNumber() const //получение номера автобуса
{
    int32_t safe =this->busNumber;
    return safe;
}

BusMarks Bus::getBusMark() const //получение марки автобуса
{
    BusMarks safe = this->busMark;
    return safe;
}

void Bus::setRouteNumber(int32_t init) //установка нового номера маршрута
{
    if (init < 0) {
        throw std::invalid_argument("Wrong input Route Number for Bus. Value is under zero");
    }
    this->routeNumber = init;
}

void Bus::setBusDriver(std::string init) //установка нового водителя автобуса
{
    if (init.length() == 0) {
        throw std::runtime_error("Wrong input Driver for Bus. String is empty");
    }
    this->driver = init;
}

void Bus::setBusNumber(int32_t init) //установка нового номера автобуса 
{
    if (init < 0) {
        throw std::invalid_argument("Wrong input Bus Number for Bus. Value is under zero");
    }
    this->busNumber = init;
}

void Bus::getBusMark(BusMarks init) //установка новой марки автобуса
{
    this->busMark = init;
}

Bus& Bus::operator=(const Bus& src) //перегрузка оператора присваивания
{
    if (this != &src) {
        this->routeNumber = src.routeNumber;
        this->driver = src.driver;
        this->busNumber = src.busNumber;
        this->busMark = src.busMark;
    }
    return *this;
}

bool Bus::operator==(const Bus &rhs)
{
    return this->routeNumber == rhs.routeNumber &&
    this->driver == rhs.driver &&
    this->busNumber == rhs.busNumber &&
    this->busMark == rhs.busMark;
}

bool Bus::operator<(const Bus &rhs)
{
    if (this->routeNumber != rhs.routeNumber) {
        return this->routeNumber < rhs.routeNumber;
    }
    else {
        if (this->driver != rhs.driver) {
            return this->driver < rhs.driver;
        }
        else {
            if (this->busNumber != rhs.busNumber) {
                return this->busNumber < rhs.busNumber;
            }
            else {
                if (this->busMark != rhs.busMark) {
                    return this->busMark < rhs.busMark;
                }
            }
        }
    }
    return false;
}

std::ostream& operator<<(std::ostream& out, const Bus& src) //перегрузка оператора для вывода
{
    out << "Bus Route Number: " << src.routeNumber << '\n';
    out << "Bus Driver: " << src.driver << '\n';
    out << "Bus Number: " << src.busNumber << '\n';
    switch (src.busMark)
    {
    case BusMarks::MAN:
        out << "Bus Mark : MAN\n";
        out << "###################\n";
        break;
    case BusMarks::MAZ:
        out << "Bus Mark : MAZ\n";
        out << "###################\n";
        break;
    case BusMarks::KAMAZ:
        out << "Bus Mark : KAMAZ\n";
        out << "###################\n";
        break;
    }
    return out;
}

std::istream &operator>>(std::istream &in, Bus &dest) //перегрузка оператора для ввода
{
    std::string line = "";
    std::getline(in, line);

    std::string::size_type begIndex = line.find_first_not_of(" ");
    std::string::size_type endIndex = line.find_first_of(" ", begIndex);
    dest.routeNumber = std::stoi(line.substr(begIndex, endIndex - begIndex)); //получение из файла номера маршрута

    begIndex = line.find_first_not_of(" ", endIndex);
    endIndex = line.find_first_of(" ", begIndex);
    dest.driver = line.substr(begIndex, endIndex - begIndex); //получение из файла имени/фамилии водителя
    
    begIndex = line.find_first_not_of(" ", endIndex);
    endIndex = line.find_first_of(" ", begIndex);
    dest.busNumber = std::stoi(line.substr(begIndex, endIndex - begIndex)); //получение из файла номера автобуса
    
    begIndex = line.find_first_not_of(" ", endIndex);
    endIndex = line.find_first_of(" ", begIndex);
    std::string mark = line.substr(begIndex, endIndex - begIndex); //получение из файла марки автобуса

    if (mark == "Маз") {
        dest.busMark = BusMarks::MAZ;
    }
    else {
        if (mark == "Ман") {
            dest.busMark = BusMarks::MAN;
        }
        else {
            if (mark == "Камаз") {
                dest.busMark = BusMarks::KAMAZ;
            }
        }
    }
    return in;
}
