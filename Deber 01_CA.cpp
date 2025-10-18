//CRISTIAN ALVEAR
//DEBER 01
/* El ejercicio nos da condiciones para aceptar la oferta de trabajo
   dependiendo de los años de experiencia y del nivel educativo,
   el ejercicio solo se divide en aquellas personas que aceptamos y 
   aquellas que rechazamos; pero, como solo nos da una sola condición
   de rechazo, se asume que todas las demás se aceptarán.
   En este caso es sencillo realizar el código sabiendo que solo
   aquellos que tienen menos de 3 años de experiencia se rechazan
   y todos los demás se aceptan
*/

#include <iostream>
using namespace std;

int main(){
	int exp, ne;
		
	cout<<"Escriba los años de experiencia: "<<endl;cin>>exp;
	cout<<"Digite el numero segun su formacion"<<endl;
	cout<<"1. Primaria"<<endl;
	cout<<"2. Secundaria"<<endl;
	cout<<"3. Universitaria"<<endl;
	cin>>ne;
	
	//Única condición para que se rechace la oferta de trabajo
	if(exp<3){
		cout<<"NO SE APRUEBA SU OFERTA DE TRABAJO"<<endl;
	}
	//Todo lo demás se aceptará 
	else{
		cout<<"SE ACEPTA SU OFERTA DE TRABAJO"<<endl;
	}

	return 0;
}

