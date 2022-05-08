#include<iostream>
#include <string>
#include "Game.hpp"
#include "Player.hpp"
using namespace std;
#pragma once

namespace coup{
    
    class Assassin: public Player{
        public:
            Player *stole_from;
            Assassin(Game &g, string n): Player(g, n){}
            string static role();
            void coup(Player &p);
    };
};
