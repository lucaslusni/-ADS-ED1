#include <iostream>
#include <string>
#include <windows.h>

using namespace std;

int main()
{
    string mensagem = "";
    cout << "Digite uma mensagem: ";
    getline(cin, mensagem);

    int tamanhoMensagem = mensagem.length();

    int espacosAntes = (80 - tamanhoMensagem) / 2;

    for (int i = 0; i < espacosAntes; i++)
    {
        cout << " ";
    }

    cout << mensagem << endl;

    for (int i = 0; i < 15; i++)
    {
        Sleep(1000);
        system("cls");

        for (int j = 0; j < espacosAntes; j++)
        {
            cout << " ";
        }
        for (int j = 0; j < tamanhoMensagem; j++)
        {
            if (i == j)
            {
                cout << mensagem[j];
            }
            else
            {
                cout << " ";
            }
        }
        cout << endl;
    }

    return 0;
}