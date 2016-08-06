//
// Created by Melentyev on 07.07.16.
//

#include <iostream>
#include <vector>
#include <array>
#include <map>
#include "struct.h"

using namespace std;                                                // using namespace
using std::cout;

int summ_array(int values[], int size);                             // function prototype


/*** POINTER VS REFERENCE ***/
    int any_function_name(int x) { return x+1; }
    void any_function_name(int* x) { ++*x; }
    void any_function_name(int& x) { ++x; }


int main() {
    constexpr int Max_value = 100;									// must be assigned before compilation
    const int Min_value = 100 / Max_value;							// constant classic can be assign at compile time
    int any_name_one = 2;                                           // simple initialization
    int any_name_two (2);                                           // alternative initialization
    int any_name_three {2};     									// universal and uniform initialization
    int any_name_four = {2};                                        // universal and uniform initialization

    double type_cast_one = double(any_name_three);                   // type casting
    double type_cast_two = static_cast<double>(any_name_four);


/*** ENUM TYPE ***/
    enum RainbowColor {
        RC_RED = 1,
        RC_ORANGE = 3,
        RC_YELLOW
    };
    RainbowColor choose_color = RC_ORANGE;


/*** UNION TYPE ***/
    union one4all {                                                 // union can hold only one value at a time
        int int_value;
        long long_value;
        double double_value;
    };


/*** STRUCT TYPE ***/
    struct PlayerInfo {
        string name;
        int skill_level;
    };

    PlayerInfo playerOne = { "Oleg", 10 };                          // create and init a struct
    PlayerInfo playerTwo {};                                        // create a struct and init with zero
    PlayerInfo playerThree;                                         // create a struct
    playerThree.name = "Sergey";
    playerThree.skill_level = 10;

    PlayerInfo players_first[2];                                    // create an array of structs
    for (int i = 0; i < (sizeof(players_first)/sizeof(*players_first)); i++) { }
    PlayerInfo players_second[2] {                                  // create an array of struct
        {"Sergey", 10}, {"Olga", 10}
    };

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
    int simple_array_one[max_number];                               // classic array init
    int simple_array_two[4] = {3, 6};
    int simple_array_three[] {3, 6};                                // init array with two ints
    int simple_array_four[100] = {};                                // init array with all zero

    int two_dimension_array[3][3];                                  // two dimension array

    int summ_func = summ_array(simple_array_one, max_number);       // pass array to the func as an argument

    int* pointer_array_one = simple_array_one;                      // pointer to the address of first element
    int* pointer_array_two = &simple_array_one[0];
    *pointer_array_two = 0;                                         // change value of first element
    pointer_array_two[0] = 1;                                       // change value of first element
    pointer_array_two += 1;                                         // pointer to the address of second element


/*** POINTERS IN DEPTH ***/
    int* null_pointer = nullptr;                                    // init pointer with null for safety
    int* empty_pointer;                                             // declare pointer without init (bad)
    int any_var_name = 17;
    int* any_pointer_name = &any_var_name;                          // pointer of type int
    *any_pointer_name = 27;                                         // assign a new value to the any_var_name
    
    int x_ptr = *++any_pointer_name;                                // increment pointer, take the value
    int y_ptr = ++*any_pointer_name;                                // increment taken value

    PlayerInfo s01, s02, s03;                                       // init three structs of type PlayerInfo
    s01.skill_level = 1;
    PlayerInfo *pa = &s02;                                          // init a pointer of type PlayerInfo
    pa->skill_level = 1;
    PlayerInfo trio[3];                                             // init an array of three structs
    trio[0].skill_level = 1;
    const PlayerInfo * arp[3] {&s01, &s02, &s03};                   // init an array of three pointers
    cout << arp[0]->skill_level << endl;
    const PlayerInfo ** ppa = arp;                                  // init a pointer to the array of pointers


/*** POINTER VS REFERENCE ***/
    int number_one = 10; int& ref = number_one; ref = 15;           // auto dereferenced pointer, called reference
    int number_two = 10; int* poi = &number_two; *poi = 15;         // classic pointer


/*** MEMORY MANAGEMENT (STACK/STATIC/HEAP) ***/
    // auto variable in function use stack memory
    // static variable exist with program`s life circle
    // dynamic memory called (heap)

    int* new_name_0 = new int;                                      // alloc of dynamic memory
    delete new_name_0;                                              // dealloc memory and set pointer equal to NULL
    new_name_0 = NULL;

    int* new_name_1 = new int(5);                                   // alloc dynamic memory and init with int
    int* new_name_2 = new int{5};

    int* new_name_3 = new int[5];                                   // alloc dynamic memory and init with array of ints
    int* new_name_4 = new int[5] {0, 1, 2, 3, 4};
    delete[] new_name_4;                                            // dealloc memory for array

    int* shallow_copy = new_name_2;                                 // shallow copy, the same object
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


    PlayerInfo * ps = new PlayerInfo;                               // alloc dynamic memory for struct object
    ps -> name = "Sergey";                                          // access property
    ps -> skill_level = 10;
    delete ps;


/*** STL VECTOR OBJECT DATA TYPE ***/
    // vector object uses heap memory
    vector<int> vd;                                                 // vector declaration
    vector<string> s(4);                                            // vector declaration with four default elements
    vector<int> v {10, 3, 2, 7};                                    // vector init with elements
    v.push_back(4);                                                 // call build-in method
    v.size();


/*** STL ARRAY OBJECT DATA TYPE ***/
    // array object uses stack memory
    array<int, 5> stl_array;
    array<int, 2> stl_arr {1, 2};


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
