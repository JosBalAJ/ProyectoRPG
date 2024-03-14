//
// Created by USER on 11/03/2024.
//

#include "Action.h"

Action::Action(int _speed, std::function<void(void)> _action, Character* _subscriber, Character* _target) {
    speed = _speed;
    action = _action;
    target = _target;
    subscriber = _subscriber;
}

Action::Action() {
    speed = 0;
    action = nullptr;
    target = nullptr;
    subscriber = nullptr;
}

bool Action::operator<(const Action &other) const {
    return speed < other.speed;
}