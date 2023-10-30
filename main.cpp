#include "game.h"
#include "data.h"


int main() {

    Player::data player{};
    Player::Inventory inv;

    player.set_hp(20, Stats::set);
    player.set_power(10, Stats::set);
    player.set_agility(7, Stats::set);



    return 0;
}
