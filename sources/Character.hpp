#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include "Point.hpp"
#include <iostream>
#include <string>
#include <cmath>
#include <sstream>


class Character {
public:
    Character(const Point& location, const std::string& name, int hitPoints);
    virtual ~Character() = default;

     // Copy constructor
    Character(const Character& other) = default;

     // Copy assignment operator
    Character& operator=(const Character& other) = default;

    // Move constructor
    Character(Character&& other) = default;

    // Move assignment operator
    Character& operator=(Character&& other) = default;
    
    bool isAlive() const;
    double distance(const Character* other) const;
    void hit(int damage);
    const std::string& getName() const;
    const Point& getLocation() const;
    int getHitPoints() const {
        return m_hitPoints;
    }
    void setInTeam(bool team) {
        inTeam = team;
    }
    bool getInTeam()const {
        return inTeam;
    }

    virtual std::string print() const;
    virtual void setLocation(const Point& location);
    virtual std::string getType() {
        return "Character";
    }
    private:
    Point m_location;
    std::string m_name;
    int m_hitPoints;
    bool inTeam = false;
};

#endif // CHARACTER_HPP