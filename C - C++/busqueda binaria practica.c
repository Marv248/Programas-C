#include <stdio.h>
#include <iostream>

int binarySearch(int arr[], int t, int n) {
    printf("BUSQUEDA BINARIA\n");
    int l = 0, r = n - 1;
    
    while(l <= r) {
        int m = l + (r - l)/2;
        printf("Mitad: %d\n", m);
        if(arr[m] == t) return m;
        
        if(arr[m] < t)
            printf("%d es mayor que la mitad %d\n", t, arr[m]);
            l = m + 1;
        else
            printf("%d es menor que la mitad %d\n", t, arr[m]);
            r = m - 1;
    }
    printf("El numero %d no se encuentra en el arreglo.\n", t);
    return -1;
}

int main() {
    int n =  2*100000; // Max int
    int searched = 0;
    int arr[n];

    printf("Numero a buscar:\t");
    scanf("%d", &searched);

    for (int i = 0; i<n ; i++){
        arr[i] = i;
    }

    int pos = binarySearch(arr, searched, n);

    printf("Posicion de %d en el arreglo: %d\n", searched, pos);
    system("pause");
    return 0;
}