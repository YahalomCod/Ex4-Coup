#include<iostream>
#include <string>
#include <vector>
#include "Game.hpp"
#include "Player.hpp"
#include <queue>
using namespace coup;
using namespace std;

void Game::add_player(Player p){
    // p.set_ID(this->player->size());
    this->player->push_back(p);
    // this->id.push(p.id);
}

string Game::turn(){
    // cout<<endl <<  this->current;
    return (*this->player).at(this->current).name; 
    }

vector<string> Game::players(){
    vector <string> *names = new vector<string>;
    for(Player player : *this->player){
        names->push_back(player.name);
    }
    return *names;
} 