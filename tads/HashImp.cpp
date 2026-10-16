#ifndef Hash_IMP
#define Hash_IMP

#include "Hash.h"
#include "ListImp.cpp"
#include <string>

struct NodoCajon
{
    int firma[26];
    int cant;
    NodoCajon *sig;
};

class HashImp : public Hash
{
private:
    NodoCajon **tabla;
    int largo;
    int cantCajones;
    int cajonGrande;

public:
    HashImp(int cantBuckets) // El constructor: se ejecuta al crear el hash, por ejemplo new HashImp<long long>(1000), y recibe el largo del array
    {
        largo = cantBuckets;
        tabla = new NodoCajon *[largo];
        cantCajones = 0;
        cajonGrande = 0; // tiene que ser en orden O(1) lo pide la letra
        for (int i = 0; i < largo; i++)
        {
            tabla[i] = NULL;
        }
    }

    int obtenerCantidadCajones(){
        return cantCajones;
    }

    int obtenerCajonGrande(){
        return cajonGrande;
    }

    int hashClave(int firma[26], int cantidadBuckets)  
    { // IA: 31 mezcla los contadores segun su posicion.
        int hash = 0;
        for (int i = 0; i < 26; i++)
        {
            hash = (hash * 31 + firma[i]) % cantidadBuckets;
        }
        return hash;
    }

    void crearFirma(std::string &palabra, int firma[26])
    { // pasar a array
        for (int j = 0; j < 26; j++)
        {
            firma[j] = 0;
        }
        for (int i = 0; i < palabra.length(); i++)
        {
            firma[palabra[i] - 'a']++;
        }
    }

    bool mismaFirma(int firma1[26], int firma2[26])
    { // comparar 2 firmas y ver si son iguales
        for (int i = 0; i < 26; i++)
        {
            if (firma1[i] != firma2[i])
            {
                return false;
            }
        }
        return true;
    }

    void registrar(std::string &palabra)
    {
        int firma[26];
        crearFirma(palabra, firma);
        int indice = hashClave(firma, largo);
        NodoCajon *actual = tabla[indice]; // tomo la lista de nodos en ese indice(bucket)
        NodoCajon *aux = actual;

        while (aux != NULL && !mismaFirma(aux->firma, firma))
        { // buscar si la firma ya esta registrada
            aux = aux->sig;
        }
        if (aux != NULL)
        {
            aux->cant++;
            // si ya esta registrada se suma 1 a la cantidad de palabras
        }
        else
        { // si no esta registrada se crea un nodo y se enlaza al bucket con la cantidad en 1
            NodoCajon *nuevo = new NodoCajon;

            for (int i = 0; i < 26; i++)
            { // pasar la firma a el nuevo
                nuevo->firma[i] = firma[i];
            }
            nuevo->cant = 1;
            nuevo->sig = tabla[indice];
            tabla[indice] = nuevo;
            cantCajones++;
            aux = nuevo;
        }
        if (aux->cant > cajonGrande)
        {
            cajonGrande = aux->cant;
        }
    }

    int consultar(std::string &palabra)
    {
        int firma[26];
        crearFirma(palabra, firma);
        int indice = hashClave(firma, largo);
        NodoCajon *actual = tabla[indice];

        while (actual != NULL && !mismaFirma(actual->firma, firma))
        {
            actual = actual->sig;
        }
        if (actual != NULL)
        {
            return actual->cant;
        }
        return 0;
    }
};

#endif