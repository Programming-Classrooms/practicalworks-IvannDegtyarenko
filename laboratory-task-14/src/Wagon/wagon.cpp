#include "wagon.hpp"

Wagon::Wagon(std::string initColor) : color(initColor)
{}

Wagon::Wagon(const Wagon& src) : color(src.color)
{}

Wagon& Wagon::operator=(const Wagon& src)
{
    if (this != &src) {
        this->color = src.color;
    }
    return *this;
}

std::string Wagon::getColor() const
{
    std::string safe = this->color;
    return safe;
}

void Wagon::setColor(std::string src)
{
    this->color = src;
}

std::ostream& operator<<(std::ostream& out, const Wagon& src)
{
    out << "Wagon color:" << src.color;
    return out;
}
