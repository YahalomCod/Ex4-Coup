#include<iostream>
#include <string>
#include <vector>
#include "Game.hpp"
#include "Player.hpp"
using namespace coup;
using namespace std;

void Player::advance_turn(){
    if(this->game.current + 1 >= this->game.player->size()){
        this->game.current = 0;
    }
    else{
        // cout << this->game.current;
        this->game.current++;
        // cout << this->game.current<<endl;

    }
}

void Player::income(){
    this->total_coins ++;
    this->advance_turn();
}

void Player::foreign_aid(){
    this->total_coins += 2;
    this->can_block = true;
    this->advance_turn();

}

void Player::coup(Player p){
    if(this->total_coins >= 7){
        this->lost = true;
        this->total_coins -= 7;
        this->advance_turn();
    }
    else{ throw invalid_argument("Not enough coins"); }
}

int Player::coins(){
    return this->total_coins;
}

// string Player::role(){
//     return 
// }