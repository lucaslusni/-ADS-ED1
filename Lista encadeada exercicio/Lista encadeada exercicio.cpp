#include <iostream>
#include <string.h>

using namespace std;

struct Funcionario
{
    int prontuario;
    string nome;
    double salario;
    struct Funcionario *prox;
};

Funcionario *init()
{
    return NULL;
}

Funcionario *inserirFuncionario(Funcionario *lista, int i)
{
    Funcionario *novo = new Funcionario;
    novo->prontuario = i;
    novo->prox = lista;
    return novo;
}

Funcionario *removerFuncionario(Funcionario *lista, int i)
{
    Funcionario *ant = NULL;
    Funcionario *aux;

    aux = lista;
    while (aux != NULL && aux->prontuario != i)
    {
        ant = aux;
        aux = aux->prox;
    }
    if (aux == NULL)
    {
        return lista;
    }
    if (ant == NULL)
    {
        lista = aux->prox;
    }
    else
    {
        ant->prox = aux->prox;
    }
    free(aux);
    return lista;
}

void listarFuncionarios(Funcionario *lista)
{
    Funcionario *aux;
    aux = lista;
    int salario = 0;
    while (aux != NULL)
    {
        cout << "Numero prontuario: " << aux->prontuario << endl;
        cout << "Nome: " << aux->nome << endl;
        cout << "Salario: R$" << aux->salario << endl;

        salario = salario + aux->salario;
        aux = aux->prox;
    }
    cout << endl
         << "Total dos salarios: R$" << salario << endl;
}

Funcionario *procurarFuncionario(Funcionario *lista, int i)
{
    Funcionario *aux;
    aux = lista;
    while (aux != NULL && aux->prontuario != i)
    {
        aux = aux->prox;
    }
    if (aux == NULL)
    {
        aux = new Funcionario;
        aux->prontuario = -1;
        aux->prox = NULL;
    }
    return aux;
}

void freeList(Funcionario *lista)
{
    Funcionario *aux;
    aux = lista;
    while (aux != NULL)
    {
        Funcionario *ant = aux->prox;
        free(aux);
        aux = ant;
    }
}

int main()
{
    bool finaliza = false;

    int pront = 0, excluir = 0, pesquisar = 0;
    string nome;
    double salario;
    Funcionario *funcionarios;
    funcionarios = init();

    while (!finaliza)
    {
        int escolhaMenu = 0;

        cout << "---- MENU ----" << endl;
        cout << "0. Sair" << endl;
        cout << "1. Incluir" << endl;
        cout << "2. Excluir" << endl;
        cout << "3. Pesquisar" << endl;
        cout << "4. Listar" << endl;
        cout << "-------------" << endl;

        cout << "Escolha uma opção: " << endl;

        cin >> escolhaMenu;

        switch (escolhaMenu)
        {
        case 0:
            finaliza = true;
            break;
        case 1:
            cout << "--- Incluir um funcionario ---" << endl;
            pront++;
            funcionarios = inserirFuncionario(funcionarios, pront);
            cout << "Numero do prontuario - " << pront << endl;
            cout << "Digite o nome do funcionario: ";
            cin >> nome;
            funcionarios->nome = nome;
            cout << "Digite o salario: ";
            cin >> salario;
            funcionarios->salario = salario;
            cout << "Funcionario registrado!" << endl;
            break;
        case 2:

            if (pront > 0)
            {
                cout << "--- Excluir um funcionario ---" << endl;
                cout << "DIgite o numero do prontuario: ";
                cin >> excluir;
                funcionarios = removerFuncionario(funcionarios, excluir);
                cout << "Funcionario excluido!" << endl;
            }
            else
            {
                cout << "Insira um funcionario!" << endl;
            }

            break;
        case 3:

            if (pront > 0)
            {
                cout << "--- Pesquisar um funcionario ---" << endl;
                cout << "Digite o numero de prontuario: ";
                cin >> pesquisar;
                Funcionario *FuncionarioSelecionado;
                FuncionarioSelecionado = procurarFuncionario(funcionarios, pesquisar);
                cout << "Prontuario: " << FuncionarioSelecionado->prontuario << endl;
                cout << "Nome: " << FuncionarioSelecionado->nome << endl;
                cout << "Salario: " << FuncionarioSelecionado->salario << endl;
            }
            else
            {
                cout << "Insira um funcionario!" << endl;
            }

            break;
        case 4:
            if (pront > 0)
            {
                cout << "--- Lista dos funcionarios ativos ---" << endl;
                listarFuncionarios(funcionarios);
            }
            else
            {
                cout << "Insira um funcionario!" << endl;
            }
            break;
        default:
            cout << "Opção errada, selecione outra!";
            break;
        }
    }

    freeList(funcionarios);
    return 0;
}