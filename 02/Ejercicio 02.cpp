
/*Crea un programa que permita simular diferentes métodos de pago en un
sistema de compras. El menú debe ofrecer las siguientes opciones:
2
• Pagar con tarjeta de crédito.
• Pagar con tarjeta de débito.
• Pagar en efectivo.
• Salir.
Según la opción seleccionada, el programa debe pedir al usuario el
monto total de la compra y realizar el cálculo del pago:
• Para tarjeta de crédito: Se aplica una comisión del 5%.
• Para tarjeta de débito: No se aplica comisión.
• Para pago en efectivo: Se aplica un descuento del 2%.
El ciclo debe continuar hasta que el usuario decida salir.
Consideraciones:
• Al final de cada operación, el programa debe mostrar el monto
total después de aplicar el descuento o la comisión, según
corresponda.
• Al elegir salir, el programa debe finalizar la ejecución.*/

#include<iostream>
using namespace std;

int main(){
	double monto, monto2, descuento;
	int opcion;
	cout<<"Ingrese el monto a pagar: "<<endl;cin>>monto;
	
	
do{
	cout<<"\nElija el metodo de pago"<<endl;
	cout<<"1. Tarjeta de credito"<<endl;
	cout<<"2. Tarjeta de Debito"<<endl;
	cout<<"3. Pagar con efectivo"<<endl;
	cout<<"4. Salir"<<endl;
	cin>>opcion;
	
	switch(opcion){
	case 1: 
			descuento=monto*0.05;
			cout<<"\nSu monto a pagar es: "<<monto<<endl;
			cout<<"Descuento del 5%: "<<descuento<<endl;
			cout<<"MONTO FINAL: "<<monto-monto2<<endl;
			cout<<"__________________________"<<endl;
		break;
	case 2:
			cout<<"\nSu monto a pagar es: "<<monto<<endl;
			cout<<"No tiene descuento"<<endl;
			cout<<"MONTO FINAL: "<<monto<<endl;
			cout<<"__________________________"<<endl;
		break;
	case 3:
			descuento=monto*0.02;
			cout<<"\nSu monto a pagar es: "<<monto<<endl;
			cout<<"Descuento del 2%: "<<descuento<<endl;
			cout<<"MONTO FINAL: "<<monto-monto2<<endl;
			cout<<"__________________________"<<endl;
		break;
	}
	
	
	
}while(opcion!=4);	
	
	
	return 0;
}