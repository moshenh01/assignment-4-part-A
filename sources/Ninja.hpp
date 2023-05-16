#ifndef Ninja_HPP
#define Ninja_HPP

#include "Point.hpp"
#include <string>
#include "Character.hpp"
class Ninja : public Character {
public:
    Ninja(const Point& location, const std::string& name, int speed,int hitPoints);
    ~Ninja() override = default;
    
    //void setLocation(const Point& location) override;
    virtual void move(Character* enemy);
    virtual void slash(Character* enemy);
    std:: string getType() override{
        return "Ninja";
    }
    std::string print() const override;
    Ninja(const Ninja&) = default; // Copy constructor
    Ninja& operator=(const Ninja&) = default; // Copy assignment operator
    Ninja(Ninja&&) = default; // Move constructor
    Ninja& operator=(Ninja&&) = default; // Move assignment operator
private:
    int m_speed;
};






#endif // Ninja_HPP