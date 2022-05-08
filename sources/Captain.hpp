#include<iostream>
#include <string>
#include "Game.hpp"
#include "Player.hpp"
using namespace std;
#pragma once

namespace coup{
    
    class Captain: public Player{
        public:
            Player *stole_from;
            Captain(Game &g, string n): Player(g, n){}
            void steal(Player &p);
            void static block(Player const &p); 
            void static block(Captain &p);            
            string static role();

    };
};
