/*
EJERCICIO 02 DE LA AA04
BY Cristian Alvear

Escribe un programa en C++ que reciba un número entero positivo n y
muestre el número primo más grande que sea menor que n, usando
funciones recursivas.
*/

#include <iostream>
using namespace std;

//Declaramos funciones usadas
int esPrimo(int num, int div);
int primoAnterior(int n);   

//Función principal
int main() {
    int n;

    cout << "Introduce un numero entero positivo: ";
    cin >> n;

    if (n <= 2) {
        cout << "No hay numeros primos menores que " << n << endl;
        return 0;
    }

    int respuesta = primoAnterior(n);

    if (respuesta == -1)
        cout << "No hay numeros primos menores que " << n << endl;
    else
        cout << "El numero primo mas grande menor que " << n
             << " es: " << respuesta << endl;

    return 0;
}

//Función para ver si es primo
// 1 es primo  y 0 no es primo

int esPrimo(int num, int div) {
    if (num < 2)
        return 0;

    if (div * div > num)
        return 1;

    if (num % div == 0)
        return 0;

    return esPrimo(num, div + 1);
}
//Función donde se usa la recursividad
// Función que busca el primo anterior

int primoAnterior(int n) {
    if (n <= 2)
        return -1;

    if (esPrimo(n - 1, 2) == 1)
        return n - 1;

    return primoAnterior(n - 1);
}