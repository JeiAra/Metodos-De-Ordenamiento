#include <iostream>
#include <ctime>
using namespace std;

// METODO 9: COUNTING SORT
// -- Ordena contando ocurrencias de cada número (solo para enteros no negativos).
void countingSort(int vec[], int n) {
    int maxVal = vec[0];
    for (int i = 1; i < n; i++)
        if (vec[i] > maxVal)
            maxVal = vec[i];

    int count[maxVal + 1] = {0};

    for (int i = 0; i < n; i++)
        count[vec[i]]++;

    int idx = 0;
    for (int i = 0; i <= maxVal; i++) {
        while (count[i]-- > 0)
            vec[idx++] = i;
    }
}

int main() {
    const int n = 1000;
    int vec[n];
    for (int i = 0; i < n; i++)
        vec[i] = n - i; // Arreglo descendente

    cout << "\nORDENANDO " << n << " ELEMENTOS CON COUNTING SORT\n-----------------------------------------\n";

    clock_t inicio = clock();
    countingSort(vec, n);
    clock_t fin = clock();

    double tiempo = double(fin - inicio) / CLOCKS_PER_SEC;

    cout << "Ordenamiento completado.\n";
    cout << "Tiempo de ejecucion: " << tiempo << " segundos.\n";

    cout << "-----------------------------------------\nORDENADOS:\n";
    for (int i = 0; i < n; i++)
        cout << vec[i] << " ";

    return 0;
}
