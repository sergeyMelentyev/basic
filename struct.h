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


/*** BINARY TREES ***/
    struct node {
        int key_value;
        node* p_left;
        node* p_right;
    };

    node* insert(node* p_tree, int key) {
        if (p_tree == NULL) {                                                   // find empty tree, add new node
            node* p_new_tree = new node;
            p_new_tree -> p_left = NULL;
            p_new_tree -> p_right = NULL;
            p_new_tree -> key_value = key;
            return p_new_tree;
        }
        if (key < p_tree -> key_value) {
            p_tree -> p_left = insert(p_tree -> p_left, key);
        } else {
            p_tree -> p_right = insert(p_tree -> p_right, key);
        }
        return p_tree;
    }

    node* search(node* p_tree, int key) {
        if (p_tree == NULL) {
            return NULL;
        } else if (key == p_tree -> key_value) {
            return p_tree;
        } else if (key < p_tree -> key_value) {
            return search(p_tree -> p_left, key);
        } else {
            return search(p_tree -> p_right, key);
        }
    }

    void destroy_tree(node* p_tree){
        if (p_tree != NULL) {
            destroy_tree(p_tree -> p_left);
            destroy_tree(p_tree -> p_right);
            delete p_tree;
        }
    }

#endif //CPP_LANG_STRUCT_H
