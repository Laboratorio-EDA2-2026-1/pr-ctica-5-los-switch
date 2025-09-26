// Escribe aqui la implementación de los ejercicios de búsqueda binaria.
#include <stdio.h>

// Función de búsqueda binaria recursiva
int busquedaBinariaRecursiva(int arreglo[], int izquierda, int derecha, int elemento) {
    // Verificar si todavía hay elementos por buscar
    if (derecha >= izquierda) {
        // Calcular el punto medio (evita desbordamiento)
        int medio = (derecha - izquierda) / 2;
        
        // Si encontramos el elemento en el medio, retornar su posición
        if (arreglo[medio] == elemento)
            return medio;
        
        // Si el elemento es menor que el medio, buscar en la mitad izquierda
        if (arreglo[medio] > elemento)
            return busquedaBinariaRecursiva(arreglo, izquierda, medio - 1, elemento);
        
        // Si el elemento es mayor que el medio, buscar en la mitad derecha
        return busquedaBinariaRecursiva(arreglo, medio + 1, derecha, elemento);
    }
    
    // Elemento no encontrado
    return -1;
}
