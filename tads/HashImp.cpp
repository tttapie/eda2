#ifndef Hash_IMP
#define Hash_IMP

#include "Hash.h"
#include "ListImp.cpp"
#include <cassert>


template <class T> // T es una clase generica, es un tipo que se elige al usarla
class HashImp : public Hash<T>
{
private:
    List<T> **tabla; // array de listas
    int largo;

public:
    HashImp(int cantBuckets) // El constructor: se ejecuta al crear el hash, por ejemplo new HashImp<long long>(1000), y recibe el largo del array
    {
        largo = cantBuckets;
        tabla = new List<T> *[largo];
        for (int i = 0; i < largo; i++)
        {
            tabla[i] = new ListImp<T>();
        }
    }

    



    
};

#endif