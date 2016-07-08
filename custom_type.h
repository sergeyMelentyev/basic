//
// Created by Melentyev on 07.07.16.
//

#ifndef CPP_LANG_TOKEN_H
#define CPP_LANG_TOKEN_H

class Custom_Type {                                                     // class definition
static const int min = 2014;                                            // create one const for all instances of the class

public:
    Custom_Type(char init_kind, double init_value)                      // custom init
            :kind{init_kind}, value{init_value}
    {
        // any init code here
    }

    void show_more(void) const;                                         // constant member of the class
    void show_private_data(void);                                       // function declaration

private:
    char kind;
    double value;
};


struct Date {                                                           // struct definition
    int year, month, day;
};


enum class Month {                                                      // scoped enumeration definition
    jan=1, feb, mar, apr, may, jun, jul, aug, sep, oct, nov, dec
};

enum Day {                                                             // simple enumeration
    mon=0, tue, wed, thr, fri, sat, sun
};

#endif //CPP_LANG_TOKEN_H
