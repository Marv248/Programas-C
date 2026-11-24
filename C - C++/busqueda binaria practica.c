#include <stdio.h>

int binarySearch(int arr[], int t, int n) {
    int l = 0, r = n - 1;
    
    while(l <= r) {
        int m = l + (r - l)/2;
        if(arr[m] == t) return m;
        
        if(arr[m] < t)
            l = m + 1;
        else
            r = m - 1;
    }
    printf("El numero %d no se encuentra en el arreglo.\n", t);
    return -1;
}

int lowerBound(int arr[], int t, int n) {
    int l = 0, r = n - 1;
    
    while(l <= r) {
        int m = l + (r - l)/2;
        
        if(arr[m] < t)
            l = m + 1;
        else
            r = m - 1;
    }
    return l;
}

int upperBound(int arr[], int t, int n) {
    int l = 0, r = n - 1;
    
    while(l <= r) {
        int m = l + (r - l)/2;
        
        if(arr[m] <= t)
            l = m + 1;
        else
            r = m - 1;
    }
    return l;
}

int main() {
    int n =  2*100000000; // Max int
    int searched = 0;
    int arr[n];

    printf("Numero a buscar:\t");
    scanf("%d", &searched);

    for (int i = 0; i<n ; i++){
        arr[i] = i;
    }

    int pos = binarySearch(arr, searched, n);
    int pos2 = lowerBound(arr, searched, n);
    int pos3 = upperBound(arr, searched, n);

    printf("Posicion de %d en el arreglo: %d\n", searched, pos);
    printf("Posicion de %d en el arreglo (lower bound): %d\n", searched, pos2);
    printf("Posicion de %d en el arreglo (upper bound): %d\n", searched, pos3);
    return 0;
}