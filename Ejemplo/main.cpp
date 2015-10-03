//#include "SetAcotado.h"
//#include "SetNoAcotado.h"
#include "AVLImp.h"


#include "Puntero.h"
#include "avl.h"
#include "ComparadorInt.h"

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
	Puntero<ComparadorInt> cmp = new ComparadorInt();
	Puntero<AVL<int>> avl = new AVLImp<int>(cmp);

	/*int x1 = 59;
	int x2 = 5;

	avl->Insertar(x1);
	cout << "se agrego x1" << endl;
	avl->Insertar(x2);
	cout << "se agrego x2" << endl;
	avl->Insertar(9);
	avl->Insertar(19);*/
	
	
	/*cout << "Maximo: "<<avl->Maximo() << endl;
	cout << "Minimo: " << avl->Minimo() << endl;
	cout << "Existe 49: " << avl->Existe(49) << endl;
	cout << "Existe 59: " << avl->Existe(59) << endl;
	cout << "Existe 5: " << avl->Existe(5) << endl;
	cout << "Existe 15: " << avl->Existe(15) << endl;
	cout << "Existe 19: " << avl->Existe(19) << endl;*/
	//avl->Borrar(x1);

	avl->Insertar(25);
	avl->Insertar(40);
	avl->Insertar(15);
	avl->Insertar(20);
	//Doble rotacion izq
	avl->Insertar(19);
	avl->Insertar(30);
	avl->Insertar(45);
	avl->Insertar(17);
	avl->Insertar(27);
	avl->Insertar(26);
	


	avl->Borrar(40);
}
