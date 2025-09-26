#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Definimos las constantes para los colores
#define ROJO_INDEX 0
#define BLANCO_INDEX 1
#define AZUL_INDEX 2
#define COLOR_RANGE 3

// Función para obtener los índices de los colores
int getIndexColor(const char * color) {
    if (strcmp(color, "rojo") == 0) {
        return ROJO_INDEX;
    } else if (strcmp(color, "blanco") == 0) {
        return BLANCO_INDEX;
    } else if (strcmp(color, "azul") == 0) {
        return AZUL_INDEX;
    }
    // Para valores diferentes
    return -1;
}

// Prototipo de la función 
void counting_sort_color(char** A, int n);

int main() {
    int n;
    printf("Ingrese la cantidad de colores que tendrá su arreglo: ");
    if (scanf("%d", &n) != 1 || n <= 0) {
        printf("Entrada inválida o cantidad no positiva.\n");
        return 1; // Retorno de error
    }
    
    char **A = (char**)malloc(n * sizeof(char*)); 
    if (A == NULL) { 
        printf("Error: No se pudo asignar memoria\n");
        return 1;
    }
    
    // Asignar memoria para cada cadena
    for (int i = 0; i < n; i++) {
        A[i] = (char*)malloc(20 * sizeof(char)); // Asumimos máximo 19 caracteres
        if (A[i] == NULL) {
            printf("Error: No se pudo asignar memoria para la cadena %d\n", i + 1);
            // Liberar memoria ya asignada
            for (int j = 0; j < i; j++) {
                free(A[j]);
            }
            free(A);
            return 1;
        }
    }
    
    printf("Ingrese los %d colores (separados por un espacio):\n", n);
    printf("Colores disponibles: 'rojo', 'blanco', 'azul'\n");
    for (int i = 0; i < n; i++) {
        if (scanf("%19s", A[i]) != 1) {
            printf("Error al leer la cadena %d.\n", i + 1);
            // Liberar memoria
            for (int j = 0; j < n; j++) {
                free(A[j]);
            }
            free(A);
            return 1;
        }
    }
    
    printf("Arreglo original: ");
    for (int i = 0; i < n; i++) {
        printf("%s ", A[i]);
    }
    printf("\n");

    // Llamada a la función de ordenamiento (corregido el nombre)
    counting_sort_color(A, n);

    printf("Arreglo ordenado: ");
    for (int i = 0; i < n; i++) {
        printf("%s ", A[i]);
    }
    printf("\n");

    // Liberar memoria
    for (int i = 0; i < n; i++) {
        free(A[i]);
    }
    free(A);
    
    return 0;
}

void counting_sort_color(char **A, int n) {
    if (n <= 0 || A == NULL) return;
    
    int count[COLOR_RANGE] = {0};
    
    char** output = (char**)malloc(n * sizeof(char*));
    if (output == NULL) {
        printf("Error: No se pudo asignar memoria\n");
        return;
    }
    
    // Contamos la frecuencia de cada color
    for (int i = 0; i < n; i++) {
        int index = getIndexColor(A[i]);
        if (index != -1) {
            count[index]++;
        } else {
            printf("Color no reconocido: %s, se omitirá\n", A[i]);
        }
    }
    
    // Modificamos el count para almacenar las posiciones acumuladas
    for (int i = 1; i < COLOR_RANGE; i++) {
        count[i] += count[i - 1];
    }
    
    // Construimos el arreglo ordenado
    for (int i = n - 1; i >= 0; i--) {
        char *colorActual = A[i];
        int index = getIndexColor(colorActual);
        if (index != -1) {
            output[count[index] - 1] = colorActual;
            count[index]--;
        } 
    }
        
    // Copiar resultado al array original
    for (int i = 0; i < n; i++) {
        A[i] = output[i];
    }

    free(output);
}
