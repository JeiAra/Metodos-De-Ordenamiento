#include <iostream>
#include <ctime>
using namespace std;

// METODO 8: SHELL SORT
// -- Variante del insertion sort que compara elementos a cierta distancia (gap) decreciente.
void shellSort(int vec[], int n) {
    for (int gap = n / 2; gap > 0; gap /= 2) {
        for (int i = gap; i < n; i++) {
            int temp = vec[i];
            int j;
            for (j = i; j >= gap && vec[j - gap] > temp; j -= gap)
                vec[j] = vec[j - gap];
            vec[j] = temp;
        }
    }
}

int main() {
    const int n = 1000;
    int vec[n];
    for (int i = 0; i < n; i++)
        vec[i] = n - i; // Arreglo descendente

    cout << "\nORDENANDO " << n << " ELEMENTOS CON SHELL SORT\n-----------------------------------------\n";

    clock_t inicio = clock();
    shellSort(vec, n);
    clock_t fin = clock();

    double tiempo = double(fin - inicio) / CLOCKS_PER_SEC;

    cout << "Ordenamiento completado.\n";
    cout << "Tiempo de ejecucion: " << tiempo << " segundos.\n";

    cout << "-----------------------------------------\nORDENADOS:\n";
    for (int i = 0; i < n; i++)
        cout << vec[i] << " ";

    return 0;
}
