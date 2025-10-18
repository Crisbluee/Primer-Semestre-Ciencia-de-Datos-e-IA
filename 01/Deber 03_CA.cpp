//Ejercicio 03
//Alvear Cristian

#include<iostream>
using namespace std;

int main(){
	double celsius, fa;
	cout<<"Ingrese la temperatura en Celsius"<<endl; 
	cin>>celsius;
	
if(celsius>=-100&&celsius<=100)	{
	
	fa=celsius*(9/5)+32;
	cout<<"Su temperatura en Fahrenheit es: "<<fa<<endl;
	
	if(celsius<0){
		cout<<"La temperatura es muy fría"<<endl;
	}
	else if(celsius>=0 && celsius <=15){
		cout<<"La temperatura es fria"<<endl;
	}
	else if(celsius>15&&celsius<=30){
		cout<<"La temperatura es templada"<<endl;
	}
	else{
		cout<<"La temperatura es caliente"<<endl;
	}
}
else{
	cout<<"NO ESTA EN UN RANGO VALIDO"<<endl;
	}	
	return 0;
	}	

	