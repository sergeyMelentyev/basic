//
// Created by Melentyev on 18.08.16.
//

#include <iostream>
#include "Custom_class.h"


Custom_class::Custom_class(){                                                   // build-in constructor definition
    company = "no name";
    shares = 0;
    share_val = 0.0;
    total_val = 0.0;
}

Custom_class::Custom_class(const std::string& co, long num, double pr){         // custom constructor definition
    company = co;
    if (num < 0) {
        std::cout << "Number of shares cannot be negative;"
                  << company << " shares set to 0." << std::endl;
        shares = 0;
    } else
        shares = num;
    share_val = pr;
    set_total();
}

void Custom_class::acquire(const std::string& co, long num, double pr){
    company = co;
    if (num < 0) {
        std::cout << "Number of shares cannot be negative; "
                  << company << " shares set to 0." << std::endl;
        shares = 0;
    } else
        shares = num;
    share_val = pr;
    set_total();
}

void Custom_class::buy(long num, double price){
    if (num < 0) {
        std::cout << "Number of shares cannot be negative; "
                  << "Transaction aborted." << std::endl;
    } else {
        shares += num;
        share_val = price;
        set_total();
    }
}

void Custom_class::sell(long num, double price) {
    if (num < 0) {
        std::cout << "Number of shares sold cannot be negative. "
                  << "Transaction is aborted." << std::endl;
    } else if (num > shares) {
        std::cout << "You cannot sell more than you have. "
                  << "Transaction is aborted." << std::endl;
    } else {
        shares -= num;
        share_val = price;
        set_total();
    }
}

void Custom_class::update(double price) {
    share_val = price;
    set_total();
}

void Custom_class::show() {
    std::cout << "Company: " << company
              << " Shares: " << shares << "\n"
              << " Share Price: $" << share_val
              << " Total Worth: $" << total_val << std::endl;
}
