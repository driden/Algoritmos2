#ifndef TABLA_H
#define TABLA_H

typedef unsigned int nat;

template <class Clave, class Valor>
class Tabla abstract
{
public:
	virtual ~Tabla(){}

	/* CONSTRUCTORAS */
	virtual void Agregar(const Clave& c, const Valor& v) abstract;
	virtual void Borrar(const Clave& c) abstract;
	/* PREDICADOS */
	virtual bool EstaVacia() const abstract;
	virtual bool EstaLlena() const abstract;
	virtual bool Pertenece(const Clave& c) const abstract;
	/* SELECTORAS */
	virtual bool Obtener(const Clave& c, Valor& v) const abstract;
	virtual nat Largo() const abstract;
};

#endif