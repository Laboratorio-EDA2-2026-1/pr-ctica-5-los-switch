// Escribe aquí la implementación de los ejercicios de búsqueda lineal.

//Busqueda linea simple

#include <stdio.h>

int buscarLineal(int arr[], int n, int valorBuscado) {
    // Itera a través del arreglo desde el primer elemento 
    for (int i = 0; i < n; i++) {
        // Compara el elemento actual con el valor buscado
        if (arr[i] == valorBuscado) {
            // Si hay una coincidencia, devuelve la posición 
            return i;
        }
    }
    // Si el bucle termina sin encontrar el valor, devuelve -1
    return -1;
}

int main() {
    int miArreglo[] = {10, 5, 8, 12, 3, 15}; // El arreglo donde buscaremos
    int tamano = sizeof(miArreglo) / sizeof(miArreglo[0]); // Calcula el tamaño del arreglo
    int valor_a_buscar = 8; // El valor que queremos encontrar

    // Llama a la función de búsqueda lineal
    int posicion = buscarLineal(miArreglo, tamano, valor_a_buscar);

    // Muestra el resultado
    if (posicion != -1) {
        printf("El valor %d se encontró en la posición %d\n", valor_a_buscar, posicion);
    } else {
        printf("El valor %d no se encontró en el arreglo\n", valor_a_buscar);
    }

    // Ejemplo buscando un valor que no está en el arreglo
    valor_a_buscar = 99;
    posicion = buscarLineal(miArreglo, tamano, valor_a_buscar);
    if (posicion != -1) {
        printf("El valor %d se encontró en la posición %d\n", valor_a_buscar, posicion);
    } else {
        printf("El valor %d no se encontró en el arreglo\n", valor_a_buscar);
    }

    return 0;
}


//Busqueda de linea mejorada
#include <stdio.h>

// Función para realizar la búsqueda lineal mejorada
int busquedaLinealMejorada(int arr[], int n, int clave) {
    // Colocar la clave al final del arreglo para actuar como centinela
    arr[n] = clave;
    int i = 0;
    while (arr[i] != clave) {
        i++;
    }

    // Si el índice es n (la última posición), significa que la clave no estaba originalmente
    // en el arreglo (la encontramos en el centinela). Si es menor que n, se encontró.
    if (i < n) {
        return i; // Devuelve el índice donde se encontró la clave
    } else {
        return -1; // Indica que el elemento no está en el arreglo (si no se encontró en las primeras n posiciones)
    }
}

int main() {
    int arr[] = {10, 2, 8, 5, 12};
    int clave = 5;
    int n = sizeof(arr) / sizeof(arr[0]);

    // Una mejor versión podría usar un arreglo auxiliar o copiar el arreglo.
    int indice = busquedaLinealMejorada(arr, n, clave);

    if (indice != -1) {
        printf("El elemento %d se encontró en el índice: %d\n", clave, indice);
    } else {
        printf("El elemento %d no se encontró en el arreglo.\n", clave);
    }

    // Para otro caso donde el elemento no está
    clave = 99;
    indice = busquedaLinealMejorada(arr, n, clave);
    if (indice != -1) {
        printf("El elemento %d se encontró en el índice: %d\n", clave, indice);
    } else {
        printf("El elemento %d no se encontró en el arreglo.\n", clave);
    }

    return 0;
}