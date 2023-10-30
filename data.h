#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;


#ifndef QUEST_GAME_DATA_H
#define QUEST_GAME_DATA_H

/* Перелік дій із характеристиками гравця */
enum class Stats {
    set,
    add,
    sub
};

/* Середовище імен для гравця */
namespace Player {
    class data { // Клас для зберігання даних про гравця
    private:
        int health; // Здоров'я
        int power; // Сила
        int agility; // Проворність, ловкість

    public:
        /* Метод для операцій зі здоров'ям головного героя */
        void set_hp (int value, Stats op = Stats::set) {
            if (op == Stats::add)
                health += value;
            else if (op == Stats::sub)
                health -= value;
            else if (op == Stats::set)
                health = value;
        }

        /* Метод для операцій із силою головного героя */
        void set_power (int value, Stats op = Stats::set) {
            if (op == Stats::add)
                power += value;
            else if (op == Stats::sub)
                power -= value;
            else if (op == Stats::set)
                power = value;
        }

        /* Метод для операцій із проворністтю головного героя */
        void set_agility (int value, Stats op = Stats::set) {
            if (op == Stats::add)
                agility += value;
            else if (op == Stats::sub)
                agility -= value;
            else if (op == Stats::set)
                agility = value;
        }

        /* Метод для отримання поточного рівня здоров'я головного героя */
        [[nodiscard]] int get_hp () const {
            return health;
        }

        /* Метод для отримання поточного рівня сили головного героя */
        [[nodiscard]] int get_power () const {
            return power;
        }

        /* Метод для получення проворності головного героя */
        [[nodiscard]] int get_agility () const {
            return agility;
        }
    };

    /* Клас під інвентар гравця */
    class Inventory {
    private:
        vector<string> inventory; // Інвентар
        int size = 10;
    public:
        /* Метод для виводу вмісту інтентаря */
        void get_inventory () {
            if (!inventory.empty()) {
                cout << "{ ";
                for (const string& item : inventory)
                    cout << "< " << item << " > ";
                cout << "}" << endl;
            } else {
                cout << endl << "{ Порожньо }" << endl;
            }
        }

        /* Метод для додавання предметів до інвентаря */
        void add_items (const vector<string>& items) {
            for (const string& item : items) {
                inventory.push_back(item);
            }
        }

        /* Метод для віднімання предметів із інвентаря */
        void remove_items (const vector<string>& items) {
            int index;

            for (const string& item : items) {
                auto it = find(inventory.begin(), inventory.end(), item);

                if (it != inventory.end()) {
                    index = (int) distance(inventory.begin(), it);

                    inventory.erase(inventory.begin() + index);
                }
            }
        }
    };

}


#endif //QUEST_GAME_DATA_H
