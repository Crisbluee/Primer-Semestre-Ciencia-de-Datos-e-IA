/*
EJERCIIO 04 DE LA AA04
By Cristian Alvear

Escribe un programa en C++ que determine cuántos elementos de la
serie de Fibonacci se encuentran en el rango entre 1000 y 2000.
El programa debe usar funciones recursivas para:
* Generar los números de la serie de Fibonacci.
* Contar cuántos de esos números están dentro del rango solicitado.
*/

#include <iostream> 
#include <cmath>    //Pow y  Factorial
using namespace std;

// Declaración de funciones
double senoTaylor(double x, int n);
double cosenoTaylor(double x, int n);

int main() {
    double grados;
    cout << "Introduce un angulo en grados: ";
    cin >> grados;

    // Convertir a radianes
    double x = grados * 3.141592653589793 / 180.0;

    cout << "\nSeno(" << grados << ") = " << senoTaylor(x, 10)<<endl;
    cout << "\nCoseno(" << grados << ") = " << cosenoTaylor(x, 10)<<endl;

    return 0;
}

// Serie de Taylor del SENO
double senoTaylor(double x, int n) {
    if (n == 0)
        return x;

    int signo;
    if (n % 2 == 0)
        signo = 1;
    else
        signo = -1;

    double termino = signo * pow(x, 2*n + 1) / tgamma(2*n + 2);

    return termino + senoTaylor(x, n - 1);
}

// Serie de Taylor del COSENO
double cosenoTaylor(double x, int n) {
    if (n == 0)
        return 1;

    int signo;
    if (n % 2 == 0)
        signo = 1;
    else
        signo = -1;

    double termino = signo * pow(x, 2*n) / tgamma(2*n + 1);

    return termino + cosenoTaylor(x, n - 1);
}