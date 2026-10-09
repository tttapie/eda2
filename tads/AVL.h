#ifndef AVL_H
#define AVL_H

#include "List.h"

template <class T>
class AVL {
public:
    // pre: -
    // post: inserta el elemento en el arbol, si ya estaba no hace nada
    virtual void insertar(T elemento) = 0;
    // pre: -
    // post: devuelve true si el elemento esta en el arbol
    virtual bool buscar(T elemento) = 0;
    // pre: desde <= hasta
    // post: devuelve una lista con los elementos que estan entre desde y hasta (incluidos)
    virtual List<T>* rango(T desde, T hasta) = 0;
};

#endif