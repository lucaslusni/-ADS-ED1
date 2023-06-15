#include <iostream>
using namespace std;


void merge(int array[], int baixo, int meio, int alto) {
    int tamanhoEsquerda = meio - baixo + 1;
    int tamanhoDireita = alto - meio;

  
    int esquerda[tamanhoEsquerda];
    int direita[tamanhoDireita];

   
    for (int i = 0; i < tamanhoEsquerda; i++) {
        esquerda[i] = array[baixo + i];
    }

 
    for (int j = 0; j < tamanhoDireita; j++) {
        direita[j] = array[meio + 1 + j];
    }


    int indiceEsquerda = 0;
    int indiceDireita = 0;
    int indiceMerge = baixo;


    while (indiceEsquerda < tamanhoEsquerda && indiceDireita < tamanhoDireita) {
        if (esquerda[indiceEsquerda] <= direita[indiceDireita]) {
            array[indiceMerge] = esquerda[indiceEsquerda];
            indiceEsquerda++;
        } else {
            array[indiceMerge] = direita[indiceDireita];
            indiceDireita++;
        }
        indiceMerge++;
    }

   
    while (indiceEsquerda < tamanhoEsquerda) {
        array[indiceMerge] = esquerda[indiceEsquerda];
        indiceEsquerda++;
        indiceMerge++;
    }

 
    while (indiceDireita < tamanhoDireita) {
        array[indiceMerge] = direita[indiceDireita];
        indiceDireita++;
        indiceMerge++;
    }
}


void mergeSort(int array[], int baixo, int alto) {
    if (baixo < alto) {
        int meio = baixo + (alto - baixo) / 2;

    
        mergeSort(array, baixo, meio);

    
        mergeSort(array, meio + 1, alto);

       
        merge(array, baixo, meio, alto);
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

    mergeSort(array, 0, tamanho - 1);

    cout << "Array ordenado: ";
    imprimirArray(array, tamanho);

    return 0;
}
