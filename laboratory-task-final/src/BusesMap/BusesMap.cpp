#include "BusesMap.hpp"

BusesMap::BusesMap() : busesMap(std::multimap<int32_t, Bus>()) 
{}

BusesMap::BusesMap(const BusesMap& src) : busesMap(src.busesMap)
{}

void BusesMap::fillMap(const std::queue<Bus>& src)
{
    std::queue<Bus> temp = src;
    while (!temp.empty()) {
        this->busesMap.insert(std::pair<int32_t, Bus>(temp.front().getRouteNumber(), temp.front()));
        temp.pop();
    }
}

BusesMap &BusesMap::operator=(const BusesMap& src)
{
    if (this != &src) {
        this->busesMap = src.busesMap;
    }
    return *this;
}

void BusesMap::printAllBusesOnRoute(const int32_t& route)
{
    for (const auto& i : this->busesMap) {
        if (i.first == route) {
            std::cout << i.second;
        }
    }
}

void BusesMap::printAllDriversOnMark(const BusMarks& mark)
{
    for (const auto& i : this->busesMap) {
        if (i.second.getBusMark() == mark) {
            std::cout << i.second.getBusDriver() << " ";
        }
    }
}

void BusesMap::deleteBusesByRoute(const int32_t& route)
{
    auto item = this->busesMap.find(route);
    if (item == this->busesMap.end()) {
        std::cout << "No such routes!";
    }
    while (item != this->busesMap.end()) {
        this->busesMap.erase(item);
        item = this->busesMap.find(route);
    }
}

std::ostream& operator<<(std::ostream& out, const BusesMap &src)
{
    for (const auto& i : src.busesMap) {
        out << "Bus Route: " << i.first << '\n';
        out << "Bus on this Route: " << i.second;
    }
    return out; 
}

std::istream &operator>>(std::istream& in, BusesMap &dest)
{
    Buses temp;
    in >> temp;
    std::queue<Bus> init = temp.getBuses();
    dest.fillMap(init);
    return in;
}
