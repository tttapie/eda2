#ifndef CONJUNTOS_DISJUNTOS_IMP
#define CONJUNTOS_DISJUNTOS_IMP

#include "DisjointSet.h"
#include <vector>

class ConjuntosDisjuntosImp : public ConjuntosDisjuntos
{
private:
    std::vector<int> padre;
    std::vector<int> altura;
    int componentes;

public:
    ConjuntosDisjuntosImp(int cantidad)
    {
        padre = std::vector<int>(cantidad);
        altura = std::vector<int>(cantidad, 0);
        componentes = cantidad;

        for (int i = 0; i < cantidad; i++)
        {
            padre[i] = i;
        }
    }

    int encontrar(int elemento)
    {
        int raiz = elemento;
        while (padre[raiz] != raiz)
        {
            raiz = padre[raiz];
        }

        while (padre[elemento] != raiz)
        {
            int siguiente = padre[elemento];
            padre[elemento] = raiz;
            elemento = siguiente;
        }

        return raiz;
    }

    bool unir(int elemento1, int elemento2)
    {
        int raiz1 = encontrar(elemento1);
        int raiz2 = encontrar(elemento2);

        if (raiz1 == raiz2)
        {
            return false;
        }

        if (altura[raiz1] < altura[raiz2])
        {
            padre[raiz1] = raiz2;
        }
        else if (altura[raiz1] > altura[raiz2])
        {
            padre[raiz2] = raiz1;
        }
        else
        {
            padre[raiz2] = raiz1;
            altura[raiz1]++;
        }

        componentes--;
        return true;
    }

    int cantidadComponentes()
    {
        return componentes;
    }
};

#endif