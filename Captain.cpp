#include<iostream>
#include <string>
#include <vector>
#include "Game.hpp"
#include "Captain.hpp"
using namespace coup;
using namespace std;

void Captain::block(Player p){
    this->advance_turn();
}

void Captain::steal(Player p){
    p.total_coins -= 2;
    this->total_coins += 2;
    this->advance_turn();
}

