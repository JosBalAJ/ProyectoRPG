#include <iostream>
#include "Player/Player.h"
#include "Enemy/Enemy.h"
#include "Combat/Combat.h"
#include <cstdlib>
#include <ctime>


int main() {
    srand(time(nullptr));
    Player *player = new Player("JosBal", 100, 30, 8, 3);
    Enemy *enemy = new Enemy("Leshy", 50, 15, 5, 5, 85, player);
    Enemy *enemy2 = new Enemy("Grizzly", 30, 20, 0, 5, 25, player);
    Enemy *enemy3 = new Enemy("Elk", 20, 15, 15, 5, 35, player);

    vector<Character*> participants;

    player->addEnemy(enemy);
    player->addEnemy(enemy2);
    player->addEnemy(enemy3);

    participants.push_back(player);
    participants.push_back(enemy);
    participants.push_back(enemy2);
    participants.push_back(enemy3);

    Combat *combat = new Combat(participants);
    combat->doCombat();

    delete player;
    delete enemy;
    delete combat;
    return 0;
}