#include<iostream>
#include <string>
#include "Game.hpp"
using namespace std;
#pragma once

namespace coup{

    class Player{
        public:
            string name;
            string last_action;
            int total_coins;
            Game game;
            bool can_block;
            bool lost;
            explicit Player(Game g, string n){
                name = n;
                total_coins = 0;
                can_block = false;
                g.add_player(*this);
                game = g;
            }

            void income();
            void foreign_aid();
            void coup(Player p);
            string role();
            int coins();
            void advance_turn();
    };
};
