#include<iostream>
#include <string>
#include "Game.hpp"
using namespace std;
#pragma once

namespace coup{

    class Player{
        public:
            string name;
            int id;
            int finish_round = 0;
            int total_coins;
            Game *game;
            bool can_block = false;
            bool can_block2 = false;
            bool lost = false;

            Player(Game &g, string n){ 
                if(!g.started){
                    name = n;
                    total_coins = 0;
                    can_block = false;
                    id = g.player->size();
                    this->game = &g;
                    this->game->add_player(*this);
                }
                else{throw invalid_argument("Game already strated");}
            }
 
            void income();
            void foreign_aid();
            void coup(Player &p);
            int coins() const;
            void advance_turn() const;
            ~Player();
    };
};
