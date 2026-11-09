#ifndef STR_DICIO_H
#define STR_DICIO_H

#include <string>

using namespace std;

class Str_dicio{
    protected:
        //atributos
        string **dic;  //atributo que sera herdado
        int tam;

    public:
        //construtor
        Str_dicio();

        //metodo para criar dicionario
        void criar_dic(string *index, string *values, int tamanho);

        //impressao de dicionario
        void print() const;

        //retorna o tamanho do dicionario 
        int get_tam() const;

        //ver um elemento do dicionario
        string* get_entry(int i) const;

        //destrutor
        ~Str_dicio();
};

#endif
