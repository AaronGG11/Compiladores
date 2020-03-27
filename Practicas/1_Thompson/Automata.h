typedef struct NodoAu{
		ElemAutomata dato; // 0 ó 1
		struct NodoAu * arriba;
		struct NodoAu * abajo;
} *ApNodo;

typedef struct ANodo{
	ApNodo inicio;
	ApNodo fin;
} *Automata;

char Epsilon = 'E';

int esNuevoNodo(ApNodo a){
	return ((a -> arriba == NULL) && (a -> abajo == NULL));
}

ApNodo nuevoNodo(){
	ApNodo n = (ApNodo)malloc(sizeof(struct NodoAu));
	ElemAutomata e = nuevoElemAu();
	n -> dato = e;
	n -> arriba = n -> abajo = NULL;

	return n;
}

Automata nuevoAutomata(){ // lista
	Automata temporal = (Automata)malloc(sizeof(struct ANodo));
	temporal -> inicio = temporal -> fin = NULL;
	return temporal;
}

int esNuevoA(Automata a){ // lista 
	return ((a -> inicio == NULL) && (a -> fin == NULL));
}

// Plantillas
// Unitario (1)
Automata plantillaUnitario(char movimiento){
	Automata a = nuevoAutomata();
	ApNodo n1 = nuevoNodo();
	ApNodo n2 = nuevoNodo();
	a -> inicio = n1;
	n1 -> arriba = n2;
	n1 -> dato.transicion_arriba = movimiento;
	a -> fin = n2;

	return a;
}

// Unitario epsilon(0)
Automata plantillaEpsilon(){
	Automata a = nuevoAutomata();
	ApNodo n1 = nuevoNodo();
	ApNodo n2 = nuevoNodo();
	a -> inicio = n1;
	n1 -> arriba = n2;
	n1 -> dato.transicion_arriba = Epsilon;
	a -> fin = n2;

	return a;
}

// Cerradura positiva (1)
Automata plantillaPositiva(Automata a){
	ApNodo n1 = nuevoNodo();
	ApNodo n2 = nuevoNodo();

	n1 -> arriba = a -> inicio; // ap1
	n1 -> dato.transicion_arriba = Epsilon; // e1
	a -> fin -> arriba = n2; // e3
	a -> fin -> dato.transicion_arriba = Epsilon; // e3
	a -> fin -> abajo = a -> inicio; // ap2
	a -> fin -> dato.transicion_abajo = Epsilon; // e2

	a -> inicio = n1;
	a -> fin = n2;

	return a;
}

// Cerradura estrella (1) 
Automata plantillaEstrella(Automata a){
	ApNodo n1 = nuevoNodo();
	ApNodo n2 = nuevoNodo();

	n1 -> arriba = a -> inicio; // ap1
	n1 -> dato.transicion_arriba = Epsilon; // e1
	a -> fin -> arriba = n2; // e3
	a -> fin -> dato.transicion_arriba = Epsilon; // e3
	a -> fin -> abajo = a -> inicio; // ap2
	a -> fin -> dato.transicion_abajo = Epsilon; // e2

	a -> inicio = n1;
	
	a -> fin = n2;
	a -> inicio -> abajo = a -> fin; // ap4
	a -> inicio -> dato.transicion_abajo = Epsilon; // e4

	return a;
}

// Concatenacion  (2)
Automata plantillaConcatenacion(Automata a, Automata b){
	a -> fin -> arriba = b -> inicio -> arriba;
	a -> fin -> abajo = b -> inicio -> abajo;

	a -> fin -> dato.transicion_arriba = b -> inicio -> dato.transicion_arriba;
	a -> fin -> dato.transicion_abajo = b -> inicio -> dato.transicion_abajo;

	a -> fin = b -> fin;
	return a;
}

// Union (2)
Automata plantillaUnion(Automata a, Automata b){
	ApNodo n1 = nuevoNodo();
	ApNodo n2 = nuevoNodo();

	n1 -> arriba = a -> inicio; // ap1
	n1 -> dato.transicion_arriba = Epsilon; // e1
	n1 -> abajo = b -> inicio; // ap2
	n1 -> dato.transicion_abajo = Epsilon; // e2

	a -> fin -> arriba = n2; // ap3
	a -> fin -> dato.transicion_arriba = Epsilon; // e3
	b -> fin -> arriba = n2; // ap4
	b -> fin -> dato.transicion_arriba = Epsilon; // e4

	a -> inicio = n1;
	a -> fin = n2;

	return a;
}







