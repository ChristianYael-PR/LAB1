#include <stdio.h>
#include <string.h>
#include <stdbool.h>

bool es_palindromo(int x) {
    if (x < 0) return false;  // Los números negativos no pueden ser palíndromos

    char str[12];  // Tamaño suficiente para un entero de 32 bits
    sprintf(str, "%d", x);  // Convertir el número a cadena

    int izquierda = 0, derecha = strlen(str) - 1;
    while (izquierda < derecha) {
        if (str[izquierda] != str[derecha])
            return false;
        izquierda++;
        derecha--;
    }
    return true;
}

int main() {
    int numero;
    printf("Introduce un número entero: ");
    scanf("%d", &numero);

    if (es_palindromo(numero)) {
        printf("El número %d es un palíndromo.\n", numero);
    } else {
        printf("El número %d no es un palíndromo.\n", numero);
    }

    return 0;
}

