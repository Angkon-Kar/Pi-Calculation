// main.cpp
#include <iostream>
#include <iomanip>
#include <chrono>
#include "utils.h"
#include <cmath>

using namespace std;

const double truePi = 3.141592653589793;

void compareMethods(int leibnizTerms, int legendreIterations) {
    auto startL = chrono::high_resolution_clock::now();
    double piL = calculatePiLeibniz(leibnizTerms);
    auto endL = chrono::high_resolution_clock::now();
    
    auto startG = chrono::high_resolution_clock::now();
    double piG = calculatePiLegendre(legendreIterations);
    auto endG = chrono::high_resolution_clock::now();

    double errorL = fabs(truePi - piL);
    double errorG = fabs(truePi - piG);

    cout << fixed << setprecision(15);
    cout << "Leibniz Approximation: " << piL << " | Error: " << errorL << " | Time: " << chrono::duration<double>(endL - startL).count() << "s\n";
    cout << "Legendre Approximation: " << piG << " | Error: " << errorG << " | Time: " << chrono::duration<double>(endG - startG).count() << "s\n";
}

int main() {
    int leibnizTerms = 1000000;
    int legendreIterations = 5;
    compareMethods(leibnizTerms, legendreIterations);
    return 0;
}
