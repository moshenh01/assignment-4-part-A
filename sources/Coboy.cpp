#include "Coboy.hpp"

//??????????????????????????????????/
Cowboy::Cowboy(const std::string& name ,const Point& location) 
: Character(location, name, 110), m_bullets(6) {
}

Cowboy::~Cowboy() {
    free(this);
}

void Cowboy::shoot(Character* enemy) {
    if (hasBullets()&& isAlive() && enemy->isAlive()) {
        enemy->hit(10);
        m_bullets--;
        if (m_bullets == 0) {
            reload();
        }
        
        
    }
}

bool Cowboy::hasBullets() const {
    return m_bullets > 0;
}

void Cowboy::reload() {
    m_bullets = 6;
}

std::string& Cowboy::print() const  {
      std::cout << "[";
        if (!isAlive()) {
            std::cout << "X";
        } else if (hasBullets()) {
            std::cout << m_bullets;
        } else {
            std::cout << "0";
        }
        std::cout << "] ";
        std::cout << getName() << " - " << getLocation().getX() << "," << getLocation().getY() << " ";
        //std::cout << getHitPoints() << " HP ";
        std::cout << std::endl;

}