#include<iostream>
#include <string> 
#include <vector>
#include "Game.hpp"
#include "Assassin.hpp"
#include <stdexcept>
using namespace coup;
using namespace std;

int const coupIt = 7;

void Assassin::coup(Player &p){
    if(this->total_coins >= coupIt && ! p.lost){
        this->advance_turn();
        p.lost = true;
        this->game->player->erase(this->game->player->begin() + p.id);
        int count =0;
        for(Player *p : *this->game->player){
            p->id = count ++;
        }
        this->total_coins -= coupIt;
        this->game->current = (this->game->current) % this->game->player->size();
        if(this->id > p.id){ 
            this->game->current = (this->game->current - 1) % this->game->player->size();}
    }
    else if(this->total_coins >= 3 && ! p.lost){
        this->advance_turn();
        this->total_coins -= 3;
        this->can_block = true;
        p.lost = true;
        this->stole_from = &p;
        
    }
    else{ throw invalid_argument("Not enough coins"); }
}

string Assassin::role(){return "Assassin";}