#include <iostream>
#include <vector>
#include <cstdint>
#include "tads/ColaSenderos.h"
#include "tads/ColaSenderosImp.cpp"
#include "tads/DisjointSet.h"
#include "tads/DisjointSetImp.cpp"
 
using namespace std;
 
// PRE:  -
// POS: devuelve el costo minimo para conectar todos los refugios, o -1 si no se puede
int64_t kruskal(vector<Sendero> &senderos, int cantidadRefugios, int cantidadSenderos)
{
    //  meto todos los senderos en la cola de prioridad
    ColaSenderosImp colaSenderos(cantidadSenderos);
    for (int i = 0; i < cantidadSenderos; i++)
    {
        colaSenderos.insertar(senderos[i]);
    }
 
    //  cada refugio arranca en su propio conjunto
    ConjuntosDisjuntosImp conjuntos(cantidadRefugios);
    int64_t costoTotal = 0;
    int cantidadMantenidos = 0;
 
    //saco el mas barato,  si une dos conjuntos distintos, no forma ciclo
    while (!colaSenderos.esVacia() && cantidadMantenidos < cantidadRefugios - 1)
    {
        Sendero s = colaSenderos.tope();
        colaSenderos.desencolar();
 
        if (conjuntos.encontrar(s.refugio1) != conjuntos.encontrar(s.refugio2))
        {
            conjuntos.unir(s.refugio1, s.refugio2);
            costoTotal = costoTotal + s.costo;
            cantidadMantenidos++;
        }
    }
 
    int64_t res = costoTotal;
    if (cantidadMantenidos < cantidadRefugios - 1)
    {
        res = -1; // quedaron refugios sin conectar
    }
    return res;
}
 


int main()
{
    int cantidadRefugios, cantidadSenderos;
    cin >> cantidadRefugios >> cantidadSenderos;
 
    vector<Sendero> senderos(cantidadSenderos);
    for (int i = 0; i < cantidadSenderos; i++)
    {
        int u, v, c;
        cin >> u >> v >> c;
        // los refugios vienen de 1 a V y el conjunto disjunto va de 0 a V-1
        senderos[i].refugio1 = u - 1;
        senderos[i].refugio2 = v - 1;
        senderos[i].costo = c;
    }
 
    int64_t res = kruskal(senderos, cantidadRefugios, cantidadSenderos);
    if (res == -1)
    {
        cout << "imposible" << endl;
    }
    else
    {
        cout << res << endl;
    }
 
    return 0;
}