/*
EJERCIIO 0 DE LA AA04
By Cristian Alvear

EJERCICIO CREADO POR MÍ

CALCULADORA DE ÁREAS Y PERÍMETROS 

*/

#include <iostream>
using namespace std;

// Sobrecarga de funciones para áreas
float area(float radio);                 // Círculo
float area(float base, float altura);    // Rectángulo o triángulo

// Funciones de perímetros
float perimetroCirculo(float radio);
float perimetroCuadrado(float lado);
float perimetroRectangulo(float base, float altura);
float perimetroTriangulo(float a, float b, float c);

// Función recursiva del menú
void repetirMenu();


int main() {
    repetirMenu(); 
    return 0;
}

// Área del círculo
float area(float radio) {
    return 3.1416f * radio * radio;
}

// Área del rectángulo o triángulo (base y altura)
float area(float base, float altura) {
    return base * altura;
}

// Perímetro del círculo
float perimetroCirculo(float radio) {
    return 2 * 3.1416f * radio;
}

// Perímetro del cuadrado
float perimetroCuadrado(float lado) {
    return 4 * lado;
}

// Perímetro del rectángulo
float perimetroRectangulo(float base, float altura) {
    return 2 * (base + altura);
}

// Perímetro del triángulo
float perimetroTriangulo(float a, float b, float c) {
    return a + b + c;
}

// Función recursiva que muestra y repite el menú
void repetirMenu() {
    int opcion;

    cout << "\n===== CALCULADORA DE AREAS Y PERIMETROS =====\n";
    cout << "1. Circulo\n";
    cout << "2. Cuadrado\n";
    cout << "3. Rectangulo\n";
    cout << "4. Triangulo\n";
    cout << "5. Salir\n";
    cout << "Elige una opcion: ";
    cin >> opcion;

    if (opcion == 1) {
        float r;
        cout << "Ingresa el radio: ";
        cin >> r;

        if (r <= 0) {
            cout << "Error: el numero debe ser positivo.\n";
        } else {
            cout << "Area = " << area(r) << endl;
            cout << "Perimetro = " << perimetroCirculo(r) << endl;
        }
    }
    else if (opcion == 2) {
        float lado;
        cout << "Ingresa el lado: ";
        cin >> lado;

        if (lado <= 0) {
            cout << "Error: el numero debe ser positivo.\n";
        } else {
            cout << "Area = " << area(lado, lado) << endl;
            cout << "Perimetro = " << perimetroCuadrado(lado) << endl;
        }
    }
    else if (opcion == 3) {
        float base, altura;
        cout << "Ingresa la base: ";
        cin >> base;
        cout << "Ingresa la altura: ";
        cin >> altura;

        if (base <= 0 || altura <= 0) {
            cout << "Error: los numeros deben ser positivos.\n";
        } else {
            cout << "Area = " << area(base, altura) << endl;
            cout << "Perimetro = " << perimetroRectangulo(base, altura) << endl;
        }
    }
    else if (opcion == 4) {
        float a, b, c;
        cout << "Ingresa lado 1: ";
        cin >> a;
        cout << "Ingresa lado 2: ";
        cin >> b;
        cout << "Ingresa lado 3: ";
        cin >> c;

        if (a <= 0 || b <= 0 || c <= 0) {
            cout << "Error: los numeros deben ser positivos.\n";
        } else {
            cout << "Para el area se usa (base * altura / 2).\n";
            cout << "Tomaremos base=a y altura=b (muy básico).\n";
            cout << "Area = " << area(a, b) / 2 << endl;
            cout << "Perimetro = " << perimetroTriangulo(a, b, c) << endl;
        }
    }
    else if (opcion == 5) {
        cout << "Saliendo del programa...\n";
        return; // Caso base: no se repite más
    }
    else {
        cout << "Opcion invalida.\n";
    }

    // Llamada recursiva para mostrar el menú nuevamente
    repetirMenu();
}