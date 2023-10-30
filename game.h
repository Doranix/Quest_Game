//
// Created by n1nd0r on 30.10.23.
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


void console_clear ()
{
    #ifdef _WIN32
    system("cls");
    #else
    system("clear");
    #endif
}


#ifndef QUEST_GAME_GAME_H
#define QUEST_GAME_GAME_H


class game {
private:
    static string line;

public:
    static void scene (const string& text) {
        console_clear();

        cout << line << endl;
        cout << text << endl;
        cout << line << endl;

        cin.get();
    }

    static int prompt (const string& question, const vector<string>& answers) {
        string answer;
        auto size = (short) answers.size();

        cout << endl << line << endl;
        cout << question;
        cout << endl << line << endl;

        for (int i = 0; i < size; i++) {
            cout << "\t" << i + 1 << ") " << answers[i] << endl;
        }

        while (true) {
            cout << "Дай відповідь:\n" << ">> ";
            getline(cin, answer);

            for (const string& el : answers)
                if (answer == el) {
                    auto it = find(answers.begin(), answers.end(), answer);
                    return (int) distance(answers.begin(), it) + 1;
                }

            cout << endl << "Такого варіанту немає !" << endl;
        }

    }
};

string game::line = "------------------------------------------------------------------";

#endif //QUEST_GAME_GAME_H
