

typedef struct NodoPA{ // Estructura autoreferenciada
	Automata data;
	struct NodoPA * siguiente;
} * PilaA;

PilaA emptyPA(){
	return NULL;
}

PilaA PushPA(Automata e, PilaA p){
	PilaA auxiliar = (PilaA)malloc(sizeof(struct NodoPA));
	auxiliar -> data = e;
	auxiliar -> siguiente = p;
	return auxiliar;
}

int isEmptyPA(PilaA p){
	return p == emptyPA();
}

Automata TopPA(PilaA p){
	return p -> data;
}

PilaA PopPA(PilaA p){
	return p -> siguiente;
}