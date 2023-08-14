#include "frac.h"

const int frac::primes[100] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97, 101, 103, 107, 109, 113, 127, 131, 137, 139, 149, 151, 157, 163, 167, 173, 179, 181, 191, 193, 197, 199, 211, 223, 227, 229, 233, 239, 241, 251, 257, 263, 269, 271, 277, 281, 283, 293, 307, 311, 313, 317, 331, 337, 347, 349, 353, 359, 367, 373, 379, 383, 389, 397, 401, 409, 419, 421, 431, 433, 439, 443, 449, 457, 461, 463, 467, 479, 487, 491, 499, 503, 509, 521, 523, 541};

frac::frac(float number) {

    float multiplier = 1;
    
    while (fmod(number * multiplier, 1) > acuracy){
        multiplier*=10;
    }
    numerator = number*multiplier;
    denominator = multiplier;
    simplify();
    
}
frac::frac(uint16_t new_numerator, int16_t new_denominator) {
    numerator = new_numerator;
    denominator = new_denominator;
    simplify();
}
int frac::simplify() {
    //returns number of simplifications
    int simplifications = 0;
    bool simplifying = true;
    while (simplifying) {
        simplifying = false;
        for (int prime : primes) {
            if (prime > numerator|| prime > denominator) {
                return simplifications;
            }
            if (numerator % prime == 0 && denominator % prime == 0) {
                numerator /= prime;
                denominator /= prime;
                ++simplifications;
                simplifying = true;
            }
        }
    }
    return simplifications;
}
int frac::set_numerator(int16_t new_numerator) {
    numerator = new_numerator;
    simplify();
    return 0;
}
int frac::set_denominator(uint16_t new_denominator) {
    denominator = new_denominator;
    simplify();
    return 0;
}
uint16_t frac::get_denominator() {
    return denominator;
}
int16_t frac::get_numerator() {
    return numerator;
}

//operator overloading

frac frac::operator +(frac other_fraction) {
    frac rtn = {0,0};
    rtn.set_numerator(
    (numerator*other_fraction.get_denominator()) + 
    (other_fraction.get_numerator() * denominator)
    );
    rtn.set_denominator(denominator * other_fraction.get_denominator());
    rtn.simplify();
    return rtn;
}
frac frac::operator *(frac other_fraction) {
    frac rtn = {0,0};
    rtn.set_denominator(other_fraction.get_denominator()*denominator);
    rtn.set_numerator(other_fraction.get_numerator() * numerator);
    rtn.simplify();
    return rtn;
}
frac frac::operator -(frac other_fraction) {
    frac rtn = {0,0};
    frac tmp = other_fraction;
    tmp.numerator*=-1;
    rtn = tmp + frac{numerator, denominator};
    rtn.simplify();
    auto x = rtn;
    return rtn;

}
frac frac::operator /(frac other_fraction) {
    frac rtn = {0,0};
    frac tmp = other_fraction;
    uint16_t tmp_numerator = tmp.get_numerator();
    tmp.set_numerator(tmp.get_denominator());
    tmp.set_denominator(tmp_numerator);
    rtn = tmp * frac{numerator, denominator };
    rtn.simplify();
    return rtn;
}
frac frac::operator ++() {
    numerator += denominator;
    return *this;

}
frac frac::operator --() {
    numerator -= denominator;
    return *this;
}

frac frac::operator ++(int) {
    frac rtn = *this;
    numerator += denominator;
    return rtn;

}
frac frac::operator --(int) {
    frac rtn = *this;
    numerator -= denominator;
    return rtn;
}