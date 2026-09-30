#include<stdio.h>
#include<iostream>

int main(){
    int n=0, cuenta=0;
    int suma = 0, num=0;
    float prom = 0.00;

    printf("n:\t");
    scanf("%d", &n);
    cuenta = 0;

    while(cuenta<n){
        printf("\nN%d:\t", cuenta+1);
        scanf("%d", &num);
        suma = suma + num;
        cuenta++;
    }

    printf("\nSuma total: %d", suma);
    printf("\nn: %d", n);

    prom = (float)suma/(float)n;

    printf("\n\nPromedio:\t%f\n\n", prom);
    system("pause");
    return 0;
}