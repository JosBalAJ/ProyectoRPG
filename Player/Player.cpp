//
// Created by USER on 11/03/2024.
//

#include "Player.h"
#include <iostream>

using namespace std;

Player::Player(const char* _name, int _health, int _attack, int _defense, int _speed) : Character(_name, _health, _attack, _defense, _speed, true) {
    level = 1;
    experience = 0;
}

void Player::doAttack(Character *target) {
    target->takeDamage(attack);
}

void Player::doAttackWithDoubleDamage(Character *target) {
    target->takeDamage(2 * attack);
}

void Player::takeDamage(int damage) {
    int trueDamage = damage - defense;

    if (trueDamage < 1){
        trueDamage = 1;
    }

    health-= trueDamage;

    cout << name << " took " << trueDamage << " damage!" << endl;

    if(health <= 0) {
        cout << name << " has been defeated!" << endl;
    }
}

void Player::levelUp() {
    cout << "YOU LEVELED UP! You are stronger!" << endl;
    level++;                //Mejora de atributos
    maxHealth += 10;        //Aumento de Salud Máxima
    health = maxHealth;     //Restaura salud
    attack += 3;            //Aumentar ataque, defensa y velocidad
    defense += 3;
    speed += 2;

    cout << "BUT WARNING!!! Your Enemies are also Stronger" << endl;
    for (Enemy* enemy : enemies) {
        enemy->levelUpEnemy();
    }
}

void Player::gainExperience(Enemy* enemy) {
    int experienceFromEnemy = enemy->getExperience();

    experience += experienceFromEnemy;
    if (experience >= 100) {
        levelUp();
        experience -= 100;
    }
}

void Player::addEnemy(Enemy *enemy) {
    enemies.push_back(enemy);
}

Character* Player::selectTarget(vector<Enemy*> possibleTargets) {
    int selectedTarget = 0;
    while (true){
        cout << "Select a target: " << endl;
        for (int i = 0; i < possibleTargets.size(); i++) {
            cout << "   " << i << ". " << possibleTargets[i]->getName() << endl;
        }

        cin >> selectedTarget;

        if (cin.fail() || selectedTarget < 0 || selectedTarget >= possibleTargets.size()){
            cin.clear();
            cout << "Invalid target. Try again..." << endl;
        } else{
            break;
        }
    }
    return possibleTargets[selectedTarget];
}

Action Player::takeAction(vector<Enemy*> enemies) {
    int action = 0;
    while (true){
        cout << "  - Your level: " << level << endl
             << "  - Your XP: " << experience << endl
             << "   * * * * *" << endl
             << "Select an action: " << endl
             << "   1. Attack" << endl
             << "   2. Defend" << endl
             << "   3. Use Item" << endl;

        cin >> action;

        if (cin.fail() || (action != 1 && action != 2 && action != 3)){
            cin.clear();
            cout << "Invalid action" << endl;
        }else{
            break;
        }
    }

    Action currentAction;
    Character* target = nullptr;

    switch(action) {
        case 1:
            target = selectTarget(enemies);
            currentAction.target = target;
            currentAction.action = [this, target](){
                endDefend(); // La defensa se restablece cuando se va a hacer un ataque
                doAttack(target);
            };
            currentAction.speed = getSpeed();
            break;
        case 2:
            isDefending = true;
            currentAction.target = nullptr;
            currentAction.action = [this](){
                endDefend(); //Ahora la defensa se reinicia cada turno, no se acumula
                defend();
            };
            currentAction.speed = getSpeed();
            break;
        case 3:
            cout << "Select an item to use:" << endl;
            cout << "1. Sacrifice a Black Goat (Double damage once)" << endl; // La funcionalidad que añadí ahora ya está bien, hace doble daño una vez, solo que después se detiene la ejecución y no sé por qué
            // Agregar opciones
            int selectedItem;
            cin >> selectedItem;
            if (selectedItem == 1){
                useItem(1);
                target = selectTarget(enemies);
                currentAction.action = [this, target](){
                    doAttackWithDoubleDamage(target);
                };
                currentAction.speed = getSpeed();
            }// else{}
            break;
        default:
            cout << "Invalid action" << endl;
            break;
    }

    return currentAction;
}