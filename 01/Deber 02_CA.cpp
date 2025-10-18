//Ejercicio 02
/*
Calculadora de precio final según categoria
"Electrónica" (se aplica un 20% de impuesto).
"Ropa" (se aplica un 10% de impuesto).
"Alimentos" (se aplica un 5% de impuesto).

2. Si el precio es mayor a 1000, se aplica un descuento del 10% sobre el
precio original antes de calcular el impuesto.

Determinar el precio final
*/

#include<iostream>
using namespace std;

int main(){
	double p, d, i, pf;
	int c;
	
	//Imprimimos y leemos las variables
	cout<<"Elija la categoria del producto"<<endl;
	cout<<"1. Electronica"<<endl;
	cout<<"2. Ropa"<<endl;
	cout<<"3. Alimentos"<<endl;
	cin>>c;
	cout<<"Digite el precio del producto"<<endl;cin>>p;
	
	if(c==1){
		i=p*0.2;
		cout<<"Su precio es: "<<p<<endl;
		cout<<"Su impuesto es de: "<<i<<endl;
		if(p>1000){
			d=p*0.1;
			cout<<"Su descuento es de: "<<d<<endl;
		}
		else{
			cout<<"no tiene descuento: "<<endl;
			d= 0;
		}
		pf=p+i-d;
		
		cout<<"Su precio final es: "<<pf<<endl;		
	}
	else if(c==2){
		i=p*0.1;
		cout<<"Su precio es: "<<p<<endl;
		cout<<"Su impuesto es de: "<<i<<endl;
		if(p>1000){
			d=p*0.1;
			cout<<"Su descuento es de: "<<d<<endl;
		}
		else{
			cout<<"no tiene descuento: "<<endl;
			d= 0;
		}
		pf=p+i-d;
		
		cout<<"Su precio final es: "<<pf<<endl;	
		}
	else{
		i=p*0.05;
		cout<<"Su precio es: "<<p<<endl;
		cout<<"Su impuesto es de: "<<i<<endl;
		if(p>1000){
			d=p*0.1;
			cout<<"Su descuento es de: "<<d<<endl;
		}
		else{
			cout<<"no tiene descuento: "<<endl;
			d= 0;
		}
		pf=p+i-d;
		
		cout<<"Su precio final es: "<<pf<<endl;	
	}	
	
	return 0;
	}
	
