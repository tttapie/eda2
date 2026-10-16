#ifndef HASH_H
#define HASH_H

#include <string>

class Hash
{
public:
	// pre: palabra contiene entre 1 y 20 letras minusculas
	// post: registra palabra en su cajon, incrementando su cantidad en uno
	virtual void registrar(std::string &palabra) = 0;

	// pre: palabra contiene entre 1 y 20 letras minusculas
	// post: devuelve cuantas palabras registradas usan el mismo cajon que palabra; devuelve 0 si no hay ninguna
	virtual int consultar(std::string &palabra) = 0;

	// pre: -
	// post: devuelve la cantidad de cajones distintos usados por las palabras registradas
	virtual int obtenerCantidadCajones() = 0;

	// pre: -
	// post: devuelve la cantidad maxima de palabras registradas en un mismo cajon; devuelve 0 si no hay palabras registradas
	virtual int obtenerCajonGrande() = 0;
};

#endif
