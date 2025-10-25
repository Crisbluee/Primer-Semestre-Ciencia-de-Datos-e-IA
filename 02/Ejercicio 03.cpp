/*
NOMBRE: Cristian Alvear
FECHA: 24/10/2025
3. Crea un programa que simule una calculadora avanzada, con las siguientes
características:
El programa debe mostrar un menú con las siguientes opciones:
1. Sumar
2. Restar
3. Multiplicar
4. Dividir
5. Potencia (A^B)
6. Raíz cuadrada (√A)
7. Salir
• Dependiendo de la opción seleccionada, el programa debe realizar
la operación correspondiente. Para las opciones de potencia y raíz
cuadrada, el programa debe validar que el número A sea positivo.
• Si el usuario selecciona una opción inválida, debe mostrarse un
mensaje de error y el menú debe repetirse.
• El programa debe seguir pidiendo operaciones hasta que el usuario
elija Salir.
• Si el usuario intenta dividir por cero, debe mostrarse un mensaje de
error y volver a pedir los números.
• En cada operación, se debe mostrar el resultado y preguntar si desea
hacer otra operación o salir. Si elige continuar, debe repetirse el
proceso.

*/

#include <iostream>
#include <cmath>
using namespace std;

int main() {
    int m;
    float n1, n2;
    int continuar = 1;

    do {
        cout << "===== CALCULADORA =====" << endl;
        cout << "1. Suma" << endl;
        cout << "2. Resta" << endl;
        cout << "3. Multiplicacion" << endl;
        cout << "4. Division" << endl;
        cout << "5. Potencia" << endl;
        cout << "6. Raiz n-esima" << endl;
        cout << "Seleccione una opcion: ";
        cin >> m;

        switch (m) {
            case 1:
                cout << "Ingrese el primer numero: "; cin >> n1;
                cout << "Ingrese el segundo numero: "; cin >> n2;
                cout << "Resultado: " << n1 + n2 << endl;
                break;

            case 2:
                cout << "Ingrese el primer numero: "; cin >> n1;
                cout << "Ingrese el segundo numero: "; cin >> n2;
                cout << "Resultado: " << n1 - n2 << endl;
                break;

            case 3:
                cout << "Ingrese el primer numero: "; cin >> n1;
                cout << "Ingrese el segundo numero: "; cin >> n2;
                cout << "Resultado: " << n1 * n2 << endl;
                break;

            case 4:
                cout << "Ingrese el numerador: "; cin >> n1;
                cout << "Ingrese el denominador: "; cin >> n2;
                if (n2 != 0)
                    cout << "Resultado: " << n1 / n2 << endl;
                else
                    cout << "Error: Division entre 0 no permitida." << endl;
                break;

            case 5:
                cout << "Ingrese la base: "; cin >> n1;
                cout << "Ingrese el exponente: "; cin >> n2;
                cout << "Resultado: " << pow(n1, n2) << endl;
                break;

            case 6:
                cout << "Ingrese el numero base: "; cin >> n1;
                cout << "Ingrese el radical (n): "; cin >> n2;
                if (n1 >= 0 && n2 > 0)
                    cout << "Resultado: " << pow(n1, 1.0 / n2) << endl;
                else
                    cout << "Error: valores invalidos." << endl;
                break;

            default:
                cout << "Opcion no valida." << endl;
        }

        cout << "Desea realizar otra operacion? (1=Si / 0=No): ";
        cin >> continuar;

    } while (continuar == 1);

    cout << "Hasta luego!" << endl;
    return 0;
}