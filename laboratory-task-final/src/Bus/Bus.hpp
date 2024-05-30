#ifndef BUS_HPP
#define BUS_HPP

#include <iostream>
#include <string>
#include <fstream>
#include <typeinfo>
#include <stdexcept>


enum class BusMarks
{
    MAZ,
    MAN,
    KAMAZ,

}; //enum-класс для марок автобуса

class Bus {
private:
    int32_t routeNumber;
    std::string driver;
    int32_t busNumber;
    BusMarks busMark;
public:
    Bus(); //конструктор по умолчанию
    Bus(
        int32_t initRouteNum, 
        std::string initDriver,
        int32_t initBusNum, 
        BusMarks initBusMark
    ); //конструктор с параметрами
    Bus(const Bus&); //конструктор копирования
    ~Bus() {} //деструктор

    int32_t getRouteNumber() const; //получение номера маршрута
    std::string getBusDriver() const; //получение имени/фамилии водителя
    int32_t getBusNumber() const; //получение номера автобуса
    BusMarks getBusMark() const; //получение марки автобуса

    void setRouteNumber(int32_t init); //установка нового номера маршрута
    void setBusDriver(std::string init); //установка нового водителя автобуса
    void setBusNumber(int32_t init); //установка нового номера автобуса 
    void getBusMark(BusMarks init); //установка новой марки автобуса

    Bus& operator=(const Bus& src); //перегрузка оператора присваивания

    bool operator==(const Bus& rhs);
    bool operator<(const Bus& rhs);

    friend std::ostream& operator<<(std::ostream& out, const Bus& src); //перегрузка оператора для вывода
    friend std::istream& operator>>(std::istream& in, Bus& dest); //перегрузка оператора для ввода
};
#endif //BUS_HPP
