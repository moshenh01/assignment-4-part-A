#ifndef TEAM2_HPP
#define TEAM2_HPP

#include "Team.hpp"


class Team2: public ariel::Team{
    public:
        Team2(Character* leader):Team(leader){}
        void order() override; 


        
};

#endif // TEAM2_HPP