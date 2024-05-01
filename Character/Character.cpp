//
// Created by USER on 11/03/2024.
//

#include "Character.h"
Character::Character(const char* _name, int _health, int _attack, int _defense, int _speed, bool _isPlayer) {
    strcpy(name, _name);
    health = _health;
    maxHealth = _health;
    attack = _attack;
    defense = _defense;
    originalDefense = _defense;
    speed = _speed;
    isPlayer = _isPlayer;
    usingItem = false;
    originalAttack = _attack;
    effect = 0;
}

const char* Character::getName() const {
    return name;
}

int Character::getHealth() {
    return health;
}

int Character::getAttack() {
    return attack;
}

int Character::getDefense() {
    return defense;
}

int Character::getSpeed() {
    return speed;
}

string Character::toString() {
    string nameStr(name);
    return "Name: " + nameStr + "\nHealth: " + to_string(health) + "\nAttack: " + to_string(attack) + "\nDefense: " + to_string(defense) + "\nSpeed: " + to_string(speed);
}

bool Character::getIsPlayer() {
    return isPlayer;
}

bool Character::flee(Character*target) {
    if(this->speed > target->speed)
        return true;

    int chance = rand() % 100;
    return chance > 30;
}

void Character::defend() {
    defense = static_cast<int>(defense * 1.2);
    isDefending = true;
}

void Character::endDefend() {
    defense = originalDefense;
    isDefending = false;
}

bool Character::getUsingItem() const {
    return usingItem;
}

int Character::getItemEffect() const {
    return itemEffect;
}

void Character::setUsingItem(bool value) {
    usingItem = value;
}

void Character::setItemEffect(int effect) {
    itemEffect = effect;
}

void Character::endItemEffect() {
    usingItem = false;
    attack = originalAttack;
}

void Character::setAttack(int value) {
    attack = value;
}

void Character::useItem(int effectValue) {
    effect = effectValue;
}