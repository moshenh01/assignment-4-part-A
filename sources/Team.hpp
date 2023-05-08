
#include "Ninja.hpp"
#include "Point.hpp"
#include"Character.hpp"
#include "Coboy.hpp"

namespace ariel{
    class Team{
        private:
            Ninja* _leader;
            Ninja** _ninjas;
            int _size;
            int _capacity;
            void resize();
        public:
            Team(Ninja* leader);
            ~Team();
            void add(Ninja* ninja);
            void attack(Team* other);
            int stillAlive();
            void print();
    };
}