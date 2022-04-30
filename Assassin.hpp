#include<iostream>
#include <string>
#include "Game.hpp"
#include "Player.hpp"
using namespace std;
#pragma once

namespace coup{
    
    class Assassin: public Player{
        public:
            explicit Assassin(Game g, string n): Player(g, n){}

            void coup(Player p);
    };
};
