#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "mpi.h"

//mpic++ experiment.cpp -o out
//./out

const int MAX = 100;

void generar_bools(bool b[], int n){
    for(int i =0; i < n; i++){
        b[i] = true;
    }
}

bool is_sorted (bool b[], int n){
    for (int i = 0; i < n; i ++){ 
        if(b[i] == false){
            return false;
        }
    }
    return true;
}

void odd_even_logic(int a[], bool b[]){
    if (*a > *(a+1)) {
        int temp = *a;
        *a = *(a+1);
        *(a+1) = temp;
        *b = false;
    }
}

void Odd_even_sort(int a[], bool b[], int n) {
    bool sorted = false;
    int rank, size;

    //MPI_Init(NULL,NULL);
    //MPI_Comm_rank(MPI_COMM_WORLD, &rank); 
    //MPI_Comm_size(MPI_COMM_WORLD, &size); 

    //MPI_Status status;

    while(!sorted){
        generar_bools(b,n);
        for (int i = 1; i < n-1; i += 2){ //even
            //MPI_Send(&value[0],1,MPI_INT,rank+1,0,MPI_COMM_WORLD);
            odd_even_logic(a+i, b+i); //cambiar for para el mpi
            
        }
        for (int i = 0; i < n - 1; i += 2){ //odd
            //MPI_Recv(&value[1],1,MPI_INT,rank+1,0,MPI_COMM_WORLD,&status);
            odd_even_logic(a+i, b+i); //cambiar for para el mpi
            
        }
        sorted = is_sorted(b,n);
    }

    //MPI_Gather(&value[0],1,MPI_INT,&arr[0],1,MPI_INT,0,MPI_COMM_WORLD);
    //if(rank==0) {
        //printf("Sorted array: ");
        //for (i=0;i<tamArray;i++) {
            //printf("%d ", arr[i]);
        //}
    //printf("\n");
    //}

    //MPI_Finalize();
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
    int n=100;
    int a[100]];
    bool b[100];

    Generate_list(a, n);
    Print_list(a, n);

    cout<<"tiempo que se demora: "<<endl;
    std::chrono::time_point<std::chrono::high_resolution_clock> start, end;
    start = std::chrono::high_resolution_clock::now();
    Odd_even_sort(a,b,n);
    end = std::chrono::high_resolution_clock::now();
    int64_t duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start).count();
    std::cout  << std::setw(30) << "Microseg: " + std::to_string(duration) + " us\n";

    Print_list(a, n);

    return 0;
} 