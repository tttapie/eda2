#ifndef HEAP_H
#define HEAP_H

#include <cstdint>

class Heap
{
public:
	// pre: hay espacio disponible en el heap
	// post: agrega el valor y mantiene la propiedad de min-heap
	virtual void insertar(std::int64_t valor) = 0;

	// pre: el heap contiene al menos dos elementos
	// post: elimina los dos valores minimos, inserta su suma y la devuelve
	virtual std::int64_t consolidar() = 0;

	// pre: -
	// post: devuelve la cantidad actual de elementos del heap
	virtual std::int64_t cantidadElem() = 0;
	
};

#endif