#ifndef CONJUNTOS_DISJUNTOS_H
#define CONJUNTOS_DISJUNTOS_H

class ConjuntosDisjuntos
{
public:
    // pre: 0 <= elemento < cantidad de elementos
    // post: devuelve el representante del conjunto y comprime el camino
    virtual int encontrar(int elemento) = 0;

    // pre: ambos elementos pertenecen al rango valido
    // post: devuelve true y une sus conjuntos si eran distintos; si ya eran iguales devuelve false
    virtual bool unir(int elemento1, int elemento2) = 0;

    // pre: -
    // post: devuelve la cantidad actual de conjuntos disjuntos
    virtual int cantidadComponentes() = 0;
};

#endif