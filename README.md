# **Reporte: Verificación de Palíndromos**  

## **Introducción**  
En este reporte se analiza la implementación de un algoritmo que determina si un número entero es un palíndromo. Un número es un palíndromo si se lee igual de izquierda a derecha y de derecha a izquierda.  

La solución implementada utiliza la conversión del número a una cadena para facilitar la comparación de caracteres desde ambos extremos.  

---

## Explicación del Algoritmo**  

### **Entrada:**  
- Un número entero `x`.  

### **Proceso:**  
1. **Verificación de casos triviales:** Si el número es negativo, se retorna `false`, ya que los números negativos tienen el signo `-` y no pueden ser palíndromos.  
2. **Conversión a cadena:** Se usa `sprintf` para transformar el número en un arreglo de caracteres.  
3. **Comparación de caracteres:** Se inicializan dos índices:  
   - `izquierda` en la primera posición de la cadena.  
   - `derecha` en la última posición de la cadena.  
4. **Iteración:** Se comparan los caracteres de los extremos. Si en algún momento los caracteres son diferentes, se retorna `false`.  
5. **Finalización:** Si todas las comparaciones fueron exitosas, se retorna `true`.  

### **Salida:**  
- `true` si el número es un palíndromo.  
- `false` si no lo es.  

---

## **Implementación en C**  

## **Análisis de Complejidad**  
- **Conversión del número a cadena:** O(N)  
- **Comparación de caracteres:** O(N)  
- **Complejidad total:** O(N), donde N es la cantidad de dígitos del número.  
Este método es eficiente para números pequeños y medianos, pero consume más memoria que una solución matemática sin cadenas.  

---

## **Conteo de Operaciones**  

### a. Verificación de número negativo  
   - Comparación: `x < 0` → 1 operación  

### b. Conversión del número a cadena  
   - `sprintf(str, "%d", x);` → 1 operación  

### c. Obtener la longitud de la cadena  
   - Asignación: `izquierda = 0` → 1 operación  
   - Asignación: `derecha = strlen(str) - 1` → 1 operación  
   - Cálculo de longitud: `strlen(str)` → 1 operación  
   - **Total en este paso:** 3 operaciones  

### d. Comparación de caracteres en el `while`  
   - Comparación en el `while` (`izquierda < derecha`) → N/2 operaciones  
   - Comparación de caracteres (`str[izquierda] != str[derecha]`) → N/2 operaciones  
   - Incremento de `izquierda++` → N/2 operaciones  
   - Decremento de `derecha--` → N/2 operaciones  
   - **Total en este paso:** 2N operaciones  

### e. Retorno del resultado  
   - `return true;` → No se cuenta en el conteo  

### **Total de Operaciones:**  
\[
2N + 5
\]
(donde N es el número de dígitos del número ingresado)  

---

## **Conclusión**  
La implementación de la solución que verifica si un número es un palíndromo a través de la conversión a cadena es una estrategia clara y efectiva para abordar el problema. Este enfoque permite una comparación intuitiva de los caracteres, lo que simplifica la lógica del algoritmo. Sin embargo, es importante considerar las limitaciones en términos de uso de memoria y rendimiento para números muy grandes. Para aplicaciones donde el tamaño de los números es considerable, sería recomendable explorar métodos alternativos que eviten la conversión a cadena, optimizando así el uso de recursos y la eficiencia del algoritmo.

```c
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

bool es_palindromo(int x) {
    if (x < 0) return false;  // Paso 1: Si es negativo, no puede ser palíndromo

    char str[12];  // Suficiente para almacenar un entero de 32 bits
    sprintf(str, "%d", x);  // Paso 2: Convertir el número a cadena

    int izquierda = 0, derecha = strlen(str) - 1;  // Inicialización

    while (izquierda < derecha) {  // Paso 3: Comparar extremos
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



