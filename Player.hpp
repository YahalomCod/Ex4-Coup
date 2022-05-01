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
            int id;
            int total_coins;
            Game *game;
            bool can_block;
            bool lost;
            Player(Game &g, string n){
                name = n;
                total_coins = 0;
                can_block = false;
                id = g.player->size();
                // g.add_player(*this);
                this->game = &g;
                this->game->add_player(*this);
            }
 
            void set_ID(unsigned int id);
            void income();
            void foreign_aid();
            void coup(Player p);
            string role();
            int coins();
            void advance_turn();
    };
};
