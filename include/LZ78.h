#ifndef LZ78_H_INCLUDED
#define LZ78_H_INCLUDED

#include <iostream>
#include <string>
#include <cmath>

using namespace std;

class LZ78{
    private:
        string **dic_interm;
        int tam_texto;
        string arrumar_dic();
        string *arrumar_compr(string user_compr);

    public:
        string txt;
        string *cpr;
        string **dicio;
        int unidades_compridas;
        int segmentos_do_cpr;
        LZ78(string user_text="0", string user_compr="0");
        ~LZ78();
        string compressao();
        string descompressao();
        friend ostream& operator<<(ostream& os, const LZ78& obj);
};


#endif // LZ78_H_INCLUDED
