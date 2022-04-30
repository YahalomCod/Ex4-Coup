#include<iostream>
#include <string>
#include "Game.hpp"
#include "Player.hpp"
#include "Assassin.hpp"
using namespace std;
#pragma once

namespace coup{
    
    class Contessa: public Player{
        public:
            explicit Contessa(Game g, string n): Player(g, n){}
            void block(Player c);
    };
};
