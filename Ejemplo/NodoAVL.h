#ifndef NODOAVL_H
#define NODOAVL_H

#include "Puntero.h"
#include "Comparador.h"

template <class T>
class NodoAVL
{
private:
	T _dato;
	Puntero<NodoAVL<T>> _izq;
	Puntero<NodoAVL<T>> _der;
	Puntero<Comparador<T>> _comparador;
	int _height;

public:
	
	//Getters
	T& GetDato() const;
	Puntero<NodoAVL<T>> GetIzq() const;
	Puntero<NodoAVL<T>> GetDer() const;
	Puntero<Comparador<T>> GetComparador() const;
	int GetHeight() const;
	
	//Setters
	void SetHeight(const int h);
	void SetDato(const T &dato);
	void SetIzq(const Puntero<NodoAVL<T>> &izq);
	void SetDer(const Puntero<NodoAVL<T>> &der);
	void SetComparador(const Puntero<Comparador<T>> &cmp);
};

#include "NodoAVL.cpp"
#endif