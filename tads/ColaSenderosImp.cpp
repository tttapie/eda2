#ifndef COLA_SENDEROS_IMP
#define COLA_SENDEROS_IMP
 
#include "ColaSenderos.h"
 
// min-heap sobre arreglo, ordenado por costo
class ColaSenderosImp : public ColaSenderos
{
private:
    Sendero *vec; // en base 1
    int cant;
 
    void intercambiar(int a, int b)
    {
        Sendero aux = vec[a];
        vec[a] = vec[b];
        vec[b] = aux;
    }
 
    // sube el sendero mientras sea mas barato que su padre
    void flotar(int pos)
    {
        if (pos > 1 && vec[pos].costo < vec[pos / 2].costo)
        {
            intercambiar(pos, pos / 2);
            flotar(pos / 2);
        }
    }
 
    // baja el sendero mientras alguno de sus hijos sea mas barato
    void hundir(int pos)
    {
        int izq = pos * 2;
        int der = pos * 2 + 1;
        if (izq <= cant)
        {
            int menor = izq;
            if (der <= cant && vec[der].costo < vec[izq].costo)
            {
                menor = der;
            }
            if (vec[menor].costo < vec[pos].costo)
            {
                intercambiar(pos, menor);
                hundir(menor);
            }
        }
    }
 
public:
    ColaSenderosImp(int largo)
    {
        cant = 0;
        vec = new Sendero[largo + 1];
    }

 
    void insertar(Sendero s)
    {
        cant++;
        vec[cant] = s;
        flotar(cant);
    }
 
    Sendero tope()
    {
        return vec[1];
    }
 
    void desencolar()
    {
        vec[1] = vec[cant];
        cant--;
        hundir(1);
    }
 
    bool esVacia()
    {
        return cant == 0;
    }
};
 
#endif