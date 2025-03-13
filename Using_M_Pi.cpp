/*
Why Use M_PI?
It provides a high-precision value of π.
Avoids hardcoding 3.14159 manually.
Useful in trigonometric calculations like sin(), cos(), etc.
*/

#include <iostream>
#include <cmath> // Required for M_PI
#include <corecrt_math_defines.h>

using namespace std;

int main() {
    cout << "The value of Pi is: " << M_PI << endl;
    return 0;
}
