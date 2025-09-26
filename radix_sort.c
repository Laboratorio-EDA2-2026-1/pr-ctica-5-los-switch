#include <stdio.h>   
#include <stdlib.h>  

//  Función para encontrar el valor máximo en el arreglo.
//  Esto nos dice cuántos dígitos tiene el número más grande.
int elemmax(int arr[], int n) {
    int max = arr[0];                 // Suponemos que el primer elemento es el mayor
    for (int i = 1; i < n; i++) {     // Recorremos el resto del arreglo
        if (arr[i] > max)             // Si encontramos un número mayor
            max = arr[i];             // lo guardamos como nuevo máximo
    }
    return max;                       // Devolvemos el valor máximo encontrado
}

//  Counting Sort modificado para ordenar según un dígito específico 
void countingSortPorDigito(int arr[], int n, int exp) {
    int *salida = (int*)malloc(n * sizeof(int)); // Arreglo temporal de salida
    int cuenta[10] = {0};        // Contador para dígitos 0–9

    // Contar cuántos números tienen cada dígito en la posición actual
    for (int i = 0; i < n; i++)
        cuenta[(arr[i] / exp) % 10]++;

    // Convertir cuenta[] para que cada posición indique la posición final (acumulada) en el arreglo de salida
    for (int i = 1; i < 10; i++)
        cuenta[i] += cuenta[i - 1];

    // Construir el arreglo de salida en orden estable.
    for (int i = n - 1; i >= 0; i--) {
        int digito = (arr[i] / exp) % 10;            // Extraer el dígito actual
        salida[cuenta[digito] - 1] = arr[i];    // Colocar el número en la posición correcta
        cuenta[digito]--;                            // Disminuir el contador
    }

    // Copiar el arreglo ordenado de vuelta a arr[]
    for (int i = 0; i < n; i++)
        arr[i] = salida[i];

    free(salida);   // Liberar la memoria del arreglo temporal
}

//  Radix Sort principal
//  Aplica countingSortPorDigito para cada dígito, de menor a mayor
void radixSort(int arr[], int n) {
    int max = elemmax(arr, n);  // Número más grande, para saber cuántos dígitos tiene

    // Repetir counting sort para cada dígito:
    for (int exp = 1; max / exp > 0; exp *= 10)
        countingSortPorDigito(arr, n, exp);
}

//  Función para imprimir el arreglo en pantalla
void imprimirArreglo(int arr[], int n) {
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);  // Imprimir cada número seguido de un espacio
    printf("\n");               // Salto de línea al final
}


int main() {
    int arr[] = {86, 107, 42, 90, 802, 332, 6, 32}; // Datos de prueba
    int n = sizeof(arr) / sizeof(arr[0]);         // Cantidad de elementos

    printf("Arreglo original:\n");
    imprimirArreglo(arr, n);                      // Mostrar arreglo antes de ordenar

    radixSort(arr, n);                            // Llamar a Radix Sort

    printf("\nArreglo ordenado:\n");
    imprimirArreglo(arr, n);                      // Mostrar arreglo ordenado

    return 0;   
}
