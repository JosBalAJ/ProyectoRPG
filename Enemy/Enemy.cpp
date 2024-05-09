//
// Created by USER on 11/03/2024.
//

#include "Enemy.h"
#include "../Utils.h"
#include <iostream>


using namespace std;
using namespace combat_utils;

Enemy::Enemy(const char* _name, int _health, int _attack, int _defense, int _speed, int _experience, Player* _player) : Character(_name, _health, _attack, _defense, _speed, false) {
    experience = _experience;
    player = _player;
}

void Enemy::doAttack(Character *target) {
    target->takeDamage(getRolledAttack(attack));
}

void Enemy::takeDamage(int damage) {
    if (health <= (0.20 * maxHealth)){ //Si el enemigo tiene 20% o menos de vida
        int chance = rand() % 100;
        if (chance < 40){              //Entonces existe un 40% de probabilidad de que se defienda
            int trueDamage = damage - (defense * 1.2); // Su defensa será 20% Mayor
            health-= trueDamage;
            cout << name << " defended and only took " << trueDamage << " damage!" << endl;
            if(health <= 0) {
                cout << name << " has been defeated!" << endl;
                if (player) {
                    cout << name << " gave you " << experience << " of XP" << endl;
                    player->gainExperience(this);
                }
            }
        }
    }else{
        int trueDamage = damage - defense;
        health-= trueDamage;
        cout << name << " took " << trueDamage << " damage!" << endl;
        if(health <= 0) {
            cout << name << " has been defeated!" << endl;
            if (player) {
                cout << name << " gave you " << experience << " of XP" << endl;
                player->gainExperience(this);
            }
        }
    }
}

int Enemy::getExperience() {
    return experience;
}

void Enemy::levelUpEnemy() {
    maxHealth += 3;     // La suma de las mejoras para los 3 enemigos son los mismos puntos que se dieron al jugador
    attack += 1;
    defense += 1;
    speed += 1;
}

Character* Enemy::selectTarget(vector<Player*> possibleTargets) {
    //target with less health
    int lessHealth = 9999999;
    Character* target = nullptr;
    for(auto character : possibleTargets) {
        if(character->getHealth() < lessHealth) {
            lessHealth = character->getHealth();
            target = character;
        }
    }
    return target;
}

Action Enemy::takeAction(vector<Player*> partyMembers) {
    Action currentAction;
    currentAction.speed = getSpeed();

    Character* target = selectTarget(partyMembers);
    currentAction.target = target;
    currentAction.action = [this, target](){
        doAttack(target);
    };

    return currentAction;
}