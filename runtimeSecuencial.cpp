#include <iostream>
#include <cmath>
#include <chrono>

void procesarSecuencialTiempo(long num_iteraciones) {
    int iteraciones_realizadas = 0;

    auto inicio = std::chrono::high_resolution_clock::now();

    for (long i = 0; i < num_iteraciones; ++i) {
        double calculo = std::sin(i) * std::cos(i);
        iteraciones_realizadas++;
    }

    auto fin = std::chrono::high_resolution_clock::now();
    
    std::chrono::duration<double, std::milli> tiempo_transcurrido = fin - inicio;

    std::cout << "Iteraciones: " << iteraciones_realizadas << std::endl;
    std::cout << "Tiempo de ejecucion: " << tiempo_transcurrido.count() << " ms\n" << std::endl;
}

int main() {
    procesarSecuencialTiempo(10000000);
    return 0;
}
