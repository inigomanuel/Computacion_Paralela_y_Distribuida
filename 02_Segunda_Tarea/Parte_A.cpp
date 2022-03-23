#include <iostream>
#include <cmath>
#include <chrono>
using namespace std;

int** A;
int** B;
int** C;

int n=1500;
int m=1500;
int k=1500;

void Rserva_de_Memoria(){
	A = new int*[n];
	for(int i = 0; i < n; ++i)
		A[i] = new int[m];
	B = new int*[m];
	for(int i = 0; i < m; ++i)
		B[i] = new int[k];
	C = new int*[n];
	for(int i = 0; i < n; ++i)
		C[i] = new int[k];
}

void Relleno(){
	for (int i = 0; i < n; ++i){
		for (int j = 0; j < m; ++j){
			int temp = rand() % 300;
			A[i][j] = temp;
		}
	}
	for (int i=0; i < m; ++i){
		for (int j=0; j<k; ++j){
			int temp=rand() % 300;
			B[i][j]=temp;
		}
	}
	for (int i=0; i < n; ++i){
		for (int j=0; j<k; ++j){
			C[i][j]=0;
		}
	}
}

void Multiplicacion_Clasica(){ 
	for (int i = 0; i < n; i++) {
        for (int j = 0; j < k; j++) {
            for (int k = 0; k < m; k++) {
                C[i][j] = C[i][j] + A[i][k] * B[k][j];
            }
        }
    }
}

int main() {
	Rserva_de_Memoria();
	Relleno();
	std::chrono::time_point<std::chrono::high_resolution_clock> start, end;
	start = std::chrono::high_resolution_clock::now();
	Multiplicacion_Clasica();
	end = std::chrono::high_resolution_clock::now();
	int64_t duration = std::chrono::duration_cast<std::chrono::nanoseconds>(end - start).count();
	std::cout <<"Prueba Clasica en nanosegundos: "<< duration;
	cout<<endl;
	return 0;
}