/******************************************************************************

    Rebollo Vargas Marco Antonio
    
    Programa 3: Resolver un sistema de ecuaciones lineales del tipo 2x2 conociendo
    los coeficientes de ambas ecuaciones;

*******************************************************************************/

// Extensiones - librerías a usar
#include <stdio.h>
#include <iostream>

// Método principal
int main()
{
    // Variables a considerar
    float  a=0, b=0, c=0, d=0, e=0, f=0; // Coeficientes
    float x, y;
    
    // Datos del usuario
    printf("//// Ecuación 1 ////\n");
    printf("Introduzca el coeficiente a: ");
    scanf("%f", &a);
    
    printf("Introduzca el coeficiente b: ");
    scanf("%f", &b);   
    
    printf("Introduzca el coeficiente c: ");
    scanf("%f", &c);
    
    printf("//// Ecuación 2 ////\n");
    printf("Introduzca el coeficiente d: ");
    scanf("%f", &d);
    
    printf("Introduzca el coeficiente e: ");
    scanf("%f", &e);
    
    printf("Introduzca el coeficiente f: ");
    scanf("%f", &f); 
    
    // Cálculos
    x = ((c*e) - (b*f)) / ((a*e) - (b*d));
    y = ((a*f) - (c*d)) / ((a*e) - (b*d));
    
    // Salida de Datos
    printf("\nEl valor de X es: \t%f", x);
    printf("\nEl valor de Y es: \t%f", y);
    
    // Evita errores ya que main es tipo int
    system("pause");
    return 0;
}