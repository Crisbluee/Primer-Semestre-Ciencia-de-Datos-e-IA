/**************************
 EJERCICIO 04 DE AA03
 BY CRISTIAN ALVEAR
 Escribe un programa que reciba un número entero positivo entre 1 y
999, y lo convierta en texto.
Por ejemplo:
• 15 → quince
• 230 → doscientos treinta
• 999 → novecientos noventa y nueve
No utilices arreglos ni cadenas; resuélvelo con funciones, condicionales
anidados y casos especiales por separado.

***************************/

#include <iostream>
using namespace std;

void unidades(int n) {
    if (n == 1) cout << "uno";
    else if (n == 2) cout << "dos";
    else if (n == 3) cout << "tres";
    else if (n == 4) cout << "cuatro";
    else if (n == 5) cout << "cinco";
    else if (n == 6) cout << "seis";
    else if (n == 7) cout << "siete";
    else if (n == 8) cout << "ocho";
    else if (n == 9) cout << "nueve";
}

void especiales(int n) {
    if (n == 10) cout << "diez";
    else if (n == 11) cout << "once";
    else if (n == 12) cout << "doce";
    else if (n == 13) cout << "trece";
    else if (n == 14) cout << "catorce";
    else if (n == 15) cout << "quince";
    else if (n < 20) { cout << "dieci"; unidades(n - 10); }
    else if (n == 20) cout << "veinte";
    else if (n < 30) { cout << "veinti"; unidades(n - 20); }
}

void decenas(int n) {
    int d = n / 10;
    int u = n % 10;

    if (n < 10) unidades(n);
    else if (n < 30) especiales(n);
    else {
        if (d == 3) cout << "treinta";
        else if (d == 4) cout << "cuarenta";
        else if (d == 5) cout << "cincuenta";
        else if (d == 6) cout << "sesenta";
        else if (d == 7) cout << "setenta";
        else if (d == 8) cout << "ochenta";
        else if (d == 9) cout << "noventa";

        if (u != 0) {
            cout << " y ";
            unidades(u);
        }
    }
}

void centenas(int n) {
    int c = n / 100;
    int r = n % 100;

    if (n == 100) cout << "cien";
    else {
        if (c == 1) cout << "ciento";
        else if (c == 2) cout << "doscientos";
        else if (c == 3) cout << "trescientos";
        else if (c == 4) cout << "cuatrocientos";
        else if (c == 5) cout << "quinientos";
        else if (c == 6) cout << "seiscientos";
        else if (c == 7) cout << "setecientos";
        else if (c == 8) cout << "ochocientos";
        else if (c == 9) cout << "novecientos";

        if (r != 0) {
            cout << " ";
            decenas(r);
        }
    }
}

int main() {
    int n;
    cout << "Ingrese un numero entre 1 y 999: ";
    cin >> n;

    if (n <= 0 || n > 999)
        cout << "Fuera de rango";
    else if (n < 100)
        decenas(n);
    else
        centenas(n);

    cout << endl;
    return 0;
}