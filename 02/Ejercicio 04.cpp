/*
HECHO POR CRISTIAN ALVEAR EL VIERNES 24/10/25
4. Implementa un programa de control de acceso que simule un sistema de
seguridad en un edificio. El programa debe:
• Solicitar al usuario que ingrese su nombre de usuario y contraseña. Usa un
ciclo repetitivo para mantener el sistema pidiendo los datos hasta que el
usuario haya ingresado correctamente las credenciales.
• Si las credenciales son incorrectas (usuario o contraseña incorrectos), el
programa debe:
Mostrar un mensaje de error y permitir 3 intentos.
Si el usuario supera los 3 intentos sin éxito, mostrar el mensaje "Acceso
bloqueado" y finalizar el programa.
• Si el usuario ingresa correctamente las credenciales, el sistema debe:
Mostrar el mensaje de bienvenida y permitir que el usuario ingrese a un
menú de opciones:
1. Consultar saldo
2. Cambiar contraseña
3. Salir
En caso de seleccionar la opción 2 (Cambiar contraseña):
• Solicitar una nueva contraseña y confirmarla (el programa debe
asegurarse de que la contraseña confirmada coincida con la nueva).
• Si las contraseñas coinciden, cambiar la contraseña y mostrar un mensaje
de éxito. Si no coinciden, mostrar un mensaje de error y permitir reintentar
la confirmación.
• Al seleccionar 3 (Salir), el programa debe terminar.

*/
#include <iostream>
#include <string>
using namespace std;

int main() {
    string ussp="Cris";
    string passp="1221";
    string uss, pass, passn1,passn2;
    int n,i=0,j=1;
    
while(i<3){
    cout<<"Ingrese su usuario"<<endl; cin>>uss;
    cout<<"Ingrese su contrasenia"<<endl;cin>>pass;
    if(pass==passp&&uss==ussp){ 
        do{
        cout<<"1. Consultar Saldo"<<endl;
        cout<<"2. Cambiar contrasenia"<<endl;
        	cin>>n;
        switch(n){
        	case 1:
            	cout<<"Tu saldo es 0 :c"<<endl;
        	break;
        	case 2:
            	do{
				cout<<"Ingrese nueva contrasenia"<<endl;cin>>passn1;
            	cout<<"Confirme su contrasenia"<<endl;cin>>passn2;
				if(passn1!=passn2){
					cout<<"No coincide, intente nuevamente"<<endl;
				}	            	
            	}while(passn1!=passn2);
            	cout<<"Contrasenia cambiada correctamente"<<endl;
            	
            	
        	break; 	
			}
		cout<<"Desea repetir hacer otra consulta? (si=1; no=0)"<<endl;cin>>j;
        }while(j==0);
   	 }
    else{
        cout<<"=================================="<<endl;	
        cout<<"Usuario o Contrasenia Incorrecta"<<endl;
        cout<<"=================================="<<endl;
        }

        i++;
}

    if(i==3){
    cout <<"Usuario Bloqueado"<<endl;
    }
    else{
        cout<<"PROGRAMA TERMINADO"<<endl;
    }
    
    
 return 0;
}