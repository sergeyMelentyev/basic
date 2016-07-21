//
// Created by Melentyev on 07.07.16.
//

#include <iostream>
#include <vector>
#include <map>
#include <string>
#include "struct.h"
#include "custom_data_types.h"

using namespace std;
int summ_array(int values[], int size);                            // function prototype


/*** POINTER VS REFERENCE ***/
    int any_function_name(int x) { return x+1; }
    void any_function_name(int* x) { ++*x; }
    void any_function_name(int& x) { ++x; }


int main() {
    constexpr int max_value = 100;									// constant expression must be assigned
    const int min_value = 100 / max_value;							// constant classic can be assign at compile time
    double d {2.7};													// universal and uniform initialization


/*** ENUM TYPE ***/
    enum RainbowColor {
        RC_RED = 1,
        RC_ORANGE = 3,
        RC_YELLOW
    };
    RainbowColor choose_color = RC_ORANGE;


/*** STRUCT TYPE ***/
    struct PlayerInfo {
        int skill_level;
        string name;
    };

    PlayerInfo playerOne;                                           // create a single struct
    playerOne.name = "Sergey";
    playerOne.skill_level = 10;

    PlayerInfo players[5];                                          // create an array of structs
    for (int i = 0; i < (sizeof(players)/sizeof(*players)); i++) {
        // use loops in order to iterate inside an array of structs
    }

    EnemySpaceShip enemy = getNewEnemy();                           // check struct.h file for more details
    enemy = upgradeWeapon(enemy);

    EnemyStarShip* p_enemy_first = get_new_enemy();                 // check struct.h file for more details
    EnemyStarShip* p_enemy_second = get_new_enemy();
    EnemyStarShip* p_current = p_enemies;                           // pointer to the current element of array
    while (p_current != NULL) {
        upgrade_weapon(p_current);
        p_current = p_current -> p_next_enemy;                      // assign pointer to the next element of array
    }


/*** ARRAY TYPE ***/
    const int max_number = 10;                                      // length of array must be set at compile time
    int simple_array[max_number];                                   // classic array init
    int two_dimension_array[3][3];                                  // two dimension array

    int summ_func = summ_array(simple_array, max_number);           // pass array to the func as an argument

    int* pointer_array = &simple_array[0];                          // pointer to the address of first element
    *pointer_array = 0;                                             // change value of first element
    pointer_array[0] = 1;                                           // change value of first element
    pointer_array += 1;                                             // pointer to the address of second element


/*** POINTERS IN DEPTH ***/
    int* null_pointer = nullptr;                                    // init pointer with null for safety
    int* empty_pointer;                                             // declare pointer without init (bad)
    int any_var_name = 17;
    int* any_pointer_name = &any_var_name;                          // pointer of type int
    *any_pointer_name = 27;
    /* <= the same as => */
    any_pointer_name[0] = 27;


/*** POINTER VS REFERENCE ***/
    int number_one = 10; int& ref = number_one; ref = 15;           // auto dereferenced pointer, called reference
    int number_two = 10; int* poi = &number_two; *poi = 15;         // classic pointer


/*** MEMORY MANAGEMENT ***/
    int* new_name_0 = new int;                                      // alloc of dynamic memory
    delete new_name_0;                                              // dealloc memory and set pointer equal to NULL
    new_name_0 = NULL;

    int* new_name_1 = new int(5);                                   // alloc dynamic memory and init with int
    int* new_name_2 = new int{5};

    int* new_name_3 = new int[5];                                   // alloc dynamic memory and init with array of ints
    int* new_name_4 = new int[5] {0, 1, 2, 3, 4};
    delete[] new_name_4;                                            // dealloc memory for array

    int* copy_shallow = new_name_2;                                 // shallow copy, the same object
    int* deep_copy = new int{*new_name_2};                          // deep copy, different object

    int** p_p_new_name;
    p_p_new_name = new int*[3];                                     // alloc dynamic memory for multidimensional array
    for (int i = 0; i < 3; i++) {
        p_p_new_name[i] = new int[3];
    }
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            p_p_new_name[i][j] = 0;
        }
    }
    for (int i = 0; i < 3; i++) {                                   // dealloc memory in reverse way
        delete[] p_p_new_name[i];
    }
    delete[] p_p_new_name;


/*** STL VECTOR DATA TYPE ***/
    vector<int> vd;                                                 // vector declaration

    vector<int> v {10, 3, 2, 7};                                    // vector init with elements
    v.push_back(4);                                                 // call build in methods
    v.size();

    vector<string> s(4);                                            // vector declaration with four default elements


/*** STL MAP DATA TYPE ***/
    map<string, string> name_to_email;
    name_to_email["Sergey"] = "sergey.melentyev@gmail.com";
    name_to_email["Olga"] = "olga.melentyev@gmail.com";
    name_to_email.size();
    name_to_email.erase("Sergey");
    if (name_to_email.empty()) { /* logic */ }


/*** STL ITERATORS ***/
    vector<int> vec_name;
    vec_name.push_back(1);
    vec_name.push_back(2);
    vector<int>::iterator itr_name = vec_name.begin();              // save address of the first index (pointer)
    itr_name++;                                                     // save address of the second index

    // iteration inside vector
    for (vector<int>:: iterator itr = vec_name.begin(); itr != vec_name.end(); ++itr) {
        // logic here
    }

    // iterate inside map
    for (map<string, string>:: iterator itr_map = name_to_email.begin(), end = name_to_email.end();
            itr_map != end; ++itr_map) {
        cout << itr_map -> first << " = " << itr_map -> second << endl;
    }


/*** CLASSES ***/
    custom_data_types token {'C', 14.0};                            // class init
    token.show_private_data();
    token.show_more();

    return 0;
}


int summ_array(int values[], int size) {                            // pass array as an argument to the func
    int sum = 0;
    for (int i = 0; i < size; i++)
    {
        sum += values[i];
    }
    return sum;
}
