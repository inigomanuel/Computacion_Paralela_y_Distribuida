#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include <ctime>
#include <chrono>
#include <iomanip>
#include <iostream>
using namespace std::chrono;
using namespace std;

const int MAX = 100;

void Odd_even_sort(int a[], int n) {
    bool sorted = false;
    while(!sorted){
        sorted = true;
        for (int i = 1; i < n-1; i += 2){ //even
            if (a[i] > a[i+1]) {
                int temp = a[i];
                a[i] = a[i + 1];
                a[i + 1] = temp;
                sorted = false;
            }
        }
        for (int i = 0; i < n-1; i += 2){ //odd
            if (a[i] > a[i + 1]) {
                int temp = a[i];
                a[i] = a[i + 1];
                a[i + 1] = temp;
                sorted = false;
            }
        }
    }
} 

void Generate_list(int a[], int n) {
    int i;
    for (i = 0; i < n; i++)
        a[i] = rand() % MAX;
} 

void Print_list(int a[], int n) {
    int i;
    for (i = 0; i < n; i++){
        printf("%d ", a[i]);
    }
    printf("\n\n");
}


int main() {
    int n=1000;
    int a[1000];
    Generate_list(a, n);
    Print_list(a, n);

    cout<<"tiempo que se demora: "<<endl;
    std::chrono::time_point<std::chrono::high_resolution_clock> start, end;
    start = std::chrono::high_resolution_clock::now();
    Odd_even_sort(a, n);
    end = std::chrono::high_resolution_clock::now();
    int64_t duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start).count();
    std::cout  << std::setw(30) << "Microseg: " + std::to_string(duration) + " us\n";
    
    Print_list(a, n);

    return 0;
} 