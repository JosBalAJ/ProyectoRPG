//
// Created by USER on 11/03/2024.
//

#pragma once
#ifndef RPG_PLAYER_H
#define RPG_PLAYER_H
#include "../Character/Character.h"
#include "../Enemy/Enemy.h"
#include "../Combat/Action.h"
#include <vector>
#include <fstream>

class Enemy;

class Player: public Character {
private:
    int level;
    int experience;

    void levelUp();
    std::vector<Enemy*> enemies;
public:
    //Cambio de string a Char de nuevo
    Player(const char* _name, int _health, int _attack, int _defense, int _speed);

    virtual void doAttack(Character *target) override;
    void doAttackWithDoubleDamage(Character *target);
    void takeDamage(int damage) override;
    Character* selectTarget(vector<Enemy*> possibleTargets);
    Action takeAction(vector<Enemy*> enemies);
    bool isDefending = false;

    void gainExperience(Enemy* enemy);
    void addEnemy(Enemy* enemy);

    void savePlayerToFile();

    void setTheLevel(int lvl) { level = lvl; }
    void setTheExperience(int xp) { experience = xp; }
    void setTheHealth(int hp) { health = hp; }
    void setTheMaxHealth(int maxHp) { maxHealth = maxHp; }
    void setTheAttack(int atk) { attack = atk; }
    void setTheDefense(int def) { defense = def; }
    void setTheSpeed(int spd) { speed = spd; }

    //TODO: Implement use object
};


#endif //RPG_PLAYER_H