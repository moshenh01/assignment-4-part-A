#ifndef YoungNinja_HPP
#define YoungNinja_HPP


#include "Ninja.hpp"

class YoungNinja : public Ninja {
public:
    YoungNinja(const std::string& name, const Point& loc)
        : Ninja(loc,name ,kYoungNinjaPower,kYoungNinjaHealth) {}

    ~YoungNinja() override = default;
    
    YoungNinja(const YoungNinja& other) = default; // Copy constructor
    YoungNinja& operator=(const YoungNinja& other) = default; // Copy assignment operator
    YoungNinja(YoungNinja&& other) = default; // Move constructor
    YoungNinja& operator=(YoungNinja&& other) = default; // Move assignment operator
private:
    static const int kYoungNinjaPower = 14; // Named constant for power
    static const int kYoungNinjaHealth = 100; // Named constant for health
};

#endif // YoungNinja_HPP