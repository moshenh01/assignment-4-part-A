#ifndef Coboy_HPP
#define Coboy_HPP
#include "Point.hpp"
#include <string>
#include "Character.hpp"

class Cowboy : public Character {
public:
    Cowboy( const std::string& name,const Point& location);
    ~Cowboy() override = default;
    void shoot(Character* enemy);
    bool hasBoolets() const;
    void reload();
    std::string getType() override{
        return "Cowboy";
    }

    std::string print() const override;
    Cowboy(const Cowboy&) = default; // Copy constructor
    Cowboy& operator=(const Cowboy&) = default; // Copy assignment operator
    Cowboy(Cowboy&&) = default; // Move constructor
    Cowboy& operator=(Cowboy&&) = default; // Move assignment operato
private:
    int m_bullets;
};

#endif // Coboy_HPP