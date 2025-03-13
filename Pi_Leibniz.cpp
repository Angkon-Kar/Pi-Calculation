#include <iostream>
#include <iomanip>
#include <chrono>


using namespace std;

double calculatePiLeibniz(int terms) {
    double pi = 0.0;
    for (int i = 0; i < terms; i++) {
        double term = 4.0 / (2 * i + 1);
        pi += (i % 2 == 0) ? term : -term;
    }
    return pi;
}

int main() {
    int terms = 1000000;
    auto start = chrono::high_resolution_clock::now();
    double pi = calculatePiLeibniz(terms);
    auto end = chrono::high_resolution_clock::now();

    cout << "Leibniz Approximation: " << setprecision(15) << pi << endl;
    cout << "Execution Time: " << chrono::duration<double>(end - start).count() << " seconds" << endl;

    return 0;
}
