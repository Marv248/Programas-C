# include <stdio.h>
# include <iostream>

int main(){
    int a,b, res=0;
    float resf=0.0;

    printf("Ingrese el par de numeros enteros: ");
    scanf("%d %d", &a, &b);

    res = a + b; // Suma
    printf("\nLa suma es: %d", res);
    res = a - b; // Resta
    printf("\nLa resta es: %d", res);
    res = a * b; // Multiplicacion
    printf("\nLa multiplicacion es: %d", res);
    resf = (float)a / (float)b; // Division con Cast
    printf("\nLa division es: %f", resf);
    res = a%b; // Modulo
    printf("\nEl modulo es: %d\n", res);

    system("pause"); // Para que no se me cierre la consola
    return 0;
}