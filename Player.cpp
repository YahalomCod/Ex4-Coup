#include<iostream>
#include <stdexcept>
#include <string>
#include <vector>
#include "Game.hpp"
#include "Player.hpp"
using namespace coup;
using namespace std;

void Player::advance_turn(){
    if(this->game->current < this->game->player->size() && this->id == this->game->current){
            cout <<"this is current turn : "<< this->game->current << " this is the id : "<< this->id << endl;
            this->game->current = (this->game->current + 1) % this->game->player->size();
    }
    else{
        throw invalid_argument("That is not the correct player for this turn");
    }
}

void Player::income(){
    this->advance_turn();
    this->total_coins ++;
}

void Player::foreign_aid(){
    this->advance_turn();
    this->total_coins += 2;
    this->can_block = true;
}

void Player::coup(Player p){
    if(this->total_coins >= 7){
        this->advance_turn();
        this->lost = true;
        this->total_coins -= 7;
    }
    else{ throw invalid_argument("Not enough coins"); }
}

int Player::coins(){
    return this->total_coins;
}

void Player::set_ID(unsigned int id){
    // this->id = id;
}
// string Player::role(){
//     return 
// }