#include <iostream>
using namespace std;

void trocar(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void selectionSort(int array[], int tamanho) {
    for (int i = 0; i < tamanho - 1; i++) {
    
        int indiceMin = i;

        
        for (int j = i + 1; j < tamanho; j++) {
            if (array[j] < array[indiceMin]) {
                
                indiceMin = j;
            }
        }

        
        trocar(&array[indiceMin], &array[i]);
    }
}

void imprimirArray(int array[], int tamanho) {
    for (int i = 0; i < tamanho; i++) {
        cout << array[i] << " ";
    }
    cout << endl;
}

int main() {
    int array[] = { 64, 25, 12, 22, 11, 75, 90, 3 };
    int tamanho = sizeof(array) / sizeof(array[0]);

    cout << "Array original: ";
    imprimirArray(array, tamanho);

    selectionSort(array, tamanho);

    cout << "Array ordenado: ";
    imprimirArray(array, tamanho);

    return 0;
}
