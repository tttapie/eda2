#ifndef HeapPrio_IMP
#define HeapPrio_IMP

#include "HeapPrio.h"
#include <string>
#include <iostream>
#include <cstring>
#include <cstdint>

class HeapPrioImp : public HeapPrio
{
private:
    struct Modulo
    {
        int numero;
        int prioridad;
    };
    Modulo *array; // guarda numeros de modulo
    int cantElem;

public:
    HeapPrioImp(int largo)
    { // base 1
        array = new Modulo[largo + 1];
        cantElem = 0;
    }

    bool antes(Modulo a, Modulo b)
    {
        if (a.prioridad == b.prioridad)
            return (a.numero < b.numero);
        else
            return (a.prioridad < b.prioridad);
    }

    void flotar(int pos)
    {
        while (true)
        {
            if (pos == 1)
                return;
            else
            {
                if (antes(array[pos], array[pos / 2]))
                {
                    Modulo aux = array[pos];
                    array[pos] = array[pos / 2];
                    array[pos / 2] = aux;
                    pos = pos / 2;
                }
                else
                {
                    return;
                }
            }
        }
    }

    void hundir(int pos)
    {
        while (true)
        {
            int hijo = pos * 2; // hijo izquierdo

            if (hijo > cantElem)
                return;
            else
            {
                if (hijo + 1 <= cantElem && antes(array[hijo + 1], array[hijo])) // hijo es el izq ,hijo +1 es el derecho
                    hijo = hijo + 1;                                             // toma el menor de los hijos

                if (antes(array[hijo], array[pos])) // en el caso que no se cumpla con el min heap, osea que el nodo sea mayor que el hijo
                {
                    Modulo aux = array[pos];
                    array[pos] = array[hijo];
                    array[hijo] = aux;
                    pos = hijo;
                }
                else
                {
                    return;
                }
            }
        }
    }

    void insertar(int numero, int prioridad)
    {
        cantElem++;
        array[cantElem].numero = numero;
        array[cantElem].prioridad = prioridad;
        flotar(cantElem);
    }

    int extraerMinimo(){
        Modulo minimo = array[1];
        array[1] = array[cantElem];
        cantElem--;

        if (cantElem > 0)
            hundir(1);

        return minimo.numero;
    }

    int cantidadElem (){
        return cantElem;
    }
};

#endif