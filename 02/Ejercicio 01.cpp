//CRISTIAN ALVEAR
//Ejercicio 01 de la AA02

/*1. Escribe un programa que simule una votación. El programa debe permitir a
los usuarios votar por tres opciones:
• 1 para "Candidato A"
• 2 para "Candidato B"
• 3 para "Candidato C"
• 0 para terminar la votación.
El programa debe:
• Contar los votos de cada candidato.
• Al finalizar la votación, mostrar los resultados de la elección.
El ciclo debe continuar hasta que el usuario ingrese 0 para terminar.*/

#include<iostream>
using namespace std;

int main(){
	//Declaración de variables
	int a=0, b=0, c=0, voto;
	//Opciones de votación
	cout<<"VOTACIÓN 2025"<<endl;
	cout<<"1. para Candidato A"<<endl;
	cout<<"2. para Candidato B"<<endl;
	cout<<"1. para Candidato C"<<endl;
	cout<<"0. para terminar la votacion"<<endl;
	//Ciclo para ingresar votos
	do{
		cout<<"Ingrese su voto: "<<endl;cin>>voto;
		if(voto==1){
		a++;
		}
		else if(voto==2){
		b++;}
		else if(voto==3){
		c++;}
		
	}while(voto!=0);
	
	//PRESENTACIÓN DEL GANADOR
		if(a>b&&a>c){
		cout<<"GANADOR CANDIDATO A"<<endl;}
		else if(b>a&&b>c){
		cout<<"GANADOR CANDIDATO B"<<endl;}
		else if(c>a&&c>b){
		cout<<"GANADOR CANDIDATO C"<<endl;}
		else{
		cout<<"VOTACION EMPATADA"<<endl;}
	//PRESENTACIÓN DEL CONTEO DE VOTOS
	cout<<"Votos del canditato A: "<<a<<endl;	
	cout<<"Votos del canditato B: "<<b<<endl;
	cout<<"Votos del canditato C: "<<c<<endl;
	
	
	return 0;
}