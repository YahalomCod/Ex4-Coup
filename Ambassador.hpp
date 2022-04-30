#include<iostream>
#include <string>
#include "Game.hpp"
#include "Player.hpp"
#include "Captain.hpp"
using namespace std;
#pragma once

namespace coup{

    class Ambassador: public Player{
        public:
            explicit Ambassador(Game g, string n): Player(g, n){}
            void transfer(Player p1, Player p2);

            void block(Captain c);
    };
};
