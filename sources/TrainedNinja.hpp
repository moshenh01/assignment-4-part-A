#ifndef TrainedNinja_HPP
#define TrainedNinja_HPP

#include "Ninja.hpp"
class TrainedNinja : public Ninja {
public:
    TrainedNinja(const std::string& name, const Point& loc)
        : Ninja(loc,name,kTrainedNinjaPower,kTrainedNinjaHealth) {}

    ~TrainedNinja() override = default;
    
    TrainedNinja(const TrainedNinja& other) = default; // Copy constructor
    TrainedNinja& operator=(const TrainedNinja& other) = default; // Copy assignment operator
    TrainedNinja(TrainedNinja&& other) = default; // Move constructor
    TrainedNinja& operator=(TrainedNinja&& other) = default; // Move assignment operator
private:
    static const int kTrainedNinjaPower = 12; // Named constant for power
    static const int kTrainedNinjaHealth = 120; // Named constant for health
};

#endif // TrainedNinja_HPP

