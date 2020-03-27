int esCerraduraPositiva(Elem e){
    return e == '+';
}

int esCerraduraEstrella(Elem e){
    return e == '*';
}

int esConcatenacion(Elem e){
	return e == '.';
}

int esUnion(Elem e){
    return e == '|';
}

int esParI(Elem e){
	return e == '(';
}
	
int esParD(Elem e){
	return e == ')';
}

int esOperador(Elem e){
	if(esCerraduraEstrella(e) || esCerraduraPositiva(e) 
							|| esConcatenacion(e) || esUnion(e)){
		return 1;
	}
	else{
		return 0;
	}
}

Lista conviertePosfijo(char **argv, Lista lista_postfijo){
	Pila pila = empty();
	char * pal = *++argv;
	char c;
    int punto = 0;


	while(*pal){
		c = *pal;
		if(esParI(c)){
            if(punto){
                while(!isEmpty(pila) && ((Top(pila) == esCerraduraPositiva(c))||(Top(pila) == esCerraduraEstrella(c)))){
					lista_postfijo = Cons(Top(pila),lista_postfijo);
					pila = Pop(pila);
				}
				pila = Push('.',pila);
                punto = 0;
            }
            pila = Push(c,pila);
        }
		else if(esParD(c)){
			punto = 1;
			while(!isEmpty(pila) && !esParI(Top(pila))){
				lista_postfijo = Cons(Top(pila),lista_postfijo);
				pila = Pop(pila);	
			}

			if(!isEmpty(pila)){
				pila = Pop(pila);
			}
		}
		else if(esCerraduraPositiva(c)||esCerraduraEstrella(c)){
			lista_postfijo = Cons(c,lista_postfijo);
		}
		else if(esUnion(c)){
			while(!isEmpty(pila) && (Top(pila) == esCerraduraPositiva(c) 
									|| Top(pila) == esCerraduraEstrella(c)
									|| Top(pila) == '.'
									|| Top(pila) == '|')){
				lista_postfijo = Cons(Top(pila),lista_postfijo);
				pila = Pop(pila);
			}
			pila = Push(c,pila);
            punto = 0;
		}
		else{
			if(punto){
				while(!isEmpty(pila) && ((Top(pila) == esCerraduraPositiva(c))||(Top(pila) == esCerraduraEstrella(c)))){
					lista_postfijo = Cons(Top(pila),lista_postfijo);
					pila = Pop(pila);
				}
				pila = Push('.',pila);
			}
			punto = 1;
			lista_postfijo = Cons(c,lista_postfijo);
		}
		pal++;
	}	
	while(!isEmpty(pila)){
		lista_postfijo = Cons(Top(pila),lista_postfijo);
		pila = Pop(pila);
	}

	// free(pila);
	lista_postfijo = InvierteLista(lista_postfijo);
	return lista_postfijo;
}





Automata RegexToAFD(Lista er_posfijo){
	PilaA ensambladora = emptyPA();
	while(er_posfijo != Vacia()){ 
		if(esOperador(Cabeza(er_posfijo))){ // es operador
			if(esCerraduraEstrella(Cabeza(er_posfijo))){ // cerradura *
				Automata a = TopPA(ensambladora);
				ensambladora = PopPA(ensambladora);
				ensambladora = PushPA(plantillaEstrella(a),ensambladora);
			}
			else  if(esCerraduraPositiva(Cabeza(er_posfijo))){ //cerradura +
				Automata a = TopPA(ensambladora);
				ensambladora = PopPA(ensambladora);
				ensambladora = PushPA(plantillaPositiva(a),ensambladora);
			}
			else if(esUnion(Cabeza(er_posfijo))){ // union 
				Automata a2 = TopPA(ensambladora);
				ensambladora = PopPA(ensambladora);
				Automata a1 = TopPA(ensambladora);
				ensambladora = PopPA(ensambladora);
				ensambladora = PushPA(plantillaUnion(a1,a2),ensambladora);
			}
			else{ // concatenacion
				Automata a2 = TopPA(ensambladora);
				ensambladora = PopPA(ensambladora);
				Automata a1 = TopPA(ensambladora);
				ensambladora = PopPA(ensambladora);
				ensambladora = PushPA(plantillaConcatenacion(a1,a2),ensambladora);
			}
		}
		else{ // es operando 
			ensambladora = PushPA(plantillaUnitario(Cabeza(er_posfijo)),ensambladora);
		}
		er_posfijo = Resto(er_posfijo);
	}

	return TopPA(ensambladora);
}








