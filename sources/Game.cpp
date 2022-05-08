#include<iostream>
#include <string>
#include <vector>
#include "Game.hpp"
#include "Player.hpp"
#include <queue>
using namespace coup;
using namespace std;
int const max_players = 6;
void Game::add_player(Player &p) const{
    if(this->player->size() < max_players && !this->started){
        this->player->push_back(&p);
    }
    else{
        throw invalid_argument("The game reached maximum capacity");
    }
}

string Game::turn() const{
    return (*this->player).at(this->current)->name; 
    }

vector<string> Game::players() const{
    vector <string> *names = new vector<string>;
    for(Player *player : *this->player){
        if(!player->lost){
            names->push_back(player->name);
        }
    }
    return *names;
} 

string Game:: winner() const{
    if(this->started && this->players().size() == 1){
        return this->players().at(0);
    }
    throw invalid_argument("The game isn't over yet");
}