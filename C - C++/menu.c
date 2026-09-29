#include<stdio.h>
# include<iostream>

int main(){
    short opcion;
    int a, b, res;
    float div;

    printf("=======", "INICIO", "======");
    printf("Seleccione una opción:\n");
    printf("1. Suma\n");
    printf("2. Resta\n");
    printf("3. Multiplicación\n");
    printf("4. División\n");
    printf("5. Módulo\n");
    printf(": ");
    scanf("%d", &opcion);
    printf("\nIntroduzca el primer número: ");
    scanf("%d", &a);
    printf("\nIntroduzca el segundo número: " );
    scanf("%d", &b);

    switch (opcion){
    case 1:
        res = a + b;
        break;
    case 2:
        res = a - b;
        break;
    case 3: 
        res = a*b;
        break;
    case 4:
        if(b==0){
            printf("\nNO SE PUEDE DIVIDIR SOBRE 0");
            break;
        }
        div = (float)a / (float)b;
        printf("\n EL RESULTADO ES: %d", &div);
        system("pause");
        break;
    
    default:
        printf("\nSELECCIONE UNA OPCION VALIDA");
        system("pause");
        break;
    }

    if(opcion==1|| opcion==2|| opcion==3){
        printf("\nEL RESULTADO ES: %d \n", res);
    }
    
    system("pause");
    return 0;
}