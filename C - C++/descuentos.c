#include <stdio.h>

int main()
{
    float monto;
    float pago;
    
    printf("Monto: ");
    scanf("%d", &monto);
    
    if (monto < 800){
        pago = monto;
    } else if (monto <= 1500){
        pago = monto * 0.9;
    } else if (monto <= 5000){
        pago = monto * 0.85;
    } else {
        pago = monto * 0.8;
    }
    
    printf("El pago total es: %d", &pago);

    return 0;
}