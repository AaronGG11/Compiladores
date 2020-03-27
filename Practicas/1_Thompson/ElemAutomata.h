typedef struct ea{
    int visitado;
    char transicion_arriba;
    char transicion_abajo;      // 1, le llegan dos
    int congestion; // 0, solo le llega uno 
    int id;
} ElemAutomata;


ElemAutomata nuevoElemAu(){
    ElemAutomata e;
    e.id = -1;
    e.congestion = 0;
    e.transicion_arriba = '@';
    e.transicion_abajo = '@';
    e.visitado = 0;
    return e;
}

