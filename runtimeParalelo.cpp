#include <iostream>
#include <vector>
#include <cmath>
#include <omp.h>

void procesarParaleloTiempo(long num_iteraciones) {
    int max_hilos = omp_get_max_threads();
    std::vector<int> contador_hilos(max_hilos, 0);

    double tiempo_inicio = omp_get_wtime();

    #pragma omp parallel
    {
        int id_hilo = omp_get_thread_num();

        #pragma omp for schedule(runtime)
        for (long i = 0; i < num_iteraciones; ++i) {
            double calculo = std::sin(i) * std::cos(i);
            contador_hilos[id_hilo]++;
        }
    }

    double tiempo_fin = omp_get_wtime();
    double tiempo_transcurrido_ms = (tiempo_fin - tiempo_inicio) * 1000.0;

    for (int i = 0; i < max_hilos; ++i) {
        std::cout << "Hilo " << i << " ejecuto: " << contador_hilos[i] << " iteraciones." << std::endl;
    }
    std::cout << "Tiempo de ejecucion: " << tiempo_transcurrido_ms << " ms\n" << std::endl;
}

int main() {
    procesarParaleloTiempo(10000000);
    return 0;
}