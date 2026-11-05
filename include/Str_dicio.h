#ifndef STR_DICIO_H
#define STR_DICIO_H

#include <string>

using namespace std;

class Str_dicio{
    protected:
        string **dic;
        int tam;

    public:
        Str_dicio();

        void criar_dic(string *index, string *values, int tamanho);

        void print() const;
        
        int get_tam() const;
        
        string* get_entry(int i) const;
        
        ~Str_dicio();
};

//  Matriz arr(3, 3, 2, 2) <-- 3 dimensões, 3 matrizes 2x2
//  Matriz arz(2, 3, 3)
//  Matriz arx(3, {2, 3, 3})

#endif