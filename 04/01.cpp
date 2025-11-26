/*
EJERCICIO 01 DE LA AA04
BY Cristian Alvear

Escribe una función recursiva que genere todas las permutaciones
posibles de una cadena de texto.
Por ejemplo:
Entrada: "abc".
 Salida:
abc
acb
bac
bca
cab
cba
La cadena puede ser de 2 caracteres en adelante sin restricciones de
cantidad de caracteres.

*/

#include <iostream>
#include <string>
using namespace std;


void generarPermutaciones(string &s, int i) {

    // Caso base de la recursión:
    // Si 'i' es la última posición, ya se generó una permutación completa.
    if (i == (int)s.size() - 1) {
        cout << s << endl;
        return;
    }

    // Intercambiamos el elemento de 'i' con cada posición 'j'
    // para generar nuevas combinaciones.
    for (int j = i; j < (int)s.size(); j++) {
        swap(s[i], s[j]);               // Intercambiar para fijar un carácter
        generarPermutaciones(s, i + 1); // hacer la recursividad
        swap(s[i], s[j]);               // arreglar
    }
}

int main() {
    string cadena;

    cout << "Introduce una cadena (al menos 2 caracteres): ";
    cin >> cadena;
    //CASO BASE
    if (cadena.size() < 2) {
        cout << "La cadena debe tener al menos 2 caracteres." << endl;
        return 0;
    }
    
    //LLAMADA A LA FUNCIÓN RECURSIVA
    cout << "\nPermutaciones posibles:\n";
    generarPermutaciones(cadena, 0);

    return 0;
}