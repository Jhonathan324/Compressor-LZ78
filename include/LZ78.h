#ifndef LZ78_H
#define LZ78_H

#include "Str_dicio.h"
#include <string>


class LZ78 : public Str_dicio {
    private:
        //atributos privados
        string **dic_interm;        //dicionario intermediario que n sera usado
        int tam_texto;

        //transforma a string de entrada em array
        string *arrumar_compr(string user_compr);

    public:
        //atributos gerais
        string txt;
        string *cpr;
        int unidades_compridas;     //quantos elementos o txt foi comprimido
        int segmentos_do_cpr;       //quantos elementos tinhna a compressao de entrada

        //construtor
        LZ78(string user_text="0", string user_compr="0");

        //compressao do txt
        string compressao();

        //descompressao do *cpr
        string descompressao();

        //sobrecarga do cout
        friend ostream& operator<<(ostream& os, const LZ78& obj);

        //outro metodo de impressao
        void print();

        //destrutor
        ~LZ78();

};

#endif
