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
    int health; // Здоров'я
    int power; // Сила
    int agility; // Проворність, ловкість
    string name; // Ім'я головного героя

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
    void set_agility (const int& value, Stats op = Stats::set) {
        if (op == Stats::add)
            agility += value;
        else if (op == Stats::sub)
            agility -= value;
        else if (op == Stats::set)
            agility = value;
    }

    /* Метод для операцій з іменем героя */
    void set_name (const string& value) {
        name = value;
    }

    /* Метод для отримання поточного рівня здоров'я головного героя */
    int get_hp () {
        return health;
    }

    /* Метод для отримання поточного рівня сили головного героя */
    int get_power () {
        return power;
    }

    /* Метод для отримання проворності головного героя */
    int get_agility () {
        return agility;
    }

    /* Метод для отримання імені головного героя */
    string get_name () {
        return name;
    }
}

namespace Inventory {
    vector<string> inventory; // Інвентар
    int size = 10; // Розмір інвентарю

    /* Метод для виводу вмісту інтентаря */
    void get_inventory () {
        if (!inventory.empty()) {
            cout << endl << "{ ";
            for (const string& item : inventory)
                cout << "[" << item << "] ";
            cout << "}" << endl;
        } else {
            cout << endl << "{ Порожньо }" << endl;
        }
    }

    /* Метод для додавання предметів до інвентарю */
    void add_items (const vector<string>& items) {
        for (const string& item : items) {
            inventory.push_back(item);
        }
    }

    /* Метод для віднімання предметів з інвентарю */
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
}


#endif //QUEST_GAME_DATA_H
