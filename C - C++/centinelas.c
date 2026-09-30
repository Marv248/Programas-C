#include<stdio.h>
#include<iostream>

/*
Control de ciclos mediante centinelas:
    Un centinela es un valor constante especial utilizado para señalar el final de una lista de datos
    El valor seleccionado debe ser totalmente distinto de los valores que puede tomar la lista de 
*/

#define CENT -1

int main(){
    short x=1, suma=0, n=0;
    float prom;

    printf("N: \t");
    scanf("%d", &x);
    while(x != CENT){
        suma += x;
        printf("\nN:\t");
        scanf("%d", &x);
        n++;
    }

    prom = (float)suma/(float)n;

    printf("\n\nPROM:\t%f\n\n", prom);
    system("pause");
    return 0;
}