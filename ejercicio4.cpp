#include <iostream>
#include "tads/HeapPrioImp.cpp"

using namespace std;

struct nodoLista
{
    int dato;       // un modulo
    nodoLista *sig; // el siguiente de la lista
};

int main()
{
    int V, A;
    cin >> V >> A; // vertices V y aristas A

    int *prio = new int[V + 1]; // prioridad de cada vertice
    for (int i = 1; i <= V; i++)
    {
        cin >> prio[i];
    }

    int *dependencias = new int[V + 1];
    for (int i = 0; i <= V; i++)
    {
        dependencias[i] = 0; // comienza en 0 pqe no hay dependencias, nadie depende de nada
    }

    nodoLista **ady = new nodoLista *[V + 1];
    for (int i = 1; i <= V; i++)
    {
        ady[i] = NULL; // lista vacia
    }

    for (int i = 0; i < A; i++)
    { // se ingresan las dependencias
        int u;
        int v;
        cin >> u >> v;
        dependencias[v]++; // v tiene 1 dependencia mas

        nodoLista *nuevo = new nodoLista; // agrego v al principio de la lista de u, los adyacentes de u, son los que se liberan cuando u compila
        nuevo->dato = v;
        nuevo->sig = ady[u];
        ady[u] = nuevo;
    }

    HeapPrioImp h(V);

    for (int i = 1; i <= V; i++)
    {

        if (dependencias[i] == 0)
        {
            h.insertar(i, prio[i]);
        }
    }

    int *ordenDeCompliacion = new int[V];
    int cantCompilados = 0;

    while (h.cantidadElem() > 0)
    {
        int min = h.extraerMinimo();
        ordenDeCompliacion[cantCompilados] = min;
        cantCompilados++;

        nodoLista *aux = ady[min];

        while (aux != NULL)
        {
            int w = aux->dato;
            dependencias[w]--;
            if (dependencias[w] == 0)
            {
                h.insertar(w, prio[w]);
            }
            aux = aux->sig;
        }
    }
    
    if(cantCompilados < V){
        std::cout << "imposible" << std::endl;
        
    }else{
        for(int i = 0 ; i< V ; i++ ){
            std::cout << ordenDeCompliacion[i] << "\n"; // sugerencia de ia 
        }
    }



     for (int i = 1; i <= V; i++)
    {
        nodoLista *aux = ady[i];
        while (aux != NULL)
        {
            nodoLista *borrar = aux;
            aux = aux->sig;
            delete borrar;
        }
    }
    delete[] ady;
    delete[] dependencias;
    delete[] prio;
    delete[] ordenDeCompliacion;

    return 0;
}