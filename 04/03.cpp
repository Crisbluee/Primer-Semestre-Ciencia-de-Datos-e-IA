/*
EJERCIIO 03 DE LA AA04
By Cristian Alvear

Escribe un programa en C++ que determine cuántos elementos de la
serie de Fibonacci se encuentran en el rango entre 1000 y 2000.
El programa debe usar funciones recursivas para:
* Generar los números de la serie de Fibonacci.
* Contar cuántos de esos números están dentro del rango solicitado.
*/

#include <iostream>
using namespace std;

//Declaración funciones necesarias
int fibonacci(int n);
int contarEnRango(int n, int contador);

int main() {
    //Hacemos el llamado a la Función y guardamos la respuesta.
    int total = contarEnRango(0, 0);

    cout << "Cantidad de numeros de Fibonacci entre 1000 y 2000: "
         << total << endl;

    return 0;
}

// ---- Desarrollo de funciones ----

/*
 * Función recursiva que calcula el número de Fibonacci en la posición n.
 */
int fibonacci(int n) {
    if (n == 0) return 0;
    if (n == 1) return 1;

    return fibonacci(n - 1) + fibonacci(n - 2);
}

//Cuanta los números que hay entre 1000 y 2000
int contarEnRango(int n, int contador) {
    int f = fibonacci(n);

    // Si ya supera 2000, terminamos la recursión
    if (f > 2000)
        return contador;

    // Si el número está entre 1000 y 2000, lo contamos
    if (f >= 1000 && f <= 2000)
        contador++;

    // Continuar con el siguiente término de Fibonacci
    return contarEnRango(n + 1, contador);
}