#include <iostream>
using namespace std;

void shellSort(int array[], int tamanho) {
   
    int intervalo = tamanho / 2;

   
    while (intervalo > 0) {
      
        for (int i = intervalo; i < tamanho; i++) {
            int temp = array[i];
            int j = i;

          
            while (j >= intervalo && array[j - intervalo] > temp) {
                array[j] = array[j - intervalo];
                j -= intervalo;
            }

            array[j] = temp;
        }

        
        intervalo /= 2;
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

    shellSort(array, tamanho);

    cout << "Array ordenado: ";
    imprimirArray(array, tamanho);

    return 0;
}
