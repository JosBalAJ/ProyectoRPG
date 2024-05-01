//
// Created by USER on 11/03/2024.
//

#ifndef RPG_CHARACTER_H
#define RPG_CHARACTER_H
#include <string>
#include <cstring>

using namespace std;

class Character {
protected:
    //Cambio de String a Char
    char name[100];
    int health;
    int maxHealth; //Agregamos la salud máxima
    int attack;
    int defense;
    int speed;
    bool isPlayer;
    int originalDefense;
    bool isDefending;
    bool usingItem;
    int itemEffect;
    int originalAttack;
    int effect;
public:
    Character(const char* _name, int _health, int _attack, int _defense, int _speed, bool _isPlayer);

    virtual void doAttack(Character *target) = 0;
    virtual void takeDamage(int damage) = 0;

    void defend();
    void endDefend();

    bool flee(Character* target);
    const char* getName() const;
    int getHealth();
    int getMaxHealth() const {return maxHealth; }
    int getAttack();
    int getDefense();
    bool getIsPlayer();
    int getSpeed();
    string toString();
    bool getUsingItem() const;
    int getItemEffect() const;
    void setUsingItem(bool value);
    void setItemEffect(int effect);
    void endItemEffect();
    void setAttack(int value);
    void useItem(int effectValue);
};


#endif //RPG_CHARACTER_H