#include "Cowboy.hpp"

//??????????????????????????????????/
Cowboy::Cowboy(const std::string& name ,const Point& location) 
: Character(location, name, 110), m_bullets(6) {
}



void Cowboy::shoot(Character* enemy) {
    if (hasBoolets()&& isAlive() && enemy->isAlive()) {
        enemy->hit(10);
        m_bullets--;
        if (m_bullets == 0) {
            reload();
        }
        
        
    }
}

bool Cowboy::hasBoolets() const {
    return m_bullets > 0;
}

void Cowboy::reload() {
    m_bullets = 6;
}

std::string Cowboy::print() const {
    std::string output = "C  " + Character::print();
    if (isAlive()) {
        output += "bullets left: " + std::to_string(m_bullets) + " ";
    }

    return output;
}
