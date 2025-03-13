#include <iostream>
#include <cmath>
#include <iomanip>
#include <chrono>

using namespace std;

double calculatePiLegendre(int iterations) {
    double a = 1.0;
    double b = 1.0 / sqrt(2);
    double t = 0.25;
    double p = 1.0;

    for (int i = 0; i < iterations; i++) {
        double aNext = (a + b) / 2;
        double bNext = sqrt(a * b);
        double tNext = t - p * (a - aNext) * (a - aNext);
        a = aNext;
        b = bNext;
        t = tNext;
        p *= 2;
    }

    return (a + b) * (a + b) / (4 * t);
}

int main() {
    int iterations = 5;
    auto start = chrono::high_resolution_clock::now();
    double pi = calculatePiLegendre(iterations);
    auto end = chrono::high_resolution_clock::now();

    cout << "Legendre Approximation: " << setprecision(15) << pi << endl;
    cout << "Execution Time: " << chrono::duration<double>(end - start).count() << " seconds" << endl;

    return 0;
}
