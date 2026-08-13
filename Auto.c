// Loop Scheduling: auto

#include <stdio.h>
#include <omp.h>

#define N 1000000

int main(void) {

    static double a[N], b[N];

    // Llenar arreglo
    for (int i = 0; i < N; i++) {
        a[i] = i * 1.0;
    }


//Version secuencial

    double inicio = omp_get_wtime();

    for (int i = 0; i < N; i++) {
        b[i] = a[i] * a[i] + 1;
    }

    double fin = omp_get_wtime();

    printf("Secuencial: %f segundos\n", fin - inicio);


//version paralela con auto 
    inicio = omp_get_wtime();

    #pragma omp parallel for schedule(auto)
    for (int i = 0; i < N; i++) {
        b[i] = a[i] * a[i] + 1;
    }

    fin = omp_get_wtime();

    printf("Paralelo (auto): %f segundos\n", fin - inicio);

    return 0;
}