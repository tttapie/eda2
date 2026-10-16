#include <string>
#include <iostream>
#include "tads/HashImp.cpp"

using namespace std;

bool primo(int n){
    if(n < 2){
        return false;
    }
    int i = 2;
    while(i * i <= n){
        if(n % i == 0){
            return false;
        }
        i++;
    }
    return true;
}

int sigPrimo(int n){

    while(!primo(n)){
        n++;
    }
    
    return n;
}

int main()
{
  
    int cantidadPalabras;
    std::cin >> cantidadPalabras;
    HashImp h(sigPrimo(cantidadPalabras));  
    
    for(int i = 0; i < cantidadPalabras ; i++){
        std::string palabra;
        std::cin >> palabra;
        
        h.registrar(palabra);
    }

    int consultas;
    std::cin >> consultas;
    for(int i = 0; i < consultas; i++){
        std::string palabra;
        std::cin >> palabra;

        std::cout << h.consultar(palabra) << std::endl;
    }

    std::cout << h.obtenerCantidadCajones() << ' ' << h.obtenerCajonGrande() << std::endl;
    
    return 0;
}