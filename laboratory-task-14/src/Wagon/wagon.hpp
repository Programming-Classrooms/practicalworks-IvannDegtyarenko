#ifndef WAGON_HPP
#define WAGON_HPP

#include <iostream>
#include <string>


class Wagon {
private:
    std::string color;
public:
    Wagon() = default;
    Wagon(std::string);
    Wagon(const Wagon&);
    ~Wagon() {}

    Wagon& operator=(const Wagon&);
    Wagon& operator=(std::string);

    std::string getColor() const;

    void setColor(std::string);

    friend std::ostream& operator<<(std::ostream&, const Wagon&);
};
#endif //WAGON_HPP
