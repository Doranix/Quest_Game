#include "game.h"
#include "data.h"


int main() {
    Player::set_hp(20);
    Player::set_power(8);
    Player::set_agility(7);
    Inventory::add_items({"Гаманець"});

    game::scene("Тут починається твоя історія");

    switch (game::prompt("Вибери ім'я головного героя", {"Джеймс", "Джек", "Раян", "Майк", "Дабл"})) {
        case 1:
            Player::set_name("Джеймс");
            break;
        case 2:
            Player::set_name("Джек");
            break;
        case 3:
            Player::set_name("Раян");
            break;
        case 4:
            Player::set_name("Майк");
            break;
        case 5:
            Player::set_name("Дабл");
            break;
    }

    puts("ГЛАВА 1 << \"Запрошення\" >> ");
    game::scene("Я пішов. Все !", Player::get_name());
    game::scene("Добре, добре, йди", "Юля");
    game::scene(". . .");
    game::scene("Ей !!!!!! Віддай мій зошит !!!!", "Юля");
    game::scene("Такс, побачим, що ти в ньому пишеш весь цей час..", Player::get_name());

    return 0;
}
