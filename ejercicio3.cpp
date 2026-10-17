#include <iostream>
#include "tads/HeapImp.cpp"  
#include <cstdint>
using namespace std;

int main()
{
    std::int64_t cantArchivos;
    std::cin >> cantArchivos;
    HeapImp h(cantArchivos);

    std::int64_t costo = 0;
    for(int i = 0 ; i < cantArchivos ; i++){
        std::int64_t tam = 0 ;
        std::cin >> tam;

        h.insertar(tam);
    }
    
    while(h.cantidadElem() > 1){
        costo += h.consolidar();
    }
    
    std:: cout << costo << std::endl;

}