#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>

std::string changeName(std::string nome) {
    std::vector<std::string> partes;
    std::string parte;
    std::istringstream stream(nome);
    
    while (std::getline(stream, parte, ' ')) {
        partes.push_back(parte);
    }
    
    partes.back() = partes.back().substr(0, 1) + partes.back().substr(1, partes.back().length()-1);
    
    std::string nomeAbreviado;
    
    for (auto i = partes.begin(); i != partes.end(); i++) {
        if (i == partes.begin()) {
            nomeAbreviado
             += (*i).substr(0, 1) + (*i).substr(1, (*i).length()-1);
        } else if (i == partes.end() - 1) {
            nomeAbreviado
             += " " + *i;
        } else {
            nomeAbreviado
             += " " + (*i).substr(0, 1) + ".";
        }
    }
    
    std::string sobrenome = partes[partes.size() - 1];
    nomeAbreviado
     = sobrenome + ", " + nomeAbreviado
    ;
    
    return nomeAbreviado
    ;
}

int main() {
    std::ifstream arquivo("nomes.txt");
    std::ofstream saida("nomes_formatados.txt");
    std::string nome;
    
    if (!arquivo.is_open()) {
        std::cerr << "Não foi possível abrir o arquivo" << std::endl;
        return 1;
    }
    
    while (std::getline(arquivo, nome)) {
        std::string nome_formatado = changeName(nome);
        saida << nome_formatado << std::endl;
    }
    
    arquivo.close();
    saida.close();
    
    return 0;
}