#include<iostream>
#include <string>
#include <vector>
#include <stdexcept>
#include "Game.hpp"
#include "Captain.hpp"
using namespace coup;
using namespace std;

int const max_coins = 10;

void Captain::block(Player const &p){
    throw invalid_argument("Only Captain and Ambassador can block Captain");
}
void Captain::block(Captain &p){
    if(p.can_block && p.game->current != p.id){
        p.stole_from->total_coins += 2;
        p.stole_from = nullptr;
        p.can_block = false;
        p.total_coins -= 2;
    }
    else{ throw invalid_argument("Player cannot be blocked");}
}
void Captain::steal(Player &p){ 
    if(this->total_coins >= max_coins){
            throw invalid_argument("Player with 10 coins must do coup");
        }
    this->advance_turn();
    if(p.total_coins >= 1){
        p.total_coins -= 1;
        this->total_coins += 1;
    }
    if(p.total_coins >= 1){
        p.total_coins -= 1;
        this->total_coins += 1;
    }
    this->stole_from = &p;
    this->can_block = true;
}

string Captain::role(){return "Captain";}

