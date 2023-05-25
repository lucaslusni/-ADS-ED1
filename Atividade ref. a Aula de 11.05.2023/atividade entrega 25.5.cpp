#include <iostream>
using namespace std;

struct No {
	float dado;
	struct No* prox;
};

struct Pilha {
	No* topo;
};

Pilha* init() {
	Pilha* p = new Pilha();
	p->topo = NULL;
	return p;
}

int isEmpty(Pilha* p) {
	return (p->topo == NULL);
}

int countPilha(Pilha* p) {
	int i = 0;
	No* no = p->topo;
	while (no != NULL) {
		i++;
		no = no->prox;
	}
	return i;
}

void print(Pilha* p) {
	No* no = p->topo;
	cout << endl << "||-----------------------||" << endl;
	cout << "      Qtde de elementos: " << countPilha(p) << endl;
	cout << "||-----------------------||" << endl;
	while (no != NULL) {
		cout << no->dado << endl;
		no = no->prox;
	}
	cout << "--------------" << endl;
}

void push(Pilha* p, float v) {
	No* no = new No();
	no->dado = v;
	no->prox = p->topo;
	p->topo = no;
}

float pop(Pilha* p) {
	float ret;
	int podeDesempilhar = (!isEmpty(p));
	if (podeDesempilhar) {
		No* no = p->topo;
		ret = no->dado;
		p->topo = p->topo->prox;
		delete no;
	}
	else {
		ret = -1;
	}
	return ret;
}

void freePilha(Pilha* p) {
	No* no = p->topo;
	while (no != NULL) {
		No* aux = no->prox;
		delete no;
		no = aux;
	}
	delete p;
}

int main(int argc, char** argv) {
	Pilha* pilhaPar = init();
	Pilha* pilhaImpar = init();

	int numAnterior = -1;
	int num;
	for (int i = 0; i < 30; i++) {
		cout << "Digite o " << (i + 1) << "o numero: ";
		cin >> num;

		if (num > numAnterior) {
			if (num % 2 == 0) {
				push(pilhaPar, num);
			}
			else {
				push(pilhaImpar, num);
			}
			numAnterior = num;
		}
		else {
			cout << "Numero invalido! Digite um numero maior que o anterior." << endl;
			i--; 
		}
	}

	cout << " imprimindo a pilha de numeros pares: ";
	print(pilhaPar);

	cout << " imprimindo a pilha de numeros impares: ";
	print(pilhaImpar);


	freePilha(pilhaPar);
	freePilha(pilhaImpar);

	return 0;
}
