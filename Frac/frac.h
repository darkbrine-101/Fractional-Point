#include <cstdint>
#include <cmath>

#pragma once

class frac {
public:
    frac(float number);
    frac(uint16_t numerator, int16_t denominator);
    int simplify();
    int set_numerator(int16_t new_numerator);
    int set_denominator(uint16_t new_denominator);
    uint16_t get_denominator();
    int16_t get_numerator();
    float acuracy = 0.0001;

    //operator overloading
    frac operator +(frac other_fraction);
    frac operator *(frac other_fraction);
    frac operator -(frac other_fraction);
    frac operator /(frac other_fraction);

    frac operator ++();
    frac operator --();
    frac operator ++(int);
    frac operator --(int);

private:
    uint16_t numerator;
    int16_t denominator;
    static const int primes[100];
};
