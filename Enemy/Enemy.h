//
// Created by USER on 11/03/2024.
//

#ifndef RPG_ENEMY_H
#define RPG_ENEMY_H

#pragma once
#include "../Character/Character.h"
#include "../Player/Player.h"
#include <vector>
#include "../Combat/Action.h"

class Player;

class Enemy: public Character{
private:
    int experience;
    Player* player;
public:
    // Cambio de String a Char de nuevo
    Enemy(const char* _name, int _health, int _attack, int _defense, int _speed, int _experience, Player* _player);
    void doAttack(Character *target) override;
    void takeDamage(int damage) override;
    Character* selectTarget(vector<Player*> possibleTargets);
    Action takeAction(vector<Player*> partyMembers);

    int getExperience();
    void levelUpEnemy();
};


#endif //RPG_ENEMY_H