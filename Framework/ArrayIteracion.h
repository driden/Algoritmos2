#ifndef ARRAYITERACION_H
#define ARRAYITERACION_H

template <class T>
class Array;

#include "Iteracion.h"

typedef unsigned int nat;

template <class T>
class ArrayIteracion : public Iteracion<T>
{
public:
	ArrayIteracion(const Array<T>& iterable);
	ArrayIteracion(const Array<T>& iterable, nat largo);
	ArrayIteracion(const Array<T>& iterable, nat inicio, nat largo);

	void Reiniciar();
	bool HayElemento() const;
	const T& ElementoActual() const;
	void Avanzar();

	Puntero<Iteracion<T>> Clonar() const;

private:
	ArrayIteracion(const Array<T>& iterable, nat inicio, nat largo, nat posicion);

	Array<T> m_Iterable;
	nat m_Posicion;
	nat m_Inicio;
	nat m_Largo;
};

#include "ArrayIteracion.cpp"

#endif