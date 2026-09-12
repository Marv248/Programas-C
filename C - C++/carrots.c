# include <stdio.h>

int main(){
    int test_cases = 0;
    scanf("%d", &test_cases);
    while(test_cases--){
        int n = 0, m = 0;
        scanf("%d %d", &n, &m);

        int carrots[n]; // Lista de longitudes de las zanahorias de tamño n (total de zanahorias)
        for(int j=0; j<n
            ; j++){
            scanf("%d", &carrots[j]); // Leer los valores para la lista de longitudes
        }

        int max = 0;
        for(int x=1; x<=m; x++){ // Preguntar para cada valor de x desde 1 hasta m
            int max_actual = 0;

            for(int j=0; j<n; j++){ // Para cada valor de la lista de longitudes
                if(!(carrots[j] < x)){ // Si el valor de la lista es mayor o igual a x
                    if(carrots[j] == (2*x)){
                        max_actual = max_actual + 2; // Sumar 2
                    } else{
                        max_actual = max_actual + 1; // Sumar 1
                    }
                } // De lo contrario no sumar nada ya que si es menor no hay más partes de longitud x
            }
            if(max_actual > max){ // Si el valor actual es mayor que el valor máximo
                max = max_actual; // Guardar el valor actual como el nuevo valor máximo
            }
        }
        printf("%d\n", max); // Regresar el valor máximo de la longitud de la lista
    }
    return 0; // Para regresar algún dato int
}