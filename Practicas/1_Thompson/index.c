#include <stdio.h>
#include <stdlib.h>
#include "Elem.h"
#include "Pila.h"
#include "Lista.h"
#include "ElemAutomata.h"
#include "Automata.h"
#include "PilaAutomata.h"
#include "Aristas.h"
#include "dfs.h"
#include "Posfijo.h"
#include "archivoGV.h"

int main(int argc, char *argv[]){
	Lista er_posfijo = conviertePosfijo(argv, er_posfijo);
	Transicion transiciones = TransicionVacia();
	
	printf("\n\n-------------------------------------------------------\n");
	ImpLista(er_posfijo);

	Automata afd = RegexToAFD(er_posfijo);

	DFS(afd -> inicio);
	DFS_aristasL(afd -> inicio, &transiciones);

    transiciones = InvierteTransiciones(transiciones);

	printf("\n-------------------------------------------------------\n");
	printf("Numero de nodos: %d\n", contador-1);
	printf("-------------------------------------------------------\n");
	printf("Nodo inicial: %d\n",afd -> inicio -> dato.id);
	printf("-------------------------------------------------------\n");
	printf("Nodo final: %d\n", afd -> fin -> dato.id);
	printf("-------------------------------------------------------\n");
	printf("Total de transiciones: %d\n", NumTransiciones(transiciones));
	printf("-------------------------------------------------------\n");
	printf("Transiciones:\n");	
	ImpTransiciones(transiciones);
	printf("-------------------------------------------------------\n\n");

	saveFileGV(transiciones,afd);
	system("dot -Tpng afd_thompson.gv > salida.png");
	system("open salida.png");

	free(er_posfijo);
	free(transiciones);
	free(afd);

	return 0;
}