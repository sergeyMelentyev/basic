//
// Created by Melentyev on 07.07.16.
//

#include <iostream>
#include <vector>
#include "struct.h"
#include "custom_data_types.h"

using namespace std;
int summ_array(int values[], int size);                            // function prototype

/* pointer vs reference */
    int any_function_name(int x) { return x+1; }
    void any_function_name(int* x) { ++*x; }
    void any_function_name(int& x) { ++x; }

int main() {
    constexpr int max_value = 100;									// constant expression must be assigned
    const int min_value = 100 / max_value;							// constant classic can be assign at compile time
    double d {2.7};													// universal and uniform initialization

/* ENUM TYPE */
    enum RainbowColor {
        RC_RED = 1,
        RC_ORANGE = 3,
        RC_YELLOW
    };
    RainbowColor choose_color = RC_ORANGE;

/* STRUCT TYPE */
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

    EnemySpaceShip enemy = getNewEnemy();                           // check struct.h file
    enemy = upgradeWeapon(enemy);

/* ARRAY TYPE */
    const int max_number = 10;                                      // length of array must be set at compile time
    int simple_array[max_number];                                   // classic array init
    int two_dimension_array[3][3];                                  // two dimension array

    int summ_func = summ_array(simple_array, max_number);           // pass array to the func as an argument

    int* pointer_array = &simple_array[0];                          // pointer to the address of first element
    *pointer_array = 0;                                             // change value of first element
    pointer_array[0] = 1;                                           // change value of first element
    pointer_array += 1;                                             // pointer to the address of second element

/* POINTERS IN DEPTH */
    int any_var_name = 17;
    int* any_pointer_name = &any_var_name;                          // pointer of type int
    *any_pointer_name = 27; /* <= the same as => */ any_pointer_name[0] = 27;

    int* new_name_0 = nullptr;                                      // init pointer with null for safety
    int* new_name_1;                                                // declare pointer without init (bad)
    int* new_name_2 = new int;                                      // alloc of dynamic ram without init
    int* new_name_3 = new int(5);                                   // init pointer with value of 5
    int* new_name_4 = new int{5};
    int* new_name_5 = new int[5];                                   // alloc of dynamic ram for array of 5 int
    int* new_name_6 = new int[5] {0, 1, 2, 3, 4};                   // alloc and init array of 5 int

    int* copy_shallow = new_name_4;                                 // shallow copy, the same object
    int* deep_copy = new int{*new_name_4};                          // deep copy, different object

    delete new_name_5;                                              // dealloc memory for one obj
    delete[] new_name_6;                                            // dealloc memory for array

    int n = 2;
    double* p = new double[n];                                      // allocation in dynamic ram for n values
    cout << "Dynamic alloc = " << *p << "\n";                       // *p or p[0] print first element
    int* i = new int;                                               // alloc in dynamic ram for array of one int
    cout << "Dynamic alloc = " << *i << "\n";

/* POINTER VS REFERENCE */
    int number_one = 10; int& ref = number_one; ref = 15;           // auto dereferenced pointer, called reference
    int number_two = 10; int* poi = &number_two; *poi = 15;         // classic pointer

/* VECTOR IN DEPTH */
    vector<int> v {10, 3, 2, 7};                                    // vector init with passed elements
    v.push_back(4);                                                 // add value to the end of the vector
    vector<double> vd;                                              // vector declaration
    vector<string> s(4);                                            // vector declaration with four default elements

/* custom data types in depth */
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
