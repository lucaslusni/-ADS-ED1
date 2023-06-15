#include <iostream>
#include <vector>
#include <locale>

using namespace std;

void print(vector<int>& arr) {
    int aux = arr.size();

    cout << endl << "||-----------------------||" << endl;
    cout << "      Qtde de elementos: " << aux << endl;
    cout << "||-----------------------||" << endl;
}

void insertionSort(vector<int>& arr) {
    int n = arr.size();
    for (int i = 1; i < n; ++i) {
        int aux = arr[i];
        int j = i - 1;

        while (j >= 0 && arr[j] > aux) {
            arr[j + 1] = arr[j];
            j -= 1;
        }

        arr[j + 1] = aux;
    }
}

int main() {
    setlocale(LC_ALL, "portuguese");

    int arr_data[8] = {2, 5, 7, 3, 1, 4, 6, 8};
    vector<int> arr(arr_data, arr_data + sizeof(arr_data) / sizeof(arr_data[0]));
    
    
	cout << endl << "||-----------------------||" << endl;
    cout << "Array antes da ordenação: ";
    for (vector<int>::iterator it = arr.begin(); it != arr.end(); ++it) {
        cout << *it << " ";
    }
    cout << endl;

    insertionSort(arr);
	cout << endl << "||-----------------------||" << endl;
    cout << "Array após a ordenação: ";
    for (vector<int>::iterator it = arr.begin(); it != arr.end(); ++it) {
        cout << *it << " ";
    }
    cout << endl;

    print(arr);

    return 0;
}
