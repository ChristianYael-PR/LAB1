#include <stdio.h>
#include <string.h>
#include <stdbool.h>

bool es_palindromo(int x) {
    if (x < 0) return false;  // Los n�meros negativos no pueden ser pal�ndromos

    char str[12];  // Tama�o suficiente para un entero de 32 bits
    sprintf(str, "%d", x);  // Convertir el n�mero a cadena

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
    printf("Introduce un n�mero entero: ");
    scanf("%d", &numero);

    if (es_palindromo(numero)) {
        printf("El n�mero %d es un pal�ndromo.\n", numero);
    } else {
        printf("El n�mero %d no es un pal�ndromo.\n", numero);
    }

    return 0;
}

