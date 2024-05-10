#include <iostream>
#include "Player/Player.h"
#include "Enemy/Enemy.h"
#include "Combat/Combat.h"
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <sstream>

void loadGame(Player*& player, vector<Character*>& participants);
void newGame(Player*& player, vector<Character*>& participants);
void loadPlayerFromFile(Player& player);

int main() {
    srand(time(nullptr));
    int choice;

    cout << "Welcome to Inscryption't" << endl;
    cout << "1. New Game" << endl;
    cout << "2. Continue" << endl;
    cout << "Enter your choice: " << endl;
    cin >> choice;

    Player* player = nullptr;
    vector<Character*> participants;

    if (choice == 2) {
        loadGame(player, participants);
    } else {
        newGame(player, participants);
    }

    if (player) {
        Combat *combat = new Combat(participants);
        combat->doCombat();
        delete combat;
    }

    for (auto& participant : participants) {
        delete participant;
    }

    return 0;
}

void newGame(Player*& player, vector<Character*>& participants) {
    player = new Player("JosBal", 100, 30, 8, 3);
    Enemy *enemy = new Enemy("Leshy", 50, 15, 5, 5, 85, player);
    Enemy *enemy2 = new Enemy("Grizzly", 30, 20, 0, 5, 25, player);
    Enemy *enemy3 = new Enemy("Elk", 20, 15, 15, 5, 35, player);

    player->addEnemy(enemy);
    player->addEnemy(enemy2);
    player->addEnemy(enemy3);

    participants.push_back(player);
    participants.push_back(enemy);
    participants.push_back(enemy2);
    participants.push_back(enemy3);
}

void loadGame(Player*& player, vector<Character*>& participants) {
    if (!player) {
        player = new Player("Default", 100, 30, 8, 3);
    }

    Enemy *enemy = new Enemy("Leshy", 50, 15, 5, 5, 85, player);
    Enemy *enemy2 = new Enemy("Grizzly", 30, 20, 0, 5, 25, player);
    Enemy *enemy3 = new Enemy("Elk", 20, 15, 15, 5, 35, player);

    player->addEnemy(enemy);
    player->addEnemy(enemy2);
    player->addEnemy(enemy3);

    participants.push_back(player);
    participants.push_back(enemy);
    participants.push_back(enemy2);
    participants.push_back(enemy3);

    loadPlayerFromFile(*player);
}

void loadPlayerFromFile(Player& player) {
    ifstream file("player_data.txt");
    string line;
    string key;
    int value;

    if (file.is_open()) {
        while (getline(file, line)) {
            istringstream iss(line);
            getline(iss, key, ':');
            iss >> value;

            if (key == "Level") {
                player.setTheLevel(value);
            } else if (key == "Experience") {
                player.setTheExperience(value);
            } else if (key == "Health") {
                int maxHealth;
                char slash;
                iss >> slash >> maxHealth;
                player.setTheHealth(value);
                player.setTheMaxHealth(maxHealth);
            } else if (key == "Attack") {
                player.setTheAttack(value);
            } else if (key == "Defense") {
                player.setTheDefense(value);
            } else if (key == "Speed") {
                player.setTheSpeed(value);
            }
        }
        cout << "Game Loaded... Go Ahead!" << endl;
        file.close();
    } else {
        cout << "Failed to Load Your Game..." << endl;
    }
}