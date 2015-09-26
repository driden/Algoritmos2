#pragma once

#include "Iteracion.h"
#include "Puntero.h"

#define foreach(item, iterador)																			\
	for (auto item##_iterator = unwrapIterador(iterador); item##_iterator.C; item##_iterator.C = false)	\
		for (auto item = item##_iterator.D; item##_iterator.I->HayElemento() ? &(item = item##_iterator.I->ElementoActual()) || true : false; item##_iterator.I->Avanzar())

template <class T>
class Iterador
{
public:
	Iterador(Iteracion<T>* iteracion = NULL);
	Iterador(const Puntero<Iteracion<T>>& iteracion);
	Iterador(const Iterador<T>& iterador);

	const Iterador<T>& operator=(Iteracion<T>* iteracion);
	const Iterador<T>& operator=(const Puntero<Iteracion<T>>& iteracion);
	const Iterador<T>& operator=(const Iterador<T>& iterador);

	void Reiniciar();
	bool HayElemento() const;
	const T& ElementoActual() const;
	void Avanzar();

	inline Iterador<T>& operator++();
	inline Iterador<T> operator++(int);
	inline const T& operator*() const;
	inline bool operator!() const;
	inline operator bool() const;

	template <class U> operator Iterador<U>() const;

	template <class U, typename Conv>
	Iterador<U> Convert() const;

	Iterador<T> Concat(const Iterador<T>& it) const;

	Iterador<T> Clonar() const;

	struct Wrapper
	{
	private:
		void Init(const Iterador<T>& it)
		{
			I = it.m_Iteracion;
			if (I)
			{
				I->Reiniciar();
				C = true;
			}
			else
				C = false;
		}

	public:
		Puntero<Iteracion<T>> I;
		bool C;
		T D;

		Wrapper(const Iterador<T>& it)
		{
			Init(it);
		}
	};
private:
	Puntero<Iteracion<T>> m_Iteracion;
};

template <class T>
typename Iterador<T>::Wrapper unwrapIterador(const Iterador<T>& it)
{
	return Iterador<T>::Wrapper(it);
}

#include "Iterador.cpp"