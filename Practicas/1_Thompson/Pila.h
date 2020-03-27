

typedef struct Nodo{ // Estructura autoreferenciada
	Elem dato;
	struct Nodo * siguiente;
} * Pila;

Pila empty(){
	return NULL;
}

Pila Push(Elem e, Pila p){
	Pila auxiliar = (Pila)malloc(sizeof(struct Nodo));
	auxiliar -> dato = e;
	auxiliar -> siguiente = p;
	return auxiliar;
}

int isEmpty(Pila p){
	return p == empty();
}

Elem Top(Pila p){
	return p -> dato;
}

Pila Pop(Pila p){
	return p -> siguiente;
}

void impPila(Pila p){
	Pila auxiliar = p;
	while(!isEmpty(auxiliar)){
		ImpElem(Top(auxiliar));
		auxiliar = Pop(auxiliar);
	}
}





/*
Especificacion de pila 

	empty: -> Pila; 
	push: Elem, Pila -> Pila;
	isEmpty: Pila -> boolean;
	top: Pila -> elemento;
	Pop: PIla -> Pila;


Axiomas: 

	p1: isEmpty(empty()) = Cierto;
	p2: ispEmty(push(e,p)) = Falso;
	p3: top(empty()) = ERROR;
	p4: top(push(e,p)) = e;
	p5: pop(empty()) = ERROR:
	p6: pop(push(e,p)) = p;

 

*/
