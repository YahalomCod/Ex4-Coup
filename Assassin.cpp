#include<iostream>
#include <string>
#include <vector>
#include "Game.hpp"
#include "Assassin.hpp"
using namespace coup;
using namespace std;

void Assassin::coup(Player p){
    if(this->total_coins >= 3){
        this->lost = true;
        this->total_coins -= 3;
        this->advance_turn();
    }
    else{ throw invalid_argument("Not enough coins"); }
}