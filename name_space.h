//
// Created by Melentyev on 07.07.16.
//

#include <iostream>

#ifndef CPP_LANG_NAME_SPACE_H
#define CPP_LANG_NAME_SPACE_H

namespace Graph_Lib {                                   // create a new namespace Graph_Lib::Color
    struct Color {
        int color_code = 254;
    };
    struct Shape {
        int number_sides = 4;
    };
}

#endif //CPP_LANG_NAME_SPACE_H
