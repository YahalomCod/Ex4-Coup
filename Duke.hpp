#include<iostream>
#include <string>
#include "Game.hpp"
#include "Player.hpp"
using namespace std;
#pragma once

namespace coup{
    
    class Duke: public Player{
        public:
            Duke(Game &g, string n): Player(g, n){}
            void block(Player p);
            void tax();
    };
};
