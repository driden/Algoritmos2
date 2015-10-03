#ifndef AVLIMP_CPP
#define AVLIMP_CPP

#include <algorithm> //max
#include <iomanip>   
#include "AVLImp.h"


using namespace std;

template <class T>
void AVLImp<T> ::Vacio(){
	_root = NULL;
}

template <class T>
void AVLImp<T>::Insertar(const T &x){
	if (_root != NULL){
		Insertar(x, _comparador, _root);

	}
	else{
		_root = new NodoAVL<T>();
		_root->SetDato(x);
		_root->SetIzq(NULL);
		_root->SetDer(NULL);
		_root->SetHeight(0);
	}
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
				RotacionDobleIzq(root);
			}
		}
	}
	else if (cmp->EsMayor(x, root->GetDato()))
	{
		Insertar(x, cmp, root->GetDer());
		if (GetHeight(root->GetDer()) - GetHeight(root->GetIzq()) == 2)
		{
			if (cmp->EsMayor(x, root->GetDer()->GetDato()))
			{
				RotacionSimpleDer(root);
			}
			else
			{
				RotacionDobleDer(root);
			}
		}
	}
	root->SetHeight(max(GetHeight(root->GetDer()), GetHeight(root->GetIzq())) + 1);
}

template<class T>
void AVLImp<T> ::RotacionSimpleIzq(Puntero<NodoAVL<T>> &root)
{
	if (root != NULL){
		Puntero<NodoAVL<T>>  k1 = root->GetIzq();
		if (k1 != NULL)
		{
			root->SetIzq(k1->GetDer());
			k1->SetDer(root);
			root->SetHeight(max(GetHeight(root->GetIzq()), GetHeight(root->GetDer())) + 1);
			k1->  SetHeight(max(GetHeight(k1->GetIzq()), GetHeight(root)) + 1);
			root = k1;
		}
	}
}

template<class T>
void AVLImp<T> ::RotacionSimpleDer(Puntero<NodoAVL<T>> &root)
{
	if (root != NULL){
		Puntero<NodoAVL<T>> k2 = root->GetDer();
		if (k2 != NULL){
			root->SetDer(k2->GetIzq());
			k2->SetIzq(root);
			root->SetHeight(max(GetHeight(root->GetIzq()), GetHeight(root->GetDer())) + 1);
			k2->SetHeight(max(GetHeight(k2->GetDer()), GetHeight(root)) + 1);
			root = k2;
		}
	}
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
	RotacionSimpleDer(root);
}
template<class T>
int AVLImp<T>::GetHeight(Puntero<NodoAVL<T>> nodo) const{
	return (nodo == NULL) ? -1 : nodo->GetHeight();
}

template <class T>
Puntero<Comparador<T>> AVLImp<T>::GetComparador() const{
	return _comparador;
}
template <class T>
void AVLImp<T>::SetComparador(const Puntero<Comparador<T>> &cmp){
	_comparador = cmp;
}
/**** Predicado ****/
// retorna true si el árbol es vacío
template<class T>
bool AVLImp<T>::EsVacio() const{
	return _root == NULL;
}

template<class T>
const T& AVLImp<T>::Raiz() const{
	return _root->GetDato();
}

template<class T>
const T& AVLImp<T>::Maximo() const {
	return Maximo(_root);
}
template<class T>
const T& AVLImp<T>::Maximo(Puntero<NodoAVL<T>> root) const{

	while (root->GetDer() != NULL){
		root = root->GetDer();
	}
	return root->GetDato();
}

template<class T>
const T& AVLImp<T>::Minimo() const{
	return Minimo(_root);
}
template<class T>
const T& AVLImp<T>::Minimo(Puntero<NodoAVL<T>> root) const{

	while (root->GetIzq() != NULL){
		root = root->GetIzq();
	}
	return root->GetDato();
}

template<class T>
bool AVLImp<T>::Existe(const T &x) const{
	return Existe(x, _comparador, _root);
}
template<class T>
bool AVLImp<T>::Existe(const T &x, Puntero<Comparador<T>> cmp, Puntero<NodoAVL<T>> root) const{
	bool existe = false;

	if (root != NULL){
		existe = cmp->SonIguales(x, root->GetDato());
		if (!existe){
			existe = existe || Existe(x, cmp, root->GetDer());
			existe = existe || Existe(x, cmp, root->GetIzq());
		}
	}

	return existe;
}

template<class T>
void AVLImp<T>::Borrar(const T &x)
{
	Borrar(x,_comparador,_root);
}

template<class T>
void AVLImp<T>::Borrar(const T &x, Puntero<Comparador<T>> cmp, Puntero<NodoAVL<T>> &root)
{
	if (!EsVacio()){
		if (_comparador->SonIguales(root->GetDato(), x)){

			//Si es hoja, lo borramos de la raiz.
			if (root->GetDer() == NULL &&root->GetIzq() == NULL){
				root = NULL;
			}
			// Si tiene el subarbol derecho no vacio..
			else if (root->GetDer() != NULL && root->GetIzq() == NULL){
				Puntero<NodoAVL<T>> aux = NodoMinimo(aux);
				root = NULL;
				root = aux;
			}
			// Si tiene el subarbol izquierdo no vacio...
			else if (root->GetIzq() != NULL && root->GetDer() == NULL){
				Puntero<NodoAVL<T>> aux = NodoMaximo(root->GetIzq());
				root = NULL;
				root = aux;
			}
			//Si tiene 2 subarboles no vacios, eliminamos el "mayor de los menores"
			else if (root->GetDer() != NULL && root->GetIzq() != NULL){
				Puntero<NodoAVL<T>> aux = NodoMaximo(root->GetIzq());
				root->SetDato(aux->GetDato());
				aux = NULL; // El framework lo borra solo, por eso no hacemos delete.
			}
		}
		else if (cmp->EsMenor(x, root->GetDato())){
			Borrar(x, cmp, root->GetIzq());
			if (GetHeight(root->GetIzq()) - GetHeight(root->GetDer()) == 2)
			{
				if (cmp->EsMenor(x, root->GetIzq()->GetDato()))
				{
					RotacionSimpleIzq(root);
				}
				else
				{
					RotacionDobleIzq(root);
				}
			}
		}
		else{
			Borrar(x, cmp, root->GetDer());
			if (GetHeight(root->GetDer()) - GetHeight(root->GetIzq()) == 2)
			{
				if (cmp->EsMayor(x, root->GetDer()->GetDato()))
				{
					RotacionSimpleDer(root);
				}
				else
				{
					RotacionDobleDer(root);
				}
			}
		}
		if (!EsVacio())
			root->SetHeight(max(GetHeight(root->GetDer()), GetHeight(root->GetIzq())) + 1);
	}
}

template<class T>
Puntero<NodoAVL<T>> AVLImp<T>::NodoMaximo(Puntero<NodoAVL<T>> root) {

	while (root->GetDer() != NULL){
		root = root->GetDer();
	}
	return root;
}
template<class T>
Puntero<NodoAVL<T>> AVLImp<T>::NodoMinimo(Puntero<NodoAVL<T>> root) {

	while (root->GetIzq() != NULL){
		root = root->GetIzq();
	}
	return root;
}

template<class T>
const T& AVLImp<T>::Recuperar(const T&) const{
	return Raiz();
}


template<class T>
void AVLImp<T>::Imprimir(){
	postorder(_root);
}

template <class T>
void AVLImp<T>::postorder(Puntero<NodoAVL<T>> p, int indent = 0)
{
	if (p != NULL) {
		if (p->GetIzq()) postorder(p->GetIzq(), indent + 4);
		if (p->GetDer()) postorder(p->GetDer(), indent + 4);
		if (indent) {
			std::cout << std::setw(indent) << ' ';
		}
		cout << p->GetDato() << endl;
	}
}
#endif // !AVLIMP_CPP