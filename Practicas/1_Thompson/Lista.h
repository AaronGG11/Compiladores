typedef struct NodoL{
	Elem dato;
	struct NodoL * siguiente;
} * Lista;

Lista Vacia(){
	return NULL;
}

// Construye un nodo 
Lista Cons(Elem e, Lista l){ 
	Lista auxiliar = (Lista)malloc(sizeof(struct NodoL));
	auxiliar -> dato = e;
	auxiliar -> siguiente = l;
	return auxiliar;
}

// Verifica si esta vacia la lista
int esVacia(Lista l){
	return l == Vacia(); // 0 si es falso, 1 distinto de 0
}

// Obtiene la cabeza de la lista
Elem Cabeza(Lista l){
	return l -> dato;
}

// Obtiene el resto de la lista
Lista Resto(Lista l){
	return l -> siguiente;	
}

// Cuenta el numero de nodos/elementos de la lista
int NumElem(Lista l){
	if(esVacia(l)){
		return 0;
	}
	else{
		return 1 + NumElem(Resto(l));
	}
}

// imprime la lista
void ImpLista(Lista l){
	if(!esVacia(l)){
		ImpElem(Cabeza(l));
		ImpLista(Resto(l));
	}
}

// Une dos listas
Lista PegaListas(Lista x, Lista y){
	if(esVacia(x)){
		return y;
	}
	else{
		return Cons(Cabeza(x),PegaListas(Resto(x),y));
	}
}

// Invierte una lista
Lista InvierteLista(Lista l){
	if(esVacia(l)){
		return l;
	}
	else{
		return PegaListas(InvierteLista(Resto(l)),Cons(Cabeza(l),Vacia()));
	}
}

/* definir una fucnion que reciba como argumento un elemto y una lista
	y devuelve verdadero si el elemento esta en la lista o falso en caso contrario*/
int estaEn(Elem e, Lista l){
	if(esVacia(l)){
		return 0;
	}
	else if(sonIguales(e,Cabeza(l))){
		return 1;
	}
	else{
		return estaEn(e,Resto(l));
	}
}




















