#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int i, j, aux, largo, clave, Lista[100], ListaSinOrden[100], elvectorordenado[100];
int makemagic();
void pregunta_usuario(), busco(int arreglo[], int N);
void leerElementos(int arreglo[], int N);
void ordenBurbujaA(int arreglo[], int N);
void ordenBurbujaD(int arreglo[], int N);
void imprimirElementos(int arreglo[], int N);


main() {
    srand(time(0));
    pregunta_usuario();
    leerElementos(Lista, largo);
    imprimirElementos(ListaSinOrden, largo);

    /* Ordenar */
    printf("\nOrden Ascendente");
    ordenBurbujaA(ListaSinOrden, largo);
    imprimirElementos(Lista, largo);
    /* Busqueda */
    busco(Lista, largo);
    /* Ordenar */
    printf("\nOrden Descendente");
    ordenBurbujaD(ListaSinOrden, largo);
    imprimirElementos(Lista, largo);
    /* Busqueda */
    busco(Lista, largo);
}

void pregunta_usuario () {
    do {
        printf("\nIngrese el largo del arreglo (debe ser mayor a Zero y menor a 100): \n");
        scanf("%d", &largo);
    }while(largo < 0 || largo > 100);

    return;
}

void leerElementos(int arreglo[], int N){
    printf("\n");
    for(i=0; i<=N; i++){
        printf("Dame el elemento [%d]: \n", i);
        scanf("%d", &Lista[i]);
        ListaSinOrden[i]=arreglo[i];
    }
    return;
}

/* Ordeno los valores del arreglo */
void ordenBurbujaA(int arreglo[], int N){
    for(i=N; i>0; i--)
        for(j=1; j<= i ; j++)
            if(Lista[j-1] > Lista[j])
            {
                aux=Lista[j];
                Lista[j]=Lista[j-1];
                Lista[j-1]= aux;
            }
    return;
}
/* Ordeno los valores del arreglo */
void ordenBurbujaD(int arreglo[], int N){
    for(i=N; i>0; i--)
        for(j=1; j<= i ; j++)
            if(Lista[j-1] < Lista[j])
            {
                aux=Lista[j];
                Lista[j]=Lista[j-1];
                Lista[j-1]= aux;
            }
    return;
}

/* Imprimo los valores del arreglo */
void imprimirElementos(int arreglo[], int N){
    printf("\n");

    for( i = 1; i <= N; i++) {
        printf("Elemento [%d]=%d \n", i, arreglo[i]);
    }
    printf("\n ************************************** \n");
    printf("\n \n");
    return;
}

/* Mi super duper buscador */
void busco(int arreglo[], int N) {
    printf("\n Busqueda: ");
    printf("Ingrese la clave buscar: ");
    scanf("%d", &clave);

    int found = 0;
    for (int i = 0; i <= N; i++) {
        if (clave == Lista[i]) {
            printf("\nEureka! Lo encontré en el elemento numero %d del arreglo \n", i);
            found = 1;
        }
    }

    /* Si lo encuentro imprimo el mensaje Eureka y ademas imprimo ( para no mentir mas ;) )*/
    if (found == 0) {
        printf("\nEl valor no fue encontrado :'( \n");
    }
}