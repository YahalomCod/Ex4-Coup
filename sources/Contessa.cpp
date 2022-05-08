#include<iostream>
#include <string>
#include <vector>
#include <stdexcept>
#include "Assassin.hpp"
#include "Game.hpp"
#include "Contessa.hpp"
using namespace coup;
using namespace std;

void Contessa::block(Player const &p){
    throw invalid_argument("Contessa can only block Assassin");
}

void Contessa::block(Assassin &p){
    if(p.can_block && p.id != this->game->current){
        p.stole_from->lost = false;
        p.stole_from = nullptr;
        p.can_block = false;;
    }
    else{throw invalid_argument("Player could not be blocked");}
}
string Contessa::role(){return "Contessa";}
