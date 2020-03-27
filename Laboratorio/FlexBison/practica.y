
     %{
       #include <stdio.h>
       void yyerror (char const *);
     %}

%token ENTER MAS ENTERO

%%

programa: linea
| programa linea
;
linea: expresion ENTER              {printf("R = %d\n",$1);}
| ENTER
;
expresion: expresion MAS ENTERO     {$$ = $1 + $3;}
| ENTERO                            {$$ = $1;}
;
%%

int main()
{
  yyparse();
}

void
yyerror(char const *s)
{
  fprintf(stderr,"Creo que encontre un error :[ %s\n",s);
}




