#include <ctime>
#include <iomanip>
#include <chrono>
#include <cstdlib>
#include <string>
#include <iostream>

using namespace std;
using namespace std::chrono;

#define MAX 15000
double A[MAX][MAX], x[MAX], y[MAX];

void primer_bucle() {
    for (size_t i = 0; i < MAX ; i++) {
        for (size_t j = 0; j < MAX ; j++) {
            y[i] += A[i][j] * x[j];
        }
    }
}

void segundo_bucle() {
    for (size_t j = 0; j < MAX ; j++) {
        for (size_t i = 0; i < MAX ; i++) {
            y[i] += A[i][j] * x[j];
        }
    }
}

void relleno(){
    for (size_t i = 0; i < MAX; ++i) {
        for (size_t j = 0; j < MAX; ++j) {
            A[i][j] = rand() % MAX;
        }
    }
    for (size_t i = 0; i < MAX; ++i) {
        x[i] = rand() % MAX;
        y[i] = rand() % MAX;
    }
}

void Tiempo_Primer_Bucle() {
    std::chrono::time_point<std::chrono::high_resolution_clock> start, end;
    start = std::chrono::high_resolution_clock::now();
    primer_bucle();
    end = std::chrono::high_resolution_clock::now();
    int64_t duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start).count();
    std::cout  << std::setw(30) << "Microseg: " + std::to_string(duration) + " us\n";
}

void Tiempo_Segundo_Bucle() {
    std::chrono::time_point<std::chrono::high_resolution_clock> start, end;
    start = std::chrono::high_resolution_clock::now();
    segundo_bucle();
    end = std::chrono::high_resolution_clock::now();
    int64_t duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start).count();
    std::cout  << std::setw(30) << "Microseg: " + std::to_string(duration) + " us\n";
}

int main() {
    relleno();
    cout << "Primer Bucle: " << endl;
    Tiempo_Primer_Bucle();
    cout << endl;
    cout << "Segundo Bucle: " << endl;
    Tiempo_Segundo_Bucle();
    return 0;
}
