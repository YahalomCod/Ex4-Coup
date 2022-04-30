#include "doctest.h"
#include "Player.hpp"
#include "Game.hpp"
#include "Duke.hpp"
#include "Assassin.hpp"
#include "Contessa.hpp"
#include "Ambassador.hpp"
#include "Captain.hpp"
#include "doctest.h"
using namespace coup;
#include <string>
#include <algorithm>
using namespace std;

Game game{};
Duke duke{game, "Koko"};
Assassin assassin{game, "Diamond"};
Ambassador ambassador{game, "Golan"};
Captain captain{game, "Satoshi"};
Contessa contessa{game, "Or"};

TEST_CASE("Good input") {
    for(Player p : *game.player){
        CHECK_NOTHROW(p.income());
    }
    CHECK_NOTHROW(duke.income());
    CHECK_NOTHROW(assassin.income());
    CHECK_NOTHROW(ambassador.income());
    CHECK_NOTHROW(captain.income());
    CHECK_NOTHROW(contessa.income());
    CHECK_THROWS(duke.coup(assassin));
    CHECK(duke.coins() == captain.coins());
    for(Player p : *game.player){
        CHECK_NOTHROW(p.foreign_aid());
    }
    CHECK_NOTHROW(duke.block(ambassador));
    CHECK_NOTHROW(assassin.coup(duke));
    CHECK_NOTHROW(ambassador.transfer(duke, contessa));
    CHECK_NOTHROW(captain.steal(ambassador));
    CHECK_NOTHROW(contessa.block(assassin));
}

TEST_CASE("Bad input") {
   
    CHECK_THROWS(assassin.income());
    CHECK_THROWS(contessa.block(captain));
    CHECK_THROWS(duke.block(ambassador));
    assassin.foreign_aid();
    CHECK_THROWS(ambassador.coup(assassin));
    CHECK_THROWS(captain.coup(assassin));
    CHECK_THROWS(contessa.coup(assassin));
    CHECK_THROWS(duke.coup(assassin));

}