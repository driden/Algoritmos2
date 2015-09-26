#pragma once

enum CompRetorno
{
	IGUALES,
	MENOR,
	MAYOR,
	DISTINTOS
};

template <class T>
class Comparador abstract
{
public:
	virtual ~Comparador();

	bool SonIguales(const T& t1, const T& t2) const;
	bool SonDistintos(const T& t1, const T& t2) const;
	bool EsMenor(const T& t1, const T& t2) const;
	bool EsMayor(const T& t1, const T& t2) const;

	static const Comparador<T>& Default;

	virtual CompRetorno Comparar(const T& t1, const T& t2) const abstract;

private:
	class ComparadorOperadores : public Comparador<T>
	{
	public:
			CompRetorno Comparar(const T& t1, const T& t2) const;
	};

};

#include "Comparador.cpp"
