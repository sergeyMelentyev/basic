//
// Created by Melentyev on 19.07.16.
//

#ifndef CPP_LANG_STRUCT_H
#define CPP_LANG_STRUCT_H

struct EnemySpaceShip {
    int x_coordinate;
    int y_coordinate;
    int weapon_power;
};

EnemySpaceShip getNewEnemy() {
    EnemySpaceShip ship;
    ship.x_coordinate = 0;
    ship.y_coordinate = 0;
    ship.weapon_power = 10;
    return ship;
}

EnemySpaceShip upgradeWeapon(EnemySpaceShip ship) {
    ship.weapon_power += 10;
    return ship;
}

#endif //CPP_LANG_STRUCT_H
