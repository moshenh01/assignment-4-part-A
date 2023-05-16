#include "Ninja.hpp"


Ninja::Ninja(const Point& location, const std::string& name, int speed, int hitPoints)
: Character(location, name, hitPoints), m_speed(speed) {}


void Ninja::move(Character* enemy) {
    Point dest = enemy->getLocation();
    Point src = getLocation();
    double distance_to_enemy = src.distance(dest);

    if (isAlive()&&enemy->isAlive()&&distance_to_enemy>0) {
         Point new_loc = src.moveTowards(src,dest,this->m_speed);
        setLocation(new_loc);
    }
  
}
void Ninja::slash(Character* enemy) {
    Point dest = enemy->getLocation();
    Point src = getLocation();
    double distance_to_enemy = src.distance(dest);
    if (isAlive()&&enemy->isAlive()&&distance_to_enemy<=1) {
        enemy->hit(31);
    }
}
std::string Ninja::print() const {
    std::string output = "N  " + Character::print();
    if (isAlive())
    {
        output += "Speed: " + std::to_string(m_speed);
    }
    
  

    return output;
}
    
