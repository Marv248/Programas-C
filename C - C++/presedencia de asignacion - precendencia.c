/* OPERADORES DE ASIGNACION Y PRECEDENCIA DE OPERADRORES*/
#include <stdio.h>
#include <iostream>

int main()
{
    int a = 5, b = 10, c = 15;
    int resultado;

    // Operadores de asignación
    resultado = a + b; // Asignación simple
    printf("Resultado de a + b: %d\n", resultado);

    resultado += c; // Asignación compuesta (resultado = resultado + c)
    printf("Resultado después de += c: %d\n", resultado);

    resultado -= a; // Asignación compuesta (resultado = resultado - a)
    printf("Resultado después de -= a: %d\n", resultado);

    resultado *= b; // Asignación compuesta (resultado = resultado * b)
    printf("Resultado después de *= b: %d\n", resultado);

    resultado /= c; // Asignación compuesta (resultado = resultado / c)
    printf("Resultado después de /= c: %d\n", resultado);

    resultado %= 2; // Asignación compuesta (resultado = resultado % 2)
    printf("Resultado después de %%= 2: %d\n", resultado);

    

    // Precedencia de operadores
    int x = 2, y = 3, z = 4;
    int expresion;

    expresion = x + y * z; // Multiplicación tiene mayor precedencia que suma
    printf("Resultado de x + y * z: %d\n", expresion);

    expresion = (x + y) * z; // Paréntesis cambian la precedencia
    printf("Resultado de (x + y) * z: %d\n", expresion);

    system("pause"); // Pausa para ver los resultados en la consola
    return 0;
}