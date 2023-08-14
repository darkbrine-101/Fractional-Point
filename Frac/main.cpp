#include "frac.h"
#include <iostream>

int main() {
	frac x = {1,3};
	frac y = {2, 3};
	frac z = ++x;
	std::cout<<z.get_numerator()/(float)z.get_denominator();
}