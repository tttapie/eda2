#ifndef Heap_IMP
#define Heap_IMP

#include "Heap.h"
#include <string>
#include <iostream>
#include <cstring>
#include <cstdint>

class HeapImp : public Heap
{
private:
    std::int64_t *array;
    std::int64_t cantElem;

public:
    HeapImp(std::int64_t largo)
    {
        cantElem = 0;
        array = new std::int64_t[largo + 1]; // lo hacemos en base 1
    }

    void flotar(std::int64_t pos)
    {
        while (true)
        {
            if (pos == 1)
                return;
            else
            {
                if (array[pos] < array[pos / 2])
                {
                    std::int64_t aux = array[pos];
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
    // se le pasan los 2 minimos
    std::int64_t consolidar()
    {
        std::int64_t min1 = array[1];
        borrar(1);

        std::int64_t min2 = array[1];
        borrar(1);

        std::int64_t costo = min1 + min2;
        insertar(costo);

        return costo;
    }

    void borrar(std::int64_t pos)
    {
        if (pos < 1 || pos > cantElem)
            return;

        array[pos] = array[cantElem];
        cantElem--;

        if (pos <= cantElem)
        {
            if (pos > 1 && array[pos] < array[pos / 2])
                flotar(pos);
            else
                hundir(pos);
        }
    }

    void hundir(std::int64_t pos)
    {
        while (true)
        {
            std::int64_t hijo = pos * 2; // hijo izquierdo 

            if (hijo > cantElem) 
                return;
            else
            {
                if (hijo + 1 <= cantElem && array[hijo + 1] < array[hijo]) // hijo es el izq ,hijo +1 es el derecho
                    hijo = hijo + 1; //toma el menor de los hijos 

                if (array[hijo] < array[pos]) // en el caso que no se cumpla con el min heap, osea que el nodo sea mayor que el hijo
                {
                    std::int64_t aux = array[pos];
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

    void insertar(std::int64_t valor)
    {
        array[cantElem + 1] = valor;
        cantElem++;
        flotar(cantElem);
    }

    std::int64_t cantidadElem (){
        return cantElem;
    }

};

#endif