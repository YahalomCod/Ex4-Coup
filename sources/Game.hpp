#include<iostream>
#include <string>
#include <vector>
#include <queue>

#pragma once

using namespace std;
namespace coup{
    class Player;
    class Game{
        public:
            vector <Player*> *player;
            unsigned int current;
            bool started = false;
            unsigned int c = 0;
            queue <int> id;
            Game(){
                player = new vector<Player*>;
                current = 0;
            } 
            void add_player(Player &p) const;
            string turn() const;
            string winner() const;
            vector<string> players() const;
    };
};
