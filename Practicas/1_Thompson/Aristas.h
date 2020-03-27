typedef struct mt{
	int origen;
	int destino;
	char simbolo;
} Motion;

Motion nuevoMovimiento(int origin, int destination, char symbol){
	Motion m;
	m.origen = origin;
	m.destino = destination;
	m.simbolo = symbol;

	return m;
}


void ImpElemMotion(Motion m){
	printf("[%d,%d] - %c\n", m.origen, m.destino, m.simbolo);
}


typedef struct NodoM{
	Motion dato;
	struct NodoM * siguiente;
} * Transicion;

Transicion TransicionVacia(){
	return NULL;
}

// Construye un nodo 
Transicion ConsTransicion(Motion e, Transicion l){ 
	Transicion auxiliar = (Transicion)malloc(sizeof(struct NodoM));
	auxiliar -> dato = e;
	auxiliar -> siguiente = l;
	return auxiliar;
}

// Verifica si esta vacia la lista
int esVaciaTransicion(Transicion l){
	return l == TransicionVacia(); // 0 si es falso, 1 distinto de 0
}

// Obtiene la cabeza de la lista
Motion CabezaTransicion(Transicion l){
	return l -> dato;
}

// Obtiene el resto de la lista
Transicion RestoTransicion(Transicion l){
	return l -> siguiente;	
}

// Cuenta el numero de nodos/elementos de la lista
int NumTransiciones(Transicion l){
	if(esVaciaTransicion(l)){
		return 0;
	}
	else{
		return 1 + NumTransiciones(RestoTransicion(l));
	}
}

// imprime la lista
void ImpTransiciones(Transicion l){
	if(!esVaciaTransicion(l)){
		ImpElemMotion(CabezaTransicion(l));
		ImpTransiciones(RestoTransicion(l));
	}
	else{
		printf("\n");
	}
}

// Une dos Pilas
Transicion PegaListasTransicion(Transicion x, Transicion y){
	if(esVaciaTransicion(x)){
		return y;
	}
	else{
		return ConsTransicion(CabezaTransicion(x),PegaListasTransicion(RestoTransicion(x),y));
	}
}

// Invierte una lista
Transicion InvierteTransiciones(Transicion l){
	if(esVaciaTransicion(l)){
		return l;
	}
	else{
		return PegaListasTransicion(InvierteTransiciones(RestoTransicion(l)),ConsTransicion(CabezaTransicion(l),TransicionVacia()));
	}
}




