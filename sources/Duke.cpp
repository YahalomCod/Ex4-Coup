#include<iostream>
#include <string>
#include <stdexcept>
#include <vector>
#include "Game.hpp"
#include "Duke.hpp"
using namespace coup;
using namespace std;

int const max_coins = 10;
void Duke::block(Player &p){
    if(p.can_block2 && p.game->current != p.id){
        p.total_coins -= 2;
        p.can_block2 = false;
    }
    else{ throw invalid_argument("The given player cannot be blocked"); } 
}

void Duke::tax(){
    if(this->total_coins >= max_coins){
            throw invalid_argument("Player with 10 coins must do coup");
        }
    this->advance_turn();
    this->total_coins += 3;
}

string Duke::role(){return "Duke";}