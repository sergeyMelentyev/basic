//
// Created by Melentyev on 07.07.16.
//

#include <iostream>
#include "custom_data_type.h"

void custom_data_type::show_private_data() {                                       //function definition
    std::cout << "\nprivate kind = "
              << kind
              << "\nprivate value = "
              << value;
}
void custom_data_type::show_more() const {
    std::cout << "\nHello\n";
}
