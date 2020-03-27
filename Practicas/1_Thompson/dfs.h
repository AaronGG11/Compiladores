int contador = 1;

// Numera los nodos del AFD
void DFS(ApNodo v){
	if(v->dato.visitado == 0){
		v->dato.visitado = 1;
		v->dato.id = contador;
		contador += 1;

		if( (v->arriba!=NULL) && (v->abajo==NULL) ){ // solo arriba
			DFS(v->arriba);
		}
		else if( (v->arriba!=NULL) && (v->abajo!=NULL) ){ // ninguno es nulo 
			DFS(v->arriba);
			DFS(v->abajo);
		}	
	}
}


// Guarda en una lista de tipo Arista cada transicion
void DFS_aristasL(ApNodo v, Transicion * t){ // marcar nodos
	if(!esNuevoNodo(v)){
		if(v->dato.visitado == 1){ // si no ha sido visitado
			v->dato.visitado = 0;

			if((v -> arriba != NULL) && (v -> abajo == NULL)){ // tiene solo arriba 
				*t = ConsTransicion(nuevoMovimiento(v->dato.id, v->arriba->dato.id, v -> dato.transicion_arriba),*t);
				DFS_aristasL(v->arriba,t);
			}
			else{ // tiene arriba y abajo
				*t = ConsTransicion(nuevoMovimiento(v->dato.id, v->arriba->dato.id, v -> dato.transicion_arriba),*t);
				DFS_aristasL(v->arriba,t);
				*t = ConsTransicion(nuevoMovimiento(v->dato.id, v->abajo->dato.id, v -> dato.transicion_abajo),*t);
				DFS_aristasL(v->abajo,t);
			}
		}
	}
	else{ // es nodo temrinal 
		if(v->dato.visitado == 1){ // si no ha sido visitado
			v->dato.visitado = 0;
		}
	}
}

