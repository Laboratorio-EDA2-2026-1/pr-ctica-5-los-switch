#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

// Prototipo de la función 
void counting_sort_alphabet(char* A, int n, int case_sensitive);

int main() {
    int n;
    printf("Ingrese la cantidad de caracteres que tendrá su arreglo: ");
    if (scanf("%d", &n) != 1 || n <= 0) {
        printf("Entrada inválida o cantidad no positiva.\n");
        return 1; // Retorno de error
    }
    
    char *A = (char*)calloc(n + 1, sizeof(char)); 
    if (A == NULL) { 
        return 1;
    }
    
    printf("Ingrese los %d caracteres (separados por un espacio):\n", n);
    for (int i = 0; i < n; i++) {
        if (scanf(" %c", &A[i]) != 1) {
            printf("Error al leer el carácter %d.\n", i + 1);
            free(A);
            return 1;
        }
    }
    A[n] = '\0';

    printf("Arreglo original: %s\n", A);
    
    // Preguntar al usuario si su array es sensible a mayúsculas / minúsculas
    int case_sensitive;
    printf("¿Desea ordenamiento sensible a mayúsculas/minúsculas? (1 = Sí, 0 = No): ");
    if (scanf("%d", &case_sensitive) != 1) {
        printf("Entrada inválida.\n");
        free(A);
        return 1;
    }

    // Llamada a la función de ordenamiento corregida
    counting_sort_alphabet(A, n, case_sensitive);

    printf("Arreglo ordenado: %s\n", A);

    free(A);
    
    return 0;
}

void counting_sort_alphabet(char* A, int n, int case_sensitive) {
    if (n <= 0 || A == NULL) return;
    
    char* output = (char*)malloc(n * sizeof(char));
    if (output == NULL) {
        printf("Error: No se pudo asignar memoria\n");
        return;
    }
    
    if (case_sensitive) {
        // CASE SENSITIVE: 52 letras (A-Z + a-z)
        int count[52] = {0};
        
        // Contar frecuencia de cada letra
        for (int i = 0; i < n; i++) {
            if (isupper(A[i])) {
                count[A[i] - 'A']++; // A-Z: índices 0-25
            } else if (islower(A[i])) {
                count[A[i] - 'a' + 26]++; // a-z: índices 26-51
            }
            // Ignorar caracteres no alfabéticos
        }
    
        // Reconstruir array ordenado
        int index = 0;
        
        // Primero las mayúsculas A-Z
        for (int i = 0; i < 26; i++) {
            for (int j = 0; j < count[i]; j++) {
                output[index++] = 'A' + i;
            }
        }
    
        // Luego las minúsculas a-z
        for (int i = 26; i < 52; i++) {
            for (int j = 0; j < count[i]; j++) {
                output[index++] = 'a' + (i - 26);
            }
        }
    
    } else {
        // CASE INSENSITIVE: 26 letras (solo minúsculas)
        int count[26] = {0};
        
        // Contar frecuencia (convertir todo a minúsculas)
        for (int i = 0; i < n; i++) {
            if (isalpha(A[i])) {
                count[tolower(A[i]) - 'a']++;
            }
        }
    
        // Reconstruir array ordenado (todo en minúsculas)
        int index = 0;
        for (int i = 0; i < 26; i++) {
            for (int j = 0; j < count[i]; j++) {
                output[index++] = 'a' + i;
            }
        }
    }
    
    // Copiar resultado al array original
    for (int i = 0; i < n; i++) {
        A[i] = output[i];
    }

    free(output);
}
