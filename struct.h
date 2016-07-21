//
// Created by Melentyev on 19.07.16.
//

#ifndef CPP_LANG_STRUCT_H
#define CPP_LANG_STRUCT_H

/*** STRUCT DATA TYPE***/
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


/*** POINTERS TO THE STRUCT ***/
    struct EnemyStarShip {
        int x_coordinate;
        int y_coordinate;
        int weapon_power;
        EnemyStarShip* p_next_enemy;
    };

    EnemyStarShip* p_enemies = NULL;                                            // list of all enemies (head)

    EnemyStarShip* get_new_enemy() {
        EnemyStarShip* p_ship = new EnemyStarShip;
        p_ship -> x_coordinate = 0;
        p_ship -> y_coordinate = 0;
        p_ship -> weapon_power = 20;
        p_ship -> p_next_enemy = p_enemies;                                     // point to the prev first enemy
        p_enemies = p_ship;                                                     // assign pointer to the new enemy
        return p_ship;
    }

    void upgrade_weapon(EnemyStarShip* p_ship) {
        p_ship -> weapon_power += 10;
    }

#endif //CPP_LANG_STRUCT_H
