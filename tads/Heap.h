#ifndef HEAP_H
#define HEAP_H

#include <cstdint>

class Heap
{
public:

	virtual void insertar(std::int64_t valor) = 0;

	virtual std::int64_t consolidar() = 0;

	virtual std::int64_t cantidadElem() = 0;
	
};

#endif