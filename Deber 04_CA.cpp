//Cristian Alvear
//Deber 04

#include<iostream>
using namespace std;

int main(){
	
	//El numero secreto será 12 porque es mi numero favorito
	int nsecreto=12, n, i=0;
	
	do{
		cout<<"Adivina mi número favorito, ingresa un numero"<<endl; cin>>n;
		if(n>nsecreto){
			cout<<"Muy alto"<<endl;
		}
		else if(n<nsecreto){
			cout<<"Muy bajo"<<endl;
		}
		else{
			cout<<"FELICIDADES ADIVINASTE"<<endl;
		}
		i+=1;
	}while(n!=nsecreto);
	cout<<"Adivinaste en: "<<i<<" intentos"<<endl;
	
	
	return 0;
}