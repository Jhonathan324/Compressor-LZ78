#include "LZ78.h"

int main(){

    LZ78 var("errd ee12e3", "01|11|21|31|41|51|61|71|81|91|101|111|121|31|");
    string compr = var.compressao();
    string texto = var.descompressao();
    cout << var;
    cout << "\nTexto apos compressao: " << compr;
    cout << "\nTexto apos descompressao: " << texto << endl;

    return 0;
}
