#ifndef OLDNINJA_HPP
#define OLDNINJA_HPP

#include "Ninja.hpp"
class OldNinja : public Ninja {
public:
    OldNinja(const std::string& name, const Point& loc)
        : Ninja(loc,name,kOldNinjaPower,kOldNinjaHealth) {}

   ~OldNinja() override = default;
   
    OldNinja(const OldNinja&) = default; // Copy constructor
    OldNinja& operator=(const OldNinja&) = default; // Copy assignment operator
    OldNinja(OldNinja&&) = default; // Move constructor
    OldNinja& operator=(OldNinja&&) = default; // Move assignment operator
private:
    static const int kOldNinjaPower = 8; // Named constant for power
    static const int kOldNinjaHealth = 150; // Named constant for health
};

#endif // OLDNINJA_HPP