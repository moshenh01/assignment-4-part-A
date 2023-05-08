#ifndef Ninja_HPP
#define Ninja_HPP

#include "Point.hpp"
#include <string>
#include "Character.hpp"
class Ninja : public Character {
public:
    Ninja(const Point& location, const std::string& name, int speed,int hitPoints);
    virtual ~Ninja();
    
    //void setLocation(const Point& location) override;
    virtual void move(Character* enemy);
    virtual void slash(Character* enemy);

protected:
    int m_speed;
};


class YoungNinja : public Ninja {
public:
    YoungNinja(const std::string& name, const Point& loc)
        : Ninja(loc,name,14,100) {}

    ~YoungNinja() {
        free(this);
    }
};

class TrainedNinja : public Ninja {
public:
    TrainedNinja(const std::string& name, const Point& loc)
        : Ninja(loc,name,12,120) {}

    ~TrainedNinja() {
        free(this);
    }

};

class OldNinja : public Ninja {
public:
    OldNinja(const std::string& name, const Point& loc)
        : Ninja(loc,name,10,140) {}

    ~OldNinja() {
        free(this);
    }

};

#endif // Ninja_HPP