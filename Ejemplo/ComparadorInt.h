#ifndef COMPARADORINT_H
#define COMPARADORINT_H

#include "Comparador.h"

class ComparadorInt : public Comparador < int > {
public:
	virtual CompRetorno Comparar(const int& t1, const int& t2) const override;
};

#include "ComparadorInt.cpp"
#endif // !COMPARADORINT_H
