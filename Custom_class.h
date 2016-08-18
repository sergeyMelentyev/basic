//
// Created by Melentyev on 18.08.16.
//

#ifndef CPP_LANG_CUSTOM_CLASS_H
#define CPP_LANG_CUSTOM_CLASS_H

#include <string>

class Custom_class {

private:
    std::string company;
    long shares;
    double share_val;
    double total_val;
    void set_total(){ total_val = shares * share_val; }                             // build-in func
    void set_grand_total();                                                         // build-in func prototype

public:
    Custom_class();                                                                 // build-in constructor prototype
    Custom_class(const std::string& co, long num, double pr);                       // custom constructor prototype
    void acquire(const std::string& co, long num, double pr);
    void buy(long num, double price);
    void sell(long num, double price);
    void update(double price);
    void show();
};

inline void Custom_class::set_grand_total() { total_val = shares * share_val; }     // build-in func definition

#endif
