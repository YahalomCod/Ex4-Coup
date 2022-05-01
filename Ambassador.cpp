#include<iostream>
#include <string>
#include <vector>
#include "Ambassador.hpp"
#include "Game.hpp"
using namespace coup;
using namespace std;

void Ambassador::transfer(Player p1, Player p2){
    p1.total_coins --;
    p2.total_coins ++;
    this->advance_turn();
}

void Ambassador::block(Player p){
    this->advance_turn();
}