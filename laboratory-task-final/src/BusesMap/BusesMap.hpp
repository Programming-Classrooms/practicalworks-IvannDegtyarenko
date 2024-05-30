#ifndef BUSESMAP_HPP
#define BUSESMAP_HPP

#include <map>

#include "../Buses/Buses.hpp"


class BusesMap 
{
private:
    std::multimap<int32_t, Bus> busesMap; //multimap для хранения одинаковых маршрутов в виде ключа
public:
    BusesMap();
    BusesMap(const BusesMap&);

    void fillMap(const std::queue<Bus>& src);
    
    BusesMap& operator=(const BusesMap& src);

    void printAllBusesOnRoute(const int32_t& route); //список автобусов на указанном маршруте
    void printAllDriversOnMark(const BusMarks& mark); //список водителей на указанной марке автобуса

    void deleteBusesByRoute(const int32_t& route); //удаление автобусов по № маршрута

    friend std::ostream& operator<<(std::ostream& out, const BusesMap& src);
    friend std::istream& operator>>(std::istream& in, BusesMap& dest);
};
#endif //BUSESMAP_HPP
