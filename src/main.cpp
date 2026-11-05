#include "LZ78.h"
#include <iostream>

int main(){
    LZ78 var("errd ee12e3", "0e|0r|2d|0 |1e|01|02|13|");
    string compr = var.compressao();
    string texto = var.descompressao();

    cout << var;
    var.print();
    
    //cout << "\nTexto apos compressao: " << compr;
    //cout << "\nTexto apos descompressao: " << texto << endl;

    return 0;
}