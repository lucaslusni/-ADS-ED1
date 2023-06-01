#include <iostream>
#include <cstdlib>
using namespace std;

struct No
{
    int dado;
    No *prox;
};

struct Fila
{
    No *ini;
    No *fim;
};

Fila *init()
{
    Fila *f = new Fila;
    f->ini = NULL;
    f->fim = NULL;
    return f;
}

int isEmpty(Fila *f)
{
    return (f->ini == NULL);
}

int count(Fila *f)
{
    int qtde = 0;
    No *no;
    no = f->ini;
    while (no != NULL)
    {
        qtde++;
        no = no->prox;
    }
    return qtde;
}

void print(Fila *f)
{
    No *no;
    no = f->ini;
    cout << "-------------" << endl;
    while (no != NULL)
    {
        cout << no->dado << endl;
        no = no->prox;
    }
    cout << "-------------" << endl;
}

int valor(Fila *f)
{
    No *no;
    no = f->ini;
    int valor = 0;

    if (no != NULL)
    {
        valor = no->dado;
    }

    return valor;
}

void enqueue(Fila *f, int v)
{
    No *no = new No;
    no->dado = v;
    no->prox = NULL;
    if (isEmpty(f))
    {
        f->ini = no;
    }
    else
    {
        f->fim->prox = no;
    }
    f->fim = no;
}

float dequeue(Fila *f)
{
    float ret;
    if (isEmpty(f))
    {
        ret = -1;
    }
    else
    {
        No *no = f->ini;
        ret = no->dado;
        f->ini = no->prox;
        if (f->ini == NULL)
        {
            f->fim = NULL;
        }
        free(no);
    }
    return ret;
}

void freeFila(Fila *f)
{
    No *no = f->ini;
    while (no != NULL)
    {
        No *temp = no->prox;
        free(no);
        no = temp;
    }
    free(f);
}

int main()
{
    Fila *senhaGeradas;
    senhaGeradas = init();

    Fila *senhaAtendidas;
    senhaAtendidas = init();

    int escolhaMenu = 0;

    do
    {
        cout << "0. SAIR" << endl;
        cout << "1. GERAR SENHA" << endl;
        cout << "2. REALIZAR ATENDIMENTO" << endl;

        cin >> escolhaMenu;

        switch (escolhaMenu)
        {
        case 0:
            isEmpty(senhaGeradas) ? escolhaMenu = 0 : escolhaMenu = -1;
            break;
        case 1:
            cout << "--- GERANDO SENHA ---" << endl
                 << endl;
            enqueue(senhaGeradas, rand());
            break;
        case 2:
            cout << "--- ATENDIMENTO ---" << endl
                 << endl;
            cout << "Senha: " << valor(senhaGeradas) << endl;
            enqueue(senhaAtendidas, valor(senhaGeradas));
            dequeue(senhaGeradas);
            cout << "Quantidade de senha aguardando atendimento: " << count(senhaGeradas) << endl
                 << endl;
            break;
        default:
            cout << "Digite uma opção valida!";
            break;
        }
    } while (escolhaMenu != 0);

    cout << "Quantidade de senhas atendidas: " << count(senhaAtendidas) << endl;

    freeFila(senhaGeradas);
    freeFila(senhaAtendidas);
}