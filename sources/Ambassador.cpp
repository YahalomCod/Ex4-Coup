#include<iostream>
#include <string>
#include <vector>
#include "Ambassador.hpp"
#include "Game.hpp"
using namespace coup;
using namespace std; 

int const max_coins = 10;

void Ambassador::transfer(Player &p1, Player &p2){
    if(this->total_coins >= max_coins){
            throw invalid_argument("Player with 10 coins must do coup");
        }
    if(p1.total_coins > 0){
        this->advance_turn();
        p1.total_coins --;
        p2.total_coins ++;
    }
    else{
        throw invalid_argument("Not enough coins");
    }
}

void Ambassador::block(Player const &p){
    throw invalid_argument("Only Captain and Ambassador can block Captain");
}

void Ambassador::block(Captain &p){
    if(p.can_block && p.game->current != p.id){
        p.stole_from->total_coins += 2;
        p.stole_from = nullptr;
        p.can_block = false;
        p.total_coins -= 2;
    }
    else {
        throw invalid_argument("Ambassador can only block Captain");

    }
}

string Ambassador::role(){return "Ambassador";}