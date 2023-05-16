#ifndef TEAM_HPP
#define TEAM_HPP
#include "Ninja.hpp"
#include "Point.hpp"
#include"Character.hpp"
#include "Cowboy.hpp"
#include "OldNinja.hpp"
#include "YoungNinja.hpp"
#include "TrainedNinja.hpp"

#include <thread>
#include <chrono>
#include <array>


namespace ariel{
    class Team{
        private:
            static const int MAX_TEAM_SIZE = 10;
            std::array<Character*, MAX_TEAM_SIZE> m_team;
            //the leader is the first ninja/caboy in the team this is the game vector
            std::array<Character*, MAX_TEAM_SIZE> m_team_order;

            Character* m_leader;
            unsigned long int num_of_worriers;
            int num_alive;
            
            void choose_new_leader();
        public:
            
            Team(Character* leader);
            Team():m_leader(nullptr),num_of_worriers(0),num_alive(0),m_team{},m_team_order{}{}
            virtual ~Team();
            virtual void order();
            void add(Character* new_member);
            void attack(Team* other);
            int stillAlive();
            void print() const ; 

            unsigned long int getNumOfWorriers() const
            {
                return num_of_worriers;
            }
              // Getter methods for the arrays
            std::array<Character*,  MAX_TEAM_SIZE> getTeam() { return m_team; }
            std::array<Character*,  MAX_TEAM_SIZE> getTeamOrder() { return m_team_order; }
            void setTeamOrder(const std::array<Character*, MAX_TEAM_SIZE>& teamOrder) {
                m_team_order = teamOrder;
            }
            // Default copy constructor
            Team(const Team&) = default;

            // Default copy assignment operator
            Team& operator=(const Team&) = default;

            // Default move constructor
            Team(Team&&) = default;

            // Default move assignment operator
            Team& operator=(Team&&) = default;
    };
  
}

#endif // TEAM_HPP