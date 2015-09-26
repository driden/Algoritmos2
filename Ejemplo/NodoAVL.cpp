#ifndef NODOAVL_CPP
#define NODOAVL_CPP
#include "NodoAVL.h"

//Getters
template <class T>
T& NodoAVL<T>::GetDato() const{
	return new Puntero(_dato);
}
template <class T>
Puntero<NodoAVL<T>> NodoAVL<T>::GetIzq() const{
	return _izq;
}
template <class T>
Puntero<NodoAVL<T>> NodoAVL<T>::GetDer() const{
	return _der;
}
template <class T>
Puntero<Comparador<T>> NodoAVL<T>::GetComparador() const{
	return _comparador;
}
template <class T>
int NodoAVL<T>::GetHeight() const{
	return _height;
}

//Setters
template <class T>
void NodoAVL<T>::SetHeight(const int h){
	_height = h;
}
template <class T>
void NodoAVL<T>::SetDato(const T &dato){
	_dato = dato;
}
template <class T>
void NodoAVL<T>::SetIzq(const Puntero<NodoAVL<T>> &izq){
	_izq = izq;
}
template <class T>
void NodoAVL<T>::SetDer(const Puntero<NodoAVL<T>> &der){
	_der = der;
}
template <class T>
void NodoAVL<T>::SetComparador(const Puntero<Comparador<T>> &cmp){
	_comparador = cmp;
}

#endif // !NODOAVL_CPP