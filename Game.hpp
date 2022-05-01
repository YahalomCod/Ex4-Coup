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
            vector <Player> *player;
            unsigned int current;
            // unsigned int *current;
            unsigned int c = 0;
            queue <int> id;
            Game(){
                player = new vector<Player>;
                current = 0;
            } 
            void add_player(Player p);
            string turn();
            vector<string> players();
    };
};
