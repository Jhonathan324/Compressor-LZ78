#include <iostream>
#include <string>
#include <cmath>

using namespace std;

class LZ78{
    private:
        string **dic_interm;
        int tam_texto;

        string arrumar_dic(){
            
            /* essa funcao tem dois objetivos
               1: transformar o dicionario intermediario num dicionario com o tamanho correto
               2: retornar a string da compressao do algoritmo para a funcao de comprimir
            */

            string compres;

            dicio = new string *[unidades_compridas];
            for (int i=0; i<unidades_compridas; i++){
                dicio[i] = new string [2];
            }

            for (int i=0; i<unidades_compridas; i++){
                dicio[i][0] = dic_interm[i][0];
                dicio[i][1] = dic_interm[i][1];
                compres += dicio[i][0];
            }
            return compres;
        }

        string *arrumar_compr(string user_compr){
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

    public:
        string txt;
        string *cpr;
        string **dicio;
        int unidades_compridas;
        int segmentos_do_cpr;
    
        LZ78(string user_text="0", string user_compr="0"){
            txt = user_text;
            tam_texto = user_text.length();

            cpr = arrumar_compr(user_compr);

            dic_interm = new string *[tam_texto];
            for (int i=0; i<tam_texto; i++){
                dic_interm[i] = new string [2];
            }
        }

        ~LZ78(){
            for (int i=0; i<tam_texto; i++){
                delete[] dic_interm[i];
            }
            delete[] dic_interm;
            //cout << "Lixo1 apagado\n";

            for (int i=0; i<unidades_compridas; i++){
                delete[] dicio[i];
            }
            delete[] dicio;
            //cout << "Lixo2 apagado\n";

            delete[] cpr;
            //cout << "Lixo3 apagado\n";
        }

        string compressao(){
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

            unidades_compridas = count;

            //ajeitando as informacoes
            string texto_apos_compressao = arrumar_dic();
            return texto_apos_compressao;
        }

        string descompressao(){
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

        //sobrecarga do cout
        friend ostream& operator<<(ostream& os, const LZ78& obj){
            cout << "Texto para comprimir: " << obj.txt;
            cout << "\nTexto para descomprimir: ";
            for (int i=0; i<obj.segmentos_do_cpr; i++){
                cout << obj.cpr[i] << "|";
            }
            os << "\n";
            return os;
        }
};

int main(){

    LZ78 var("errd ee12e3", "01|11|21|31|41|51|61|71|81|91|101|111|121|31|");
    string compr = var.compressao();
    string texto = var.descompressao();
    cout << var;
    cout << "\nTexto apos compressao: " << compr;
    cout << "\nTexto apos descompressao: " << texto << endl;

    return 0;
}
