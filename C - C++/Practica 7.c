#include <stdio.h>
#include<iostream>

int main() {
    int a = 1, b= 2, c = 3, aux;
    int *pa = NULL, *pb = NULL, *pc = NULL;

    pa = &a, pb = &b, pc = &c;  
    int **apdoble = NULL;
    int ***aptriple = NULL;
    apdoble = &pa;
    aptriple = &apdoble;

    // Intercambiar los valores de a y b con apuntadores :)
    printf("Antes del cambio: a = %d, b = %d\n", *pa, *pb);
    aux = *pa;
    *pa = *pb;
    *pb = aux;
    printf("Despues del cambio: a = %d, b = %d\n", *pa, *pb);

    // Modificar el valor de a con un apuntador triple
    ***aptriple = 10; // a = 10

    printf("Direccion de b: %p\n", b);
    printf("Direccion de c: %p\n", c);
    printf("Direccion de pa: %p\n", pa);
    printf("Direccion de pb: %p\n", pb);
    printf("Direccion de pc: %p\n", pc);
    printf("Direccion de apdoble: %p\n", apdoble);
    printf("Direccion de aptriple: %p\n", aptriple);

    // Valores almacenados en cada variable y apuntador
    printf("Valor de a: %d\n", &a);
    printf("Valor de b: %d\n", &b);
    printf("Valor de c: %d\n", &c);
    printf("Valor de pa: %d\n", *pa);
    printf("Valor de pb: %d\n", *pb);
    printf("Valor de pc: %d\n", *pc);
    printf("Valor de apdoble: %d\n", **apdoble);
    printf("Valor de aptriple: %d\n", ***aptriple);

    // Apuntadores dobles y triples
    printf("Valor de a con apdoble: %d\n", **apdoble);  
    printf("Valor de a con aptriple: %d\n", ***aptriple);

    system("pause");
}