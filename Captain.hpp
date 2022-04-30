#include<iostream>
#include <string>
#include "Game.hpp"
#include "Player.hpp"
using namespace std;
#pragma once

namespace coup{
    
    class Captain: public Player{
        public:
            explicit Captain(Game g, string n): Player(g, n){}
            void steal(Player p);
            void block(Player p);
    };
};
