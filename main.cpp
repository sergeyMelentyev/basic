//
// Created by Melentyev on 07.07.16.
//

#include <iostream>
#include <vector>
#include "custom_data_types.h"

using namespace std;

int main() {

    char any_char_name = 'c';
    int any_var_name = 17;
    int* any_pointer_name = &any_var_name;                          // pointer of type int

    cout << "Address of any_var_name = " << any_pointer_name << "\n";
    cout << "Address of any_pointer_name = " << &any_pointer_name << "\n";
    cout << "Value at any_pointer_name = " << *any_pointer_name << "\n";
    *any_pointer_name = 27;
    cout << "Address of any_var_name = " << any_pointer_name << "\n";
    cout << "Address of any_pointer_name = " << &any_pointer_name << "\n";
    cout << "Value at any_pointer_name = " << *any_pointer_name << "\n";

    cout << "Size of char = " << sizeof(any_char_name) << "\n";
    cout << "Size of int = " << sizeof(any_var_name) << "\n";
    cout << "Size of pointer = " << sizeof(any_pointer_name) << "\n";

    vector<int> any_vector_name(1000);
    cout << "Size of vector = " << sizeof(any_vector_name) << "\n";

    int n = 2;
    double* p = new double[n];                                      // allocation in dynamic ram for n values
    cout << "Dynamic alloc = " << *p << "\n";
    int* i = new int;                                               // allocation in dynamic ram for one int
    cout << "Dynamic alloc = " << *i << "\n";


    vector<int> v = {10, 3, 2, 7};                                  // vector init
    vector<double> vd;                                              // vector declaration
    vector<string> s(4);                                            // vector declaration with four elements
    v.push_back(4);                                                 // add value to the end of the vector
    for (int x : v)                                                 // for in range loop
        cout << x;                                                  // cout function in std namespace

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
