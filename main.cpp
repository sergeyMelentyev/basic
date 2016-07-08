//
// Created by Melentyev on 07.07.16.
//

#include <iostream>
#include <vector>
#include "Custom_Type.h"

using namespace std;

int main() {

    vector<int> v = {10, 3, 2, 7};                                  // vector init
    vector<double> vd;                                              // vector declaration
    vector<string> s(4);                                            // vector declaration with four elements
    v.push_back(4);                                                 // add value to the end of the vector
    for (int x : v)                                                 // for in range loop
        cout << x;                                                  // cout function in std namespace

    Custom_Type token {'C', 14.0};                                  // class init
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
