//
// Created by melentyev on 07.07.16.
//

#include <iostream>

#ifndef CPP_LANG_MAIN_TYPES_H
#define CPP_LANG_MAIN_TYPES_H

double d {2.7};													// universal and uniform initialization

double f = 2.7;                                                 // classic initialization

constexpr int max_value = 100;									// constant expression must be assigned

const int min_value = 100 / max_value;							// constant classic can be assign at compile time

double y = 2.5 / double(2);                                     // type casting

int z = 2 / int{'a'} + 1;

#endif //CPP_LANG_MAIN_TYPES_H
