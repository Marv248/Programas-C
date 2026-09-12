#include<stdio.h>
#include<iostream>

int main(){
    int n= 10, m=20, t=0;
    double expresion = 0.0;

    printf("Evaluacion 1: %d + %d * %d = %d\n", n, m, t, n + m * t); // Multiplicacion tiene mayor precedencia que suma
    printf("Evaluacion 2: (%d + %d) * %d = %d\n", n, m, t, (n + m) * t); // Parentesis cambian la precedencia

    // Uso de operadores ++ y --
    printf("Uso de ++ y --:\n");
    printf("n: %d, m: %d \n", n, m);
    printf("n++: %d, --m: %d\n", ++n, --m);
    printf("n++: %d, --m: %d\n", ++n, --m);
    printf("n++: %d, --m: %d\n", ++n, --m);
    printf("n++: %d, --m: %d\n", ++n, --m);
    printf("n++: %d, --m: %d\n", ++n, --m);
    printf("n++: %d, --m: %d\n", ++n, --m);
    printf("n++: %d, --m: %d\n", ++n, --m);
    printf("n++: %d, --m: %d\n", ++n, --m);
    printf("n++: %d, --m: %d\n", ++n, --m);

    n = 7, m=4;
    t = n--*2+m++*2+--m;
    printf("Resultado de la expresion: %d\n", t);


    system("pause"); // Pausa para ver los resultados en la consola
    return(0);
}