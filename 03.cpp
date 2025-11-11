/******************************************************
EJERCICIO 03 DE LA AA03
BY CRISTIAN ALVEAR

Desarrolla un programa que resuelva ecuaciones cuadráticas de la
forma ax² + bx + c = 0.
Implementa una función que calcule el discriminante (D = b² - 4ac) y
otra función que, según su valor, determine si la ecuación tiene:
• Dos soluciones reales y distintas
• Una solución real doble
• Dos soluciones complejas
Las soluciones deben mostrarse con dos cifras decimales si existen.
*******************************************************/
#include <iostream>
#include <cmath>
using namespace std;

//Declaro las funciones para saber con qué se está trabajando y que se vea bonito
float determinante(float a, float b, float c);
void soluciones(float d, float a, float b, float c);

//Función principal
int main() {
	//Declaro Variables
    float d, a, b, c;
    //Pido los componentes de la cuadrática
    cout << "Cuadrática en la forma ax^2 + bx + c" << endl;
    cout << "Ingrese a: "; cin >> a;
    cout << "Ingrese b: "; cin >> b;
    cout << "Ingrese c: "; cin >> c;
	//Almaceno el determinante usando la primera función
    d = determinante(a, b, c);
    cout << "Determinante: " << d << endl;
	//Con la segunda función determino la solución de la cuadrática
    soluciones(d, a, b, c);

    return 0;
}

//PRIMERA FUNCIÓN: Solo me da el determinante ezz
float determinante(float a, float b, float c) {
    return (b * b) - (4 * a * c);
}

//SEGUNDA FUNCIÓN: Esta función resuelve la cudrática según el determinante.

void soluciones(float d, float a, float b, float c) {
    float x1, x2;
	
	//Si es positivo tiene dos soluciones reales
    if (d > 0) {
        cout << "Hay dos soluciones reales distintas." << endl;
        x1 = (-b + sqrt(d)) / (2 * a);
        x2 = (-b - sqrt(d)) / (2 * a);
        cout << "x1 = " << x1 << endl;
        cout << "x2 = " << x2 << endl;
    }
    //Si es cero, solo tiene una solución
    else if (d == 0) {
        cout << "Hay una raíz real doble." << endl;
        x1 = (-b) / (2 * a);
        cout << "x = " << x1 << endl;
    }
    //Si es negativo, tiene complejos
    //Me había olvidado de esto, me tocó revisar qué honda pasa.
    else {
        cout << "Hay dos raíces complejas conjugadas." << endl;
        float parteReal = -b / (2 * a);
        float parteImag = sqrt(-d) / (2 * a);
        cout << "x1 = " << parteReal << " + " << parteImag << "i" << endl;
        cout << "x2 = " << parteReal << " - " << parteImag << "i" << endl;
    }
}