#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include "Point.hpp"
#include <iostream>
#include <string>
#include <cmath>


class Character {
public:
    Character(const Point& location, const std::string& name, int hitPoints);
    virtual ~Character();

    bool isAlive() const;
    double distance(const Character* other) const;
    void hit(int damage);
    const std::string& getName() const;
    const Point& getLocation() const;

    virtual std::string& print() const;
    virtual void setLocation(const Point& location);
    protected:
    Point m_location;
    std::string m_name;
    int m_hitPoints;
};

#endif // CHARACTER_HPP