//
// Created by USER on 11/03/2024.
//

#include<cstdlib>

namespace combat_utils {
    int getRolledAttack(int attack) {
        int lowerLimit = attack * .80;
        return (rand() % (attack - lowerLimit + 1)) + lowerLimit;
    }
}