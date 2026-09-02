/******************************************************************************

    Rebollo Vargas Marco Antonio
    
    Programa 2. Leer 2 enteros y calcular e imprimir su producto, cociente y 
    residuo

*******************************************************************************/

// Extensiones - librerías a usar
#include <stdio.h>
#include <iostream>

// Método principal
int main()
{
    // Variables a considerar
    int num1=0, num2=0; // Números a usar
    float producto, cociente;
    int residuo; // Tipo int ya que es 1 o 0
    
    // Datos del usuario
    printf("Introduzca el número 1: ");
    scanf("%i", &num1);
    
    printf("Introduzca el número 2: ");
    scanf("%i", &num2);
    
    
    // Cálculos
    producto = num1 * num2;
    cociente = num1/num2;
    residuo = num1 % num2;
    
    // Salida de Datos
    printf("\nEl producto es: \t%f", producto);
    printf("\nEl cociente es: \t%f", cociente);
    printf("\nEl residuo es: \t%i", residuo);
    
    // Evita errores ya que main es tipo int
    system("pause");
    return 0;
}