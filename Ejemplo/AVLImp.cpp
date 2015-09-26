#ifndef AVLIMP_CPP
#define AVLIMP_CPP

#include <algorithm> //max
#include "AVLImp.h"

using namespace std;

template <class T>
void AVLImp<T> ::Vacio(){
	_root = NULL;
}

template <class T>
void AVLImp<T>::Insertar(const T &x){
	Insertar(x, _root->GetComparador(), _root);
}

template<class T>
void AVLImp<T> ::Insertar(const T &x, const Puntero<Comparador<T>> &cmp, Puntero<NodoAVL<T>> &root)
{
	if (root == NULL)
	{
		root = new NodoAVL<T>();
		root->SetDato(x);
		root->SetIzq(NULL);
		root->SetDer(NULL);
		root->SetHeight(0);

	}
	else if (cmp->EsMenor(x, root->GetDato()))
	{
		Insertar(x, cmp, root->GetIzq());
		if (GetHeight(root->GetIzq()) - GetHeight(root->GetDer()) == 2)
		{
			if (cmp->EsMenor(x, root->GetIzq()->GetDato()))
			{
				RotacionSimpleIzq(root);
			}
			else
			{
				RotacionSimpleDer(root);
			}
		}
		else
		{
			RotacionDobleIzq(root);
		}
	}
	else if (cmp->EsMayor(x, root->GetDato()))
	{
		Insertar(x,cmp,root->GetDer());
		if (GetHeight(root->GetIzq()) - GetHeight(root->GetDer()) == 2)
		{
			if (cmp->EsMenor(x, root->GetDer()->GetDato()))
			{
				RotacionSimpleDer(root);
			}
			else
			{
				RotacionSimpleIzq(root);
			}
		}
		else
		{
			RotacionDobleDer(root);
		}

	}
	root->SetHeight(max(GetHeight(root->GetDer()), GetHeight(root->GetIzq())) + 1);
}

template<class T>
void AVLImp<T> ::RotacionSimpleIzq(Puntero<NodoAVL<T>> &root)
{
	Puntero<NodoAVL<T>>  k1 = root->GetIzq();
	root->GetIzq() = k1->GetDer();
	k1->GetDer() = root;
	root->SetHeight(max(GetHeight(root->GetIzq()), GetHeight(root->GetDer())) + 1);
	k1->SetHeight( max(GetHeight(k1->GetIzq()), GetHeight(k1->GetDer())) + 1 );
}

template<class T>
void AVLImp<T> ::RotacionSimpleDer(Puntero<NodoAVL<T>> &root)
{
	Puntero<NodoAVL<T>> k2 = root->GetDer();
	root->GetDer() = k2->GetIzq();
	k2->GetIzq() = root;
	k2->SetHeight(max(GetHeight(k2->GetIzq()), GetHeight(k2->GetDer())) + 1);
	root->SetHeight(max(GetHeight(root->GetIzq()), GetHeight(root->GetDer())) + 1);
}

template<class T>
void AVLImp<T> ::RotacionDobleIzq(Puntero <NodoAVL<T>> &root)
{
	RotacionSimpleDer(root->GetIzq());
	RotacionSimpleIzq(root);
}

template<class T>
void AVLImp<T> ::RotacionDobleDer(Puntero <NodoAVL<T>> &root)
{
	RotacionSimpleIzq(root->GetDer());
	RotacionSimpleIzq(root);
}


/**** Predicado ****/
// retorna true si el árbol es vacío
template<class T>
bool AVLImp<T>::EsVacio() const{
	return false;
}

template<class T>
const T& AVLImp<T>::Raiz() const{
	return _root;
}

template<class T>
const T& AVLImp<T>::Maximo() const {
	return Raiz();
}

template<class T>
const T& AVLImp<T>::Minimo() const{
	return Raiz();
}

template<class T>
bool AVLImp<T>::Existe(const T &x) const{
	return true;
}

template<class T>
void AVLImp<T>::Borrar(const T &x){}

template<class T>
const T& AVLImp<T>::Recuperar(const T&) const{
	return Raiz();
}
#endif // !AVLIMP_CPP