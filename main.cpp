#include <iostream>
#include "Player/Player.h"
#include "Enemy/Enemy.h"
#include "Combat/Combat.h"


int main() {
    Player *player = new Player("JosBal", 100, 30, 8, 3);
    Enemy *enemy = new Enemy("Leshy", 200, 15, 5, 5, 10);
    Enemy *enemy2 = new Enemy("Grizzly", 40, 20, 0, 5, 10);
    Enemy *enemy3 = new Enemy("Elk", 50, 15, 15, 5, 10);

    vector<Character*> participants;

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