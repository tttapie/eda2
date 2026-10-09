#include <cassert>
#include <string>
#include <iostream>
#include <limits>
#include <cstdint>
#include "tads/AvlImp.cpp"

int main()
{
    int cantidadOperaciones;
    std::cin >> cantidadOperaciones;
    AVLImp<std::int64_t> monedas;
    AVLImp<std::string> pinturas;

    for (int i = 0; i < cantidadOperaciones; i++)
    {
        std::string operacion;
        char coleccion;

        std::cin >> operacion >> coleccion;

        if (operacion == "ALTA")
        {
            if (coleccion == 'M')
            {

                std::int64_t catalogo;
                std::cin >> catalogo;
                monedas.insertar(catalogo);
            }
            else if (coleccion == 'P')
            {
                std::string titulo;
                std::cin >> titulo;
                pinturas.insertar(titulo);
            }
        }

        if (operacion == "BUSCAR")
        {
            if (coleccion == 'M')
            {
                std::int64_t catalogo;
                std::cin >> catalogo;
                if (monedas.buscar(catalogo) == true)
                {
                    std::cout << "SI" << std::endl;
                }
                else
                {
                    std::cout << "NO" << std::endl;
                }
            }
            else if (coleccion == 'P')
            {
                std::string titulo;
                std::cin >> titulo;
                if (pinturas.buscar(titulo) == true)
                {
                    std::cout << "SI" << std::endl;
                }
                else
                {
                    std::cout << "NO" << std::endl;
                }
            }
        }
        if (operacion == "RANGO")
        {
            if (coleccion == 'M')
            {
                std::int64_t desde, hasta;
                std::cin >> desde >> hasta;
                List<std::int64_t> *resultado = monedas.rango(desde, hasta); //devuelve solo las monedas que realmente estan guardadas dentro del rango

                for (int i = 0; i < resultado->getSize(); i++)
                {
                    std::cout << resultado->get(i) << std::endl; //resultado->get(i) obtiene el elemento que esta en la posicion i de la lista
                } //Imprime ese elemento y baja una línea
            }
            else if (coleccion == 'P')
            {
                std::string desde, hasta;
                std::cin >> desde >> hasta;
                List<std::string> *resultado = pinturas.rango(desde, hasta);
                for (int i = 0; i < resultado->getSize(); i = i + 1)
                {
                    std::cout << resultado->get(i) << std::endl;
                }
            }
        }
    }
}
