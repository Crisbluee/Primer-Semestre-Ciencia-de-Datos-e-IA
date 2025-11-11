/*
EJERCICIO 02 DE LA AA03
BY CRISTIAN ALVEAR
 Desarrolla un programa que convierta una cantidad en dinero a
monedas de diferentes denominaciones. El programa debe utilizar
2
funciones para calcular el número de monedas que corresponden a
cada denominación (por ejemplo, 1 dólar y 50, 25, 10, 5, 1 centavos).
Consideraciones:
• Crea una función que reciba una cantidad en dinero y devuelva el
número de monedas de cada denominación.
• El programa debe permitir al usuario ingresar una cantidad y mostrar
cómo se puede dividir en monedas.
(Me divertí con este ej)
*/

#include <iostream>
#include <cmath>
using namespace std;

void cambio(int plata){
    
    int dolar, c50, c25, c10, c5, c1;
    
    //Primero mod para los dólares, luego mod de lo que salió de eso
    // y mod para lo que salió de eso, y así.
    // Yo me entiendo, debió haber una forma más sencilla xd
    
    dolar=trunc(plata/100);
    c50=trunc((plata%100)/50);
    c25=trunc(((plata%100)%50)/25);
    c10=trunc((((plata%100)%50)%25) /10 );
    c5=trunc(((((plata%100)%50)%25)%10) /5 );
    c1=trunc((((((plata%100)%50)%25)%10)%5)/1);
    
    cout<<"Monedas de Dólar: "<<dolar<<endl;
    cout<<"Monedas de 50: "<<c50<<endl;
    cout<<"Monedas de 25: "<<c25<<endl;
    cout<<"Monedas de 10: "<<c10<<endl;
    cout<<"Monedas de 5: "<<c5<<endl;
    cout<<"Monedas de 1: "<<c1<<endl;
}

int main()
{
    float plata;
    cout<<"Ingrese la plata "<<endl;
    cin>>plata;
    plata=plata*100;
    cambio(plata);

    return 0;
}