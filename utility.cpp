// utility.cpp

// IN THIS FILE, define any of your OWN functions you may need to 
// solve the problems.    


// You will need to include the function prototype in "utility.h" and
// then be sure to  #include "utility.h" in the file where you use
// these functions
#include "utility.h"
#include <cmath>
using namespace std;

bool approxEqual(double a, double b, double tolerance) {
	return abs(a - b) <= tolerance;
}
