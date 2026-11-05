#include "Str_dicio.h"
#include "LZ78.h"
#include <iostream>
#include <string>
#include <cmath>

// Arrumando a string comprimida num array dos elementos comprimidos (*cpr)
string* LZ78::arrumar_compr(string user_compr){
    int tamanho = user_compr.length();

    //loop para descobrir o tamanho do vetor cpr
    int segmentos = 0;
    for (int i=0; i<tamanho; i++){
        if (user_compr[i] == '|') {
            segmentos++;
        }
    }

    string str_intermediaria;
    int count=0;

    //criando o vetor compressao *compr[segmentos]
    string *compr = new string[segmentos];
    for (int i=0; i<tamanho; i++){
        if (user_compr[i] == '|'){
            compr[count] = str_intermediaria;
            str_intermediaria = "";
            count++;
            continue;
        }
        str_intermediaria += user_compr[i];
    }
    segmentos_do_cpr = segmentos;
    return compr;
}

// Construtor
LZ78::LZ78(string user_text, string user_compr){
    txt = user_text;
    tam_texto = user_text.length();

    cpr = arrumar_compr(user_compr);

    dic_interm = new string *[tam_texto];
    for (int i=0; i<tam_texto; i++){
        dic_interm[i] = new string [2];
    }
}

// Compressao do txt
string LZ78::compressao(){
    int count=0, flag=0;
    int numb_char=0;

    while (flag==0){
        int prev = count;
        for (int i=count-1; i>=0; i--){
            if ((txt.substr(numb_char, dic_interm[i][1].length()) == dic_interm[i][1]) && (dic_interm[i][1].length() != 0)){

                //condicao para o ultimo termo nao selecionar errado
                //ex: a as as --> 0a|1s|1s| 
                //sem a condicao o ultimo termo seria 2|
                if (((numb_char + dic_interm[i][1].length() + 1) >= tam_texto) && 
                    (dic_interm[i][1].length() == txt.substr(numb_char, dic_interm[i][1].length()+1).length())){
                    continue;
                }
                
                else {

                    //adicionei a barra para separar melhor os segmentos
                    //ex: 000001 --> 00|10|21|
                    dic_interm[count][0] = to_string(i+1) + txt.substr(numb_char + dic_interm[i][1].length(), 1) + "|"; 
                    dic_interm[count][1] = txt.substr(numb_char, dic_interm[i][1].length()+1);

                    numb_char += dic_interm[i][1].length() + 1;
                    count += 1;
                    break;
                }
            }
        }

        //caso de ser um elemento isolado/novo
        if (prev == count){
            dic_interm[count][1] = txt.substr(numb_char, 1);
            dic_interm[count][0] = "0" + txt.substr(numb_char, 1) + "|";     
            numb_char += 1;
            count += 1;
        }

        //depois de ver todos os caracteres, sai do loop
        if (numb_char >= tam_texto){
            flag = 1;
        }
    }

    //ajeitando as informacoes
    string texto_apos_compressao;
    string *indx = new string[count];
    string *vals = new string[count];

    for (int i=0; i<count; i++){
        indx[i] = dic_interm[i][0];
        vals[i] = dic_interm[i][1];
        texto_apos_compressao += dic_interm[i][0];
    }

    //usando funcao herdada para guardar o dicionario arrumado
    criar_dic(indx, vals, count);
    delete[] indx;
    delete[] vals;
    return texto_apos_compressao;
}

// Descompressao do *cpr
string LZ78::descompressao(){
    string *ptr = new string[segmentos_do_cpr]; 
    string texto = "";
    cout << "\n";
    for (int i=0; i<segmentos_do_cpr; i++){
        if (cpr[i][0] == '0'){
            ptr[i] = cpr[i][cpr[i].length()-1];
        }
        else {

            /*  caso o segmento comprimido seja maior que 2 caracteres (ex 12a)
                se ve necessario uma lógica para ver todos os caracters iniciais e junta-los num unico numero decimal
                por isso o loop e o inteiro de potencia (pot)
            */
            int pos = 0;
            int pot = cpr[i].length()-2;
            for (int j=0; j<cpr[i].length()-1; j++){

                //cpr[i][j] n tava querendo ser convertido em inteiro, entao ele foi convertido pra tabela ASCII e subtraido 48
                pos += (int(cpr[i][j]) -48) * pow(10,pot);
                pot -=1;
            }
            pos -=1;
            
            ptr[i] = ptr[pos] + cpr[i][cpr[i].length()-1];
        }
        texto += ptr[i];
    }
    delete[] ptr;
    return texto;
}

// Sobrecarga do cout
ostream& operator<<(ostream& os, const LZ78& obj){
    cout << "Texto para comprimir: " << obj.txt;
    cout << "\nTexto para descomprimir: ";
    for (int i=0; i<obj.segmentos_do_cpr; i++){
        cout << obj.cpr[i] << "|";
    }
    os << "\n";
    return os;
}

// Funcao pro polimorfismo
void LZ78::print(){
    cout << "Texto para comprimir: " << txt;
    cout << "\nTexto para descomprimir: ";
    for (int i=0; i<segmentos_do_cpr; i++){
        cout << cpr[i] << "|";
    }
    cout << "\n";
}

// Destrutor
LZ78::~LZ78(){
    for (int i=0; i<tam_texto; i++){
        delete[] dic_interm[i];
    }
    delete[] dic_interm;
    //cout << "Lixo1 apagado\n";

    delete[] cpr;
    //cout << "Lixo3 apagado\n";
}