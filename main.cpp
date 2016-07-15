//
// Created by Melentyev on 07.07.16.
//

#include <iostream>
#include <vector>
#include "custom_data_types.h"

using namespace std;

/* pointer vs reference */
    int any_function_name(int x) { return x+1; }
    void any_function_name(int* x) { ++*x; }
    void any_function_name(int& x) { ++x; }

int main() {
    constexpr int max_value = 100;									// constant expression must be assigned
    const int min_value = 100 / max_value;							// constant classic can be assign at compile time
    double d {2.7};													// universal and uniform initialization

/* pointers in depth */
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

/* pointer vs reference */
    int number_one = 10; int& ref = number_one; ref = 15;           // auto dereferenced pointer, called reference
    int number_two = 10; int* poi = &number_two; *poi = 15;         // classic pointer

/* vector in depth */
    vector<int> v {10, 3, 2, 7};                                    // vector init with passed elements
    v.push_back(4);                                                 // add value to the end of the vector
    vector<double> vd;                                              // vector declaration
    vector<string> s(4);                                            // vector declaration with four default elements

/* array in depth */
    const int max_number = 100;                                     // length of array must be set at compile time
    int simple_array[max_number];                                   // classic array init
    int* pointer_array = &simple_array[0];                          // pointer to the address of first element
    *pointer_array = 0;                                             // change value of first element
    pointer_array[0] = 1;                                           // change value of first element
    pointer_array += 1;                                             // pointer to the address of second element

/* custom data types in depth */
    custom_data_types token {'C', 14.0};                            // class init
    token.show_private_data();
    token.show_more();

    Date today;                                                     // struct init
    today.day = 7;
    today.month = 6;
    today.year = 2016;

    Month current = Month::jul;                                     // scoped enumeration
    Day this_day = sun;                                             // simple enumeration
    Day next_day = Day::mon;

    return 0;
}
