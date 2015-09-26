//#include "SetAcotado.h"
//#include "SetNoAcotado.h"
#include "AVLImp.h"


#include "Puntero.h"
#include "avl.h"


void main()
{
	/*Puntero<Set<nat>> pares = new SetAcotado<nat>(5);
	for (nat i = 0; i < 5; i++)
		pares->Insertar((i + 1) * 2);
	Puntero<Set<nat>> impares = new SetNoAcotado<nat>();
	for (nat i = 0; i < 5; i++)
		impares->Insertar(i * 2 + 1);

	pares->Union(impares)->Imprimir();
	impares->Union(pares)->Imprimir();
	pares->Union(impares)->Diferencia(pares)->Imprimir();

*/
	Puntero<AVL<int>> avl = new AVLImp<int>();
	/*
	int x1 = 59;
	int x2 = 5;

	avl->Insertar(x1);
	avl->Insertar(x2);
	avl->Insertar(9);
	avl->Insertar(19);*/

	//avl->Borrar(x1);
}
