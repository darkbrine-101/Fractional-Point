#include "frac.h"

frac::frac(float number){   
    numerator = 0;
    denominator = 0;
}
frac::frac(uint16_t new_numerator, int16_t new_denominator){
    numerator = new_numerator;
    denominator = new_denominator;
    simplify();
}
int frac::simplify(){
    /* 
        returns number of simplifications 
    */
    int simplifications = 0;
    bool simplifying = true;
    while (simplifying){
        simplifying = false;
        for (int prime : primes){
            if (prime > numerator/2 || prime > denominator/2){
                return simplifications;
            }
            if (numerator%prime == 0 && denominator%prime == 0){
                numerator/=prime;
                denominator/=prime;
                ++simplifications;
                simplifying = true;
            }
        }
    }
    return simplifications;
}
int frac::set_numerator(uint16_t new_numerator){
    return numerator;
}
int frac::set_denominator(int16_t new_denominator){
    return denominator;
}
int16_t frac::get_denominator(){
    return 0;
}
uint16_t frac::get_numerator(){
    return 0;
}

