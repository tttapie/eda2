#ifndef COLA_SENDEROS_H
#define COLA_SENDEROS_H
 
struct Sendero
{
    int refugio1;
    int refugio2;
    int costo;
};
 
// Cola de prioridad de senderos: el de menor costo es el de mayor prioridad
class ColaSenderos
{
public:
    // PRE: la cola no esta llena
    // POS: el sendero queda en la cola en el lugar que le toca segun su costo
    virtual void insertar(Sendero s) = 0;
 
    // PRE: la cola no esta vacia
    // POS: devuelve el sendero mas barato sin sacarlo
    virtual Sendero tope() = 0;
 
    // PRE: la cola no esta vacia
    // POS: saca el sendero mas barato
    virtual void desencolar() = 0;
 
    // POS: devuelve true si la cola no tiene senderos
    virtual bool esVacia() = 0;
 
    
};
 
#endif