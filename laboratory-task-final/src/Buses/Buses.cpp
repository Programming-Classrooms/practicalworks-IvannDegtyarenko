#include "Buses.hpp"

Buses::Buses() : buses(std::queue<Bus>()) //конструктор по умолчанию
{}

Buses::Buses(const Buses& src) : buses(src.buses) //конструктор копирования
{}

Buses &Buses::operator=(const Buses& src) //перегрузка оператора присваивания
{
    if (this != &src) {
        this->buses = src.buses;
    }
    return *this;
}

std::queue<Bus> Buses::getBuses() const
{
    std::queue<Bus> safe = this->buses;
    return safe;
}

void Buses::sortByBusNumber() //сортировка по № автобуса
{
    std::vector<Bus> busesForSort;
    std::queue<Bus> temp = this->buses;
    while (!temp.empty()) {
        busesForSort.push_back(temp.front());
        temp.pop();
    }
    std::sort(busesForSort.begin(), busesForSort.end(),
    [](const Bus& lhs, const Bus& rhs)
    {return lhs.getBusNumber() < rhs.getBusNumber();});

    for(const auto& i : busesForSort) {
        std::cout << i;
    }
}

void Buses::sortByBusRouteNumber() //сортировка по № маршрута
{
    std::vector<Bus> busesForSort;
    std::queue<Bus> temp = this->buses;
    while (!temp.empty()) {
        busesForSort.push_back(temp.front());
        temp.pop();
    }
    std::sort(busesForSort.begin(), busesForSort.end(),
    [](const Bus& lhs, const Bus& rhs)
    {return lhs.getRouteNumber() < rhs.getRouteNumber();});
    
    for(const auto& i : busesForSort) {
        std::cout << i;
    }
}

std::ostream& operator<<(std::ostream &out, const Buses &src) //перегрузка оператора для вывода
{
    std::queue<Bus> temp = src.buses;
    while (!temp.empty()) {
        out << temp.front();
        temp.pop();
    }
    return out;
}

std::istream& operator>>(std::istream &in, Buses &dest) //перегрузка оператора для ввода
{
    Bus temp;
    while (in >> temp) {
        dest.buses.push(temp);
        if (in.peek() == EOF) {
            break;
        }
    }
    return in;
}
