/* 
    Marco Antonio Rebollo Vargas
    Práctica 0
*/

// Programa que permite calcular la superficie y la longitud de una circunferencia mediante los datos brindados por el usuario
// Directivas del pre-procesador
# include<stdio.h> // Para entrada y salida de datos
# include<iostream> // Para que no se cierre la consola
# define PI 3.1416 // Constante para etiquetar el valor PI, de modo que no se consume espacio en memoria

int main(){
    float radio, S=0, L=0;

    // Entrada de datos
    printf("Ingresa el radio de la circunferencia: ");
    scanf("%f", &radio);

    // Cálculos
    S = (radio*radio)*PI; // Cálculo de la superficie de la circunferencia
    L = (2*radio)*PI; // Cálculo de la longitud de la circunferencia

    // Salida de datos
    printf("\nEl radio es: %f", radio);
    printf("\nLa superficie de la circunferencia es: %f", S);
    printf("\nLa longitud de la circunferencia es: %f", L);

    // Final
    system("pause"); // Para que no se me cierre la consola
    return 0; // Para regresar algún dato int
}