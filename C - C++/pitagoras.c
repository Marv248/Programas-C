/******************************************************************************

    Rebollo Vargas Marco Antonio
    
    Programa 4: Hallar la hipotenusa de un triangulo rectángulo partiendo 
    de sus catetos

*******************************************************************************/

// Extensiones - librerías a usar
#include <stdio.h>
#include <math.h>
#include <iostream>

// Método principal
int main()
{
    // Variables a considerar
    float  a=0, b=0, c=0;// Coeficientes
    
    // Datos del usuario
    printf("Introduzca el cateto a:\t");
    scanf("%f", &a);
    printf("Introduzca el cateto b:\t");
    scanf("%f", &b);
    
    // Cálculos
    c = sqrt((a*a)+(b*b));
    
    // Salida de Datos
    printf("La hipotenusa C es:\t%f", c);
    
    // Evita errores ya que main es tipo int
    system("pause");
    return 0;
}