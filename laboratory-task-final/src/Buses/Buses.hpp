#ifndef BUSES_HPP
#define BUSES_HPP

#include <queue>
#include <algorithm>

#include "../Bus/Bus.hpp"


class Buses {
protected:
    std::queue<Bus> buses;
public:
    Buses(); //конструктор по умолчанию
    Buses(const Buses& src); //конструктор копирования
    ~Buses() = default; //деструктор

    Buses& operator=(const Buses& src); //перегрузка оператора присваивания

    std::queue<Bus> getBuses() const;

    void sortByBusNumber(); //сортировка по № автобуса
    void sortByBusRouteNumber(); //сортировка по № маршрута

    friend std::ostream& operator<<(std::ostream& out, const Buses& src); //перегрузка оператора для вывода
    friend std::istream& operator>>(std::istream& in, Buses& dest); //перегрузка оператора для ввода
};
#endif //BUSES_HPP
