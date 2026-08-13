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

    printf("========================================\n");
    printf(" Loop Scheduling - schedule(auto)\n");
    printf("========================================\n");
    printf("Iteraciones: %d\n", N);
    printf("Hilos utilizados: %d\n", omp_get_max_threads());
    printf("Scheduling: auto\n");
    printf("Chunk: no definido manualmente\n\n");


    // Version secuencial

    // Version secuencial
double inicio = omp_get_wtime();

    for (int i = 0; i < N; i++) {
        double x = a[i];

        for (int j = 0; j < 100; j++) {
            x = x * 1.000001 + 1;
        }

        b[i] = x;
    }

    double fin = omp_get_wtime();
    double tiempo_sec = fin - inicio;

    printf("Secuencial:      %f segundos\n", tiempo_sec);


    // Version paralela con auto

    // Version paralela
    inicio = omp_get_wtime();

    #pragma omp parallel for schedule(auto)
    for (int i = 0; i < N; i++) {
        double x = a[i];

        for (int j = 0; j < 100; j++) {
            x = x * 1.000001 + 1;
        }

        b[i] = x;
    }

    fin = omp_get_wtime();
    double tiempo_par = fin - inicio;

    printf("Paralelo (auto): %f segundos\n", tiempo_par);


    // Comparacion

    printf("\nSpeedup: %.2fx\n", tiempo_sec / tiempo_par);

    printf("========================================\n");

    return 0;
}