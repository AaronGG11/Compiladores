void saveFileGV(Transicion t, Automata a){
	FILE* fichero;
	fichero = fopen("afd_thompson.gv", "w");

	char linea1 [] = "digraph automata{\n";
	char linea2 [] = "\trankdir = LR;\n";
	char linea3 [] = "\tnode [shape = circle];\n\n";
	char linea4 [] = "\tinicio [shape = point];\n";

	int edo_inicial = a->inicio->dato.id;
	int edo_final = a->fin->dato.id;

	fprintf(fichero, "%s", linea1);
	fprintf(fichero, "%s", linea2);
	fprintf(fichero, "%s", linea3);
	fprintf(fichero, "%s", linea4);
	fprintf(fichero, "\tinicio -> %d [label = %cinicio%c]\n", edo_inicial, 34, 34);
	fprintf(fichero, "\t%d [shape = doublecircle]\n", edo_final);

	while(!esVaciaTransicion(t)){
		Motion m = CabezaTransicion(t);
		fprintf(fichero, "\t%d -> %d [label = %c%c%c]\n", m.origen, m.destino, 34, m.simbolo, 34);
		t = RestoTransicion(t);
	}
	fprintf(fichero,"}");

	fclose(fichero); 
}