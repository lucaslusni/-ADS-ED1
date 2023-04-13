#include <iostream>
#include <string.h>

using namespace std;

class Data
{
private:
    int dia;
    int mes;
    int ano;

public:
    Data(int dia, int mes, int ano)
    {
        this->dia = dia;
        this->mes = mes;
        this->ano = ano;
    }

    Data()
    {
        this->dia = 13;
        this->mes = 05;
        this->ano = 2003;
    }

    void setDia(int dia)
    {
        this->dia = dia;
    }

    void setMes(int mes)
    {
        this->mes = mes;
    }

    void setAno(int ano)
    {
        this->ano = ano;
    }

    int getDia()
    {
        return this->dia;
    }

    int getMes()
    {
        return this->mes;
    }

    int getAno()
    {
        return this->ano;
    }

    string getData()
    {
        return to_string(this->dia) + "/" +
               to_string(this->mes) + "/" +
               to_string(this->ano);
    }
};

class Contato
{
private:
    string email;
    string nome;
    string telefone;
    Data dtnasc;

public:
    Contato(string nome, string email, string telefone, Data *data)
    {
        this->nome = nome;
        this->email = email;
        this->telefone = telefone;
        this->dtnasc = *data;
    }

    void setNome(string nome)
    {
        this->nome = nome;
    }

    string getNome()
    {
        return this->nome;
    }

    void setEmail(string email)
    {
        this->email = email;
    }

    string getEmail()
    {
        return this->email;
    }

    void setTelefone(string telefone)
    {
        this->telefone = telefone;
    }

    string getTelefone()
    {
        return this->telefone;
    }

    void setData(Data data)
    {
        this->dtnasc = data;
    }

    Data getData()
    {
        return this->dtnasc;
    }

    int idade()
    {
        return 2023 - dtnasc.getAno();
    }
};

int main()
{
    Contato *contatos[5];
    Data *datas[5];

    string nome = "";
    string email = "";
    string telefone = "";
    int dia = 0;
    int mes = 0;
    int ano = 0;

    for (int i = 0; i < 5; ++i)
    {

        cout << "---- CADASTRO DE CONTATO ----" << endl;
        cout << "Digite um nome:  ";
        cin >> nome;

        cout << "Digite um email: ";
        cin >> email;

        cout << "Digite um telefone: ";
        cin >> telefone;

        cout << "Digite o dia de nascimento: ";
        cin >> dia;

        cout << "Digite o mes de nascimento: ";
        cin >> mes;

        cout << "Digite o ano de nascimento: ";
        cin >> ano;
        cout << "------------------------------------------------" << endl;

        datas[i] = new Data(dia, mes, ano);
        contatos[i] = new Contato(nome, email, telefone, datas[i]);
    }

    for (int i = 0; i < 5; ++i)
    {
        cout << "---- EXIBINDO CADASTRO ----" << endl;
        cout << "Nome: " << contatos[i]->getNome() << endl;
        cout << "Email: " << contatos[i]->getEmail() << endl;
        cout << "Telefone: " << contatos[i]->getTelefone() << endl;
        cout << "Idade: " << contatos[i]->idade() << endl;
        cout << endl;
    }

    return 0;
}