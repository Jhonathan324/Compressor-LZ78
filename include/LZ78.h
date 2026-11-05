#ifndef LZ78_H
#define LZ78_H

#include "Str_dicio.h"
#include <string>


class LZ78 : public Str_dicio {
    private:
        string **dic_interm;
        int tam_texto;

        string *arrumar_compr(string user_compr);

    public:
        string txt;
        string *cpr;
        int unidades_compridas;
        int segmentos_do_cpr;
    
        LZ78(string user_text="0", string user_compr="0");

        string compressao();

        string descompressao();

        friend ostream& operator<<(ostream& os, const LZ78& obj);

        void print();

        ~LZ78();

};

#endif
