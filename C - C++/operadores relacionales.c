#include <iostream>
#include <stdio.h>

int main(){
    int a,b;
    int booleano = 0;
    printf("Ingrese el par de numeros enteros: ");
    scanf("%d %d", &a, &b);

    booleano = (a==b);
    printf("¿Son iguales? %d\n", booleano);
    booleano = (a!=b);
    printf("¿Son diferentes? %d\n", booleano);
    booleano = (a>b);
    printf("¿A es mayor que B? %d\n", booleano);
    booleano = (a<b);
    printf("¿A es menor que B? %d\n", booleano);

    system("pause"); // Para que no se me cierre la consola
    return 0;
}