#ifndef Coboy_HPP
#define Coboy_HPP
#include "Point.hpp"
#include <string>
#include "Character.hpp"

class Cowboy : public Character {
public:
    Cowboy( const std::string& name,const Point& location);
    ~Cowboy();

    void shoot(Character* enemy);
    bool hasBullets() const;
    void reload();

    std::string& print() const override;

private:
    int m_bullets;
};

#endif // Coboy_HPP