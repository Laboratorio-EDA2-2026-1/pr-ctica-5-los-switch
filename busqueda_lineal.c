// Escribe aquí la implementación de los ejercicios de búsqueda lineal.


// Ejercicio 1. Búsqueda Lineal Simple
#include <stdio.h>

int busquedaLinealSimple(int arr[], int n, int objetivo) {
    // Recorre todo el arraglo desde el inicio hasta el final
    for (int i = 0; i < n; i++) {
        // Compara cada elemento con el objetivo
        if (arr[i] == objetivo) {
            return i; // Retorna la posición si encontra el elemento
        }
    }
    return -1; // Retorna -1 si no encontra el elemento
}

int main() {
    int arr[] = {9, 4, 23, 45, 7, 11, 15};
    int n = sizeof(arr) / sizeof(arr[0]);
    int objetivo = 7;
    
    int resultado = busquedaLinealSimple(arr, n, objetivo);
    
    if (resultado != -1) {
        printf("Elemento encontrado en la posición %d\n", resultado);
    } else {
        printf("Elemento no encontrado\n");
    }
    
    return 0;
}




// Ejercicio 2. Búsqueda Lineal Mejorada
#include <stdio.h>

int busquedaLinealMejorada(int arr[], int n, int objetivo) {
    // Caso arreglo vacío
    if (n <= 0) {
        return -1;
    }
    
    // Caso si el primer elemento es el objetivo
    if (arr[0] == objetivo) {
        return 0;
    }
    
    // Busca desde la posición 1 hasta el final
    for (int i = 1; i < n; i++) {
        if (arr[i] == objetivo) {
            return i; // Si encuentra el elemento objetivo retorna
        }
    }
    
    return -1; // Si no lo encuentra retorna -1
}

int main() {
    int arr[] = {9, 4, 23, 45, 7, 11, 15};
    int n = sizeof(arr) / sizeof(arr[0]);
    int objetivo = 45;
    
    int resultado = busquedaLinealMejorada(arr, n, objetivo);
    
    if (resultado != -1) {
        printf("Elemento encontrado en la posición %d\n", resultado);
    } else {
        printf("Elemento no encontrado\n");
    }
    
    return 0;
}




// Ejercicio 3. Búsqueda Lineal Recursiva
#include <stdio.h>

int busquedaLinealRecursiva(int arr[], int objetivo, int inicio, int fin) {
    // Caso si el inicio supera al fin, el elemento no fue encontrado
    if (inicio > fin) {
        return -1;
    }
    
    // Caso si encuentra el elemento en la posición actual
    if (arr[inicio] == objetivo) {
        return inicio;
    }
    
    // Llamada recursiva: busca en el siguiente elemento
    return busquedaLinealRecursiva(arr, objetivo, inicio + 1, fin);
}

int busquedaRecursiva(int arr[], int n, int objetivo) {
    return busquedaRecursiva(arr, objetivo, 0, n - 1);
}

int main() {
    int arr[] = {9, 4, 23, 45, 7, 11, 15};
    int n = sizeof(arr) / sizeof(arr[0]);
    int objetivo = 11;
    
    int resultado = busquedaRecursiva(arr, n, objetivo);
    
    if (resultado != -1) {
        printf("Elemento encontrado en la posición %d\n", resultado);
    } else {
        printf("Elemento no encontrado\n");
    }
    
    return 0;
}



// Ejercicio 4. Búsqueda Lineal con Centinela
#include <stdio.h>
#include <stdlib.h>

// Agrega el elemento buscado al final del arraglo para evitar verificar límites
int busquedaConCentinela(int arr[], int n, int objetivo) {
    // Guarda el último elemento original
    int ultimoOriginal = arr[n - 1];
    
    // Establece el centinela (objetivo) en la última posición
    arr[n - 1] = objetivo;
    
    int i = 0;
    // Busca hasta encontrar el objetivo 
    while (arr[i] != objetivo) {
        i++;
    }
    
    // Restaura el último elemento original
    arr[n - 1] = ultimoOriginal;
    
    // Verifica si encontro el objetivo antes del centinela
    if (i < n - 1 || arr[n - 1] == objetivo) {
        return i;
    }
    return -1; // Se retorna -1 si no se encontra
}

int main() {
    int arr[] = {9, 4, 23, 45, 7, 11, 15};
    int n = sizeof(arr) / sizeof(arr[0]);
    int objetivo = 15;
    
    int resultado = busquedaConCentinela(arr, n, objetivo);
    
    if (resultado != -1) {
        printf("Elemento encontrado en la posición %d\n", resultado);
    } else {
        printf("Elemento no encontrado\n");
    }
    
    return 0;
}