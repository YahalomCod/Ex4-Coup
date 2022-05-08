#include<iostream>
#include <stdexcept>
#include <string>
#include <vector>
#include "Game.hpp"
#include "Player.hpp"
using namespace coup;
using namespace std;

int const max_coins = 10;
int const coupIt = 7;
void Player::advance_turn() const{
    if(this->game->current < this->game->player->size() 
        && this->id == this->game->current && this->game->player->size() > 1){
            this->game->started = true;
            this->game->current = (this->game->current + 1) % this->game->player->size();
            this->game->player->at(this->game->current)->can_block = false;
            this->game->player->at(this->game->current)->can_block2 = false;
    }
    else{
        throw invalid_argument("That is not the correct player for this turn");
    }
    while(this->game->player->at(this->game->current)->lost){
        this->game->current = (this->game->current + 1) % this->game->player->size();
    }
}

void Player::income(){
    if(this->total_coins >= max_coins){
            throw invalid_argument("Player with 10 coins must do coup");
        }
    this->advance_turn();
    this->total_coins ++;
}

void Player::foreign_aid(){
    if(this->total_coins >= max_coins){
            throw invalid_argument("Player with 10 coins must do coup");
        }
    this->advance_turn();
    this->total_coins += 2;
    this->can_block2 = true;
    // *this->last_action = "foreign_aid";
}

void Player::coup(Player &p){
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
    else{ throw invalid_argument("Not enough coins"); }
}

int Player::coins() const{
    return this->total_coins;
}

Player::~Player() { }