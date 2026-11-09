#include "LZ78.h"
#include <iostream>

int main(){
    LZ78 var("errd ee12e3", "0e|0r|2d|0 |1e|01|02|13|");
    string compr = var.compressao();
    string texto = var.descompressao();

    cout << var;
    //var.print();
    
    cout << "\nTexto apos compressao: " << compr;
    cout << "\nTexto apos descompressao: " << texto << endl;

    return 0;
}

//Exemplos de strings para testar compressao:
//    "aaaaaswdddeaas" --> a aa aas w d dd e a aas --> "0a|1a|2s|0w|5d|0e|2s|"
//    "aababacbaacbaadaaa" --> a ab aba c b aa cb aad aaa --> "0a|1b|2a|0c|0b|1a|4b|6d|6a|"
//    "1111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111" --> muito 1 :D
