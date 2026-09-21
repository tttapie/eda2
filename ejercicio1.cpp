#include <cassert>
#include <string>
#include <iostream>
#include <limits>
#include "tads/AvlImp.cpp"

int main()
{
    int cantidadOperaciones;
    std::cin >> cantidadOperaciones;

    AVLImp<long long> monedas;
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

                long long catalogo;
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
                long long catalogo;
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
                long long desde, hasta;
                std::cin >> desde >> hasta;
                for (long long i = desde; i <= hasta; i++)
                {
                    if (monedas.buscar(i) == true)
                    {
                        std::cout << i << std::endl;
                    }
                }
            }
            else if (coleccion == 'P')
            {
                std::string desde, hasta;
                std::cin >> desde >> hasta;
                List<std::string> resultado = pinturas.rango(desde, hasta);
                for (int i = 0; i < resultado.getSize(); i = i + 1)
                {
                    std::cout << resultado.get(i) << std::endl;
                }
            }
        }
    }
}