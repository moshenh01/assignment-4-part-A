#include "Team.hpp"
#include "Team2.hpp"
#include <iostream>
using namespace std;

 
void ariel::Team::order()
{
     for (unsigned long int j = 0; j < 10; j++)
    {
        m_team_order[j] = nullptr;
    }

    unsigned long int i =0;
   
    for(Character* c : m_team)
    {
        if(c == NULL || c == nullptr)
        {
            //printf("1null\n");
            break;
        }
        else{ 
            
            if(c->getType() == "Ninja")
            {
                //printf("ninja\n");
                continue;
            }
            else
            {
                //insert the cowboy to the first place
                if(c->getType() == "Cowboy"){
                    m_team_order[i] = c;
                    //printf("inserted %s\n",c->getName().c_str());
                    i++;
                }
            }
        }
       
    }
   
    for(Character* c : m_team)
    {
        if(c == NULL || c == nullptr)
        {
            //printf("2null\n");
            break;
        }
        if(c->getType() == "Cowboy")
        {
            continue;
        }
        else
        {
            if(c->getType() == "Ninja")
            {
                    m_team_order[i] = c;
                    //printf("inserted %s\n",c->getName().c_str());
                    i++;
                
            }
          
        }
    }
   
    for(Character* c : m_team_order)
    {
        if (c == nullptr)
        {
            //printf("3null\n");
            break;
        }
        else{
        
            //cout << c->getType() <<" named "<<c->getName()<< endl;
           
        }
       
    }
     //printf("3order\n");
   
     
}


//coose the closest member of the team to the leader
void ariel::Team::choose_new_leader(){
    int min_distance = 1000000;
    int distance;
    unsigned long index = 0;
    for (unsigned long int i = 0; i < num_of_worriers; i++)
    {
        if (m_team[i]->isAlive())
        {
            distance = m_team[i]->getLocation().distance(m_leader->getLocation());
            if (distance < min_distance)
            {
                min_distance = distance;
                index = i;
            }
        }
    }
    //if no mew leader was found
    m_leader = m_team[index];
    
}

Character* choose_victim(std::array<Character*, 10UL> team, Character* leader, int size){
    int min_distance = 1000000;
    int distance;
    unsigned long int index = 0;
    for (unsigned long int i = 0; i < size; i++)
    {
        if (team[i]->isAlive() == true)
        {
            distance = team[i]->getLocation().distance(leader->getLocation());
            if (distance < min_distance)
            {
                min_distance = distance;
                index = i;
            }
        }
    }
    return team[index];
}

ariel::Team::Team(Character* leader):m_leader(leader),num_of_worriers(0),num_alive(0){
    for(unsigned long int i = 0; i < 10; i++){
        m_team[i] = nullptr;
    }
    if(leader == NULL){
        throw std::invalid_argument("leader is null");
        return;
    }
    if(leader->isAlive() == false){
        throw std::invalid_argument("leader is dead");
        return;
    }
    if(leader->getInTeam() == true){
        throw std::invalid_argument("leader is already in a team");
        return;
    }
    m_team[0] = leader;
    leader->setInTeam(true);
    m_team[1] = nullptr;
    m_leader = leader;
    num_of_worriers = 1;
    num_alive = 1;
}


ariel::Team::~Team(){


   // std::this_thread::sleep_for(std::chrono::seconds(1));
    for (unsigned long int i = 0; i < num_of_worriers; i++)
    {
        if(m_team[i] != nullptr){
           // printf("deleting %s\n",m_team[i]->getName().c_str());
            delete m_team[i];
           
            m_team[i] = nullptr;
        }

    }
    
}

void ariel::Team::add(Character* new_member){
    if(num_of_worriers == 10){
        printf("Team is full\n");
        return;
    }
    if(new_member == NULL){
        throw std::invalid_argument("new member is null");
        return;
    }
    if(new_member->isAlive() == false){
        throw std::invalid_argument("new member is dead");
        return;
    }
    if(new_member->getInTeam() == true){
        throw std::invalid_argument("new member is already in a team");
        return;
    }
    m_team[num_of_worriers] = new_member;
    num_of_worriers++;
    m_team[num_of_worriers] = nullptr;
    num_alive++;
    new_member->setInTeam(true);
}

void ariel::Team::attack(Team* other){
    if(other == NULL){
        throw std::invalid_argument("other team is null");
        return;
    }
    //just for part b
    // if(other->num_alive == 0){
    //     throw std::runtime_error("other team is dead");
    //     return;
    // }
    // if(num_alive == 0){
    //     throw std::runtime_error("this team is dead");
    //     return;
    // }
    if(m_leader->isAlive() == false){
        choose_new_leader();
        //printf("Team %s leader is dead, %s is the new leader\n",m_leader->getName().c_str(),m_leader->getName().c_str());
        if(m_leader->isAlive() == false){
            printf("+Team %s is dead\n",m_leader->getName().c_str());
            return;
        }
    }
    if(other == this){
        throw std::invalid_argument("other team is this team");
        return;
    }
    order();
    other->order();
    printf("Team %s attacks!\n",m_leader->getName().c_str());
   
    int i = 0;
    int j = 0;
   
       Character *victim = choose_victim(other->m_team,this->m_leader,other->num_of_worriers);

      

       for(unsigned long int k = 0; k < num_of_worriers; k++){

           if(m_team_order[k]->isAlive() == true && victim->isAlive() == true){
              if(m_team_order[k]->getType() == "Ninja"){
                    //printf("ninja attacks\n");

                        //if the ninja is 1 meter away from the victim he will slash him else he will move towards him
                    if(m_team_order[k]->getLocation().distance(victim->getLocation()) <= 1){
                        ((Ninja*)m_team_order[k])->slash(victim);
                    }
                    else{
                        ((Ninja*)m_team_order[k])->move(victim);
                    }
                  
              }
              else{
                //printf("cowboy attacks\n");
                  ((Cowboy*)m_team_order[k])->shoot(victim);
              }
           }
           else{
               if(victim->isAlive() == false){
                   other->num_alive--;
               }
               if(other->num_alive == 0){
                     printf("++ Team %s is dead\n",other->m_leader->getName().c_str());
                    break;
               }
               
           }
       }
       
}
    


int ariel::Team::stillAlive(){
    int counter = 0;
    for (unsigned long int i = 0; i < num_of_worriers; i++)
    {
        if (m_team[i]->isAlive() == true)
        {
            counter++;
        }
    }
   
    num_alive = counter;
    return counter;
}
void ariel::Team::print() const{
    
    for ( unsigned long int i = 0; i < num_of_worriers; i++)
    {
        
       cout<< m_team_order[i]->print() << endl;
    }
    
    
}

///team2*************

void Team2::order(){
   printf("Team2 order\n");
    auto teamPtr = this->getTeam(); // Use auto to deduce the type

    this->setTeamOrder(teamPtr);
    
}