#include <iostream>
#include <ctime>
using namespace std;

// METODO 10: RADIX SORT
// -- Ordena los números por sus dígitos, de menor a mayor posición (base 10).
int getMax(int vec[], int n) {
    int maxVal = vec[0];
    for (int i = 1; i < n; i++)
        if (vec[i] > maxVal)
            maxVal = vec[i];
    return maxVal;
}

void countSortRadix(int vec[], int n, int exp) {
    int output[n];
    int count[10] = {0};

    for (int i = 0; i < n; i++)
        count[(vec[i] / exp) % 10]++;

    for (int i = 1; i < 10; i++)
        count[i] += count[i - 1];

    for (int i = n - 1; i >= 0; i--) {
        output[count[(vec[i] / exp) % 10] - 1] = vec[i];
        count[(vec[i] / exp) % 10]--;
    }

    for (int i = 0; i < n; i++)
        vec[i] = output[i];
}

void radixSort(int vec[], int n) {
    int maxVal = getMax(vec, n);
    for (int exp = 1; maxVal / exp > 0; exp *= 10)
        countSortRadix(vec, n, exp);
}

int main() {
    const int n = 1000;
    int vec[n];
    for (int i = 0; i < n; i++)
        vec[i] = n - i; // Arreglo descendente

    cout << "\nORDENANDO " << n << " ELEMENTOS CON RADIX SORT\n-----------------------------------------\n";

    clock_t inicio = clock();
    radixSort(vec, n);
    clock_t fin = clock();

    double tiempo = double(fin - inicio) / CLOCKS_PER_SEC;

    cout << "Ordenamiento completado.\n";
    cout << "Tiempo de ejecucion: " << tiempo << " segundos.\n";

    cout << "-----------------------------------------\nORDENADOS:\n";
    for (int i = 0; i < n; i++)
        cout << vec[i] << " ";

    return 0;
}
