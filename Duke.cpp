#include<iostream>
#include <string>
#include <stdexcept>
#include <vector>
#include "Game.hpp"
#include "Duke.hpp"
using namespace coup;
using namespace std;

void Duke::block(Player p){
    if(!p.can_block){
        throw invalid_argument("The given player cannot be blocked");
    }
    p.total_coins -= 2;
    this->advance_turn();
}

void Duke::tax(){
    this->total_coins += 3;
    this->advance_turn();
}