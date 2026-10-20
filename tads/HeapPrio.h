#ifndef HEAP_PRIO_H
#define HEAP_PRIO_H

class HeapPrio
{
public:
    // pre: hay espacio disponible en el heap
    // post: agrega el numero con su prioridad y mantiene el min-heap
    virtual void insertar(int numero, int prioridad) = 0;

    // pre: el heap no esta vacio
    // post: elimina y devuelve el numero con menor prioridad; si empatan, devuelve el menor numero
    virtual int extraerMinimo() = 0;

    // pre: -
    // post: devuelve la cantidad actual de elementos del heap
    virtual int cantidadElem() = 0;
};

#endif