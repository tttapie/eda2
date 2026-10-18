#ifndef HEAP_PRIO_H
#define HEAP_PRIO_H

class HeapPrio
{
public:
    virtual void insertar(int numero, int prioridad) = 0;

    virtual int extraerMinimo() = 0;
    
    virtual int cantidadElem() = 0;
};

#endif