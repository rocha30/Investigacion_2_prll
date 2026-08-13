## Investigación #2

### Auto 

En la versión secuencial las iteraciones que necesitamos se ejecutan una después de otra. Lo que hacemos es tomar cada elemento del arreglo a, realizar la operación y luego guardar el resultado en el arreglo b.

En la versión paralela usamos schedule(auto). Con este tipo de scheduling nosotros no elegimos cómo se reparten las iteraciones entre los hilos, sino que dejamos esa decisión a la implementación de OpenMP. Lo usamos porque las iteraciones son independientes y realizan la misma cantidad de trabajo, por lo que podemos dejar que OpenMP decida el reparto sin tener que escoger manualmente una estrategia o un tamaño de chunk.

Los hilos se utilizan automáticamente al llegar al #pragma omp parallel for. La cantidad puede ser determinada por OpenMP o se puede fijar usando OMP_NUM_THREADS. En nuestra ejecución se utilizaron 8 hilos. Como usamos schedule(auto), no definimos manualmente un tamaño de chunk; esa decisión también queda a cargo de la implementación de OpenMP.

En la prueba, la versión secuencial tardó 0.242174 segundos, mientras que la versión paralela tardó 0.042264 segundos, obteniendo un speedup de 5.73x.

## Resultado de la ejecución

![Resultado de schedule(auto)](Auto.png)


### Runtime

