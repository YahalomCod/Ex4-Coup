#include<iostream>
#include <string>
#include <vector>
#pragma once

using namespace std;

namespace coup{
    class Player;
    class Game{
        public:
            vector <Player> *player;
            unsigned int current;
            Game(){
                player = new vector<Player>;
                current = 0;
            }
            void add_player(Player p);
            string turn();
            vector<string> players();
    };
};
