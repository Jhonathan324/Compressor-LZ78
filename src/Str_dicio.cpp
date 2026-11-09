#include "Str_dicio.h"
#include <iostream>
#include <string>

// Construtor
Str_dicio::Str_dicio(){
    //dic sera herdado
    dic = nullptr;
    tam = 0;
}

// Cria dicionario (metodo que sera herdado)
void Str_dicio::criar_dic(string *index, string *values, int tamanho){
    //libera o dicionario anterior
    if (dic != nullptr) {
        for (int i = 0; i < tam; i++) {
            delete[] dic[i];
        }
        delete[] dic;
    }

    tam = tamanho;

    dic = new string*[tam];

    for (int i = 0; i < tam; i++) {
        dic[i] = new string[2];

        dic[i][0] = index[i];
        dic[i][1] = values[i];
    }
}

// Exibe o dicionario
void Str_dicio::print() const {
    for (int i = 0; i < tam; i++) {
        cout << "{" << dic[i][0] << " : " << dic[i][1] << "} ";
    }
    cout << "\n";
}

// Retorna o tamanho do dicionario
int Str_dicio::get_tam() const {
    return tam;
}

// Retorna uma entrada do dicionario
string* Str_dicio::get_entry(int i) const {
    if (i < 0 || i >= tam) {
        return nullptr;
    }

    return dic[i];
}

// Destrutor
Str_dicio::~Str_dicio() {
    for (int i = 0; i < tam; i++) {
        delete[] dic[i];
    }

    delete[] dic;
}
