#include <iostream>
using namespace std;

// Função para trocar dois elementos
void trocar(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}


int particionar(int array[], int baixo, int alto) {
    int pivot = array[alto]; 
    int i = (baixo - 1); 

    for (int j = baixo; j <= alto - 1; j++) {
        
        if (array[j] <= pivot) {
            i++; 
            trocar(&array[i], &array[j]);
        }
    }
    trocar(&array[i + 1], &array[alto]);
    return (i + 1);
}


void quickSort(int array[], int baixo, int alto) {
    if (baixo < alto) {
    
        int pi = particionar(array, baixo, alto);

        
        quickSort(array, baixo, pi - 1);
        quickSort(array, pi + 1, alto);
    }
}


void imprimirArray(int array[], int tamanho) {
    for (int i = 0; i < tamanho; i++) {
        cout << array[i] << " ";
    }
    cout << endl;
}


int main() {
	setlocale(LC_ALL, "portuguese");
    int array[] = { 12,15,19, 64, 25, 12, 22, 11 };
    int tamanho = sizeof(array) / sizeof(array[0]);

    cout << "Array original: ";
    imprimirArray(array, tamanho);

    quickSort(array, 0, tamanho - 1);

    cout << "Array ordenado: ";
    imprimirArray(array, tamanho);

    return 0;
}






