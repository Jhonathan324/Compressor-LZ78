Código de Compressão estilo LZ78
  Projeto de implementação do algoritmo de compressão LZ78, desenvolvido em C++.

Requisitos:
  - CMake 4.5.0
  - Compilador C++ compatível com C++17.

Uso:
  Dentro da função main.cpp, crie uma variável de classe LZ78 no formato variavel("texto que quer comprimir", "texto comprimido na formatação correta")
    - A formatação correta de um texto comprimido é a separação do termos usando '|' (ex: "0a|0b|1c|")
  Após criada a variável, é preciso apenas chamar as funções variavel.compressao() e variavel.descompressao() que elas retornarão os textos alterados
  Para compilar os códigos siga as instruções sobre o uso do Cmake.

Compilação:
  Execute os seguintes comandos no CMD, dentro da pasta raiz do projeto:
    cmake -S . -B build
    cmake --build build

Executável:
  Após a compilação, o executável estará localizado em:
    build\Debug\Compressor.exe
