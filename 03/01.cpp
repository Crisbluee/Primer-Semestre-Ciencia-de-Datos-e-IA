/*
EJERCICIO 1 DE LA AAA03
BY CRISTIAN ALVEAR
*************************************************************************
Crea un programa que permita a los usuarios ingresar notas para varios
estudiantes y calcular el promedio de las notas ingresadas. El programa
debe permitir al usuario ingresar varias notas hasta que decida terminar.
Implementa la sobrecarga de funciones para calcular el promedio de las
notas, aceptando tanto enteros como flotantes.
Consideraciones:
• Define funciones sobrecargadas para calcular el promedio de las
notas.
• El programa debe permitir al usuario ingresar notas de tipo int y float.
• Utiliza un bucle do-while para permitir al usuario ingresar notas de
manera repetitiva.
• Al final, muestra el promedio de las notas ingresadas.
*/
#include <iostream>
using namespace std;


int prom(int a, int b);
float prom(float a, float b);

int main()
{
    float n=0, m=0,k=0;
    
    do{
        cout<<"Ingrese la nota: "<<endl;
        cout<<"Para terminar (=111)"<<endl;
        cin>>n;
        if(n!=111){
        m+=n;
        k+=1;
        }
        
    }while(n!=111) ;   
    
    cout<<"La suma es: "<<m<<endl;
    
    prom(m,k);
    cout<<"El promedio es: "<<prom(m,k);
    
    return 0;
}

int prom(int a, int b){
    return a/b;
}

float prom(float a, float b){
    return a/b;
}