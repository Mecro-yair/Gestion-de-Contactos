/*
1. Gestión de Contactos
Crear una estructura llamada contactoEmail que tenga las siguientes características: nombres completos, 
sexo, edad, teléfono, email, nacionalidad
El programa debe constar de un menú que permita:
a) Agregar un contacto
b) Eliminar un contacto
c) Mostrar listado general de contactos registrados hasta ese momento.
d) Mostrar listado de contactos existentes, ordenado por servidor de correo de las cuentas (gmail.com, 
outlook.com, yahoo.com, etc.)
e) Salir del programa
El programa debe mantenerse en ejecución continuamente hasta que usuario indique que desea salir del 
mismo
*/
#include <iostream>
#include <string>
#include <windows.h>
using namespace std;

struct contactoEmail {
    string nombresCompletos;
    char sexo;
    int edad;
    string telefono;
    string email;
    string nacionalidad;
};
//UNIVERSALES
int numContactosRegistrados = 0;
contactoEmail contactos[100];

void agregarContacto() {
    if (numContactosRegistrados < 100) {
        contactoEmail nuevoContacto;
        cin.ignore();
        cout << "Digite sus nombres y apellidos completos: "; getline(cin, nuevoContacto.nombresCompletos);
        cout << "Digite su sexo (masculino M, femenino F): "; cin >> nuevoContacto.sexo;
        cout << "Digite su edad: "; cin >> nuevoContacto.edad;
        cin.ignore();
        cout << "Digite su telefono: "; getline(cin, nuevoContacto.telefono);
        cout << "Digite su correo: "; getline(cin, nuevoContacto.email);
        cout << "Digite su nacionalidad: "; getline(cin, nuevoContacto.nacionalidad);
        contactos[numContactosRegistrados] = nuevoContacto;
		numContactosRegistrados++; 
    } else {
        cout << "No es posible agregar más contactos,capacidad maxima.\n";
    }
}

void mostrarContactos() {
	SetConsoleOutputCP(CP_UTF8);
    for (int i = 0; i < numContactosRegistrados; ++i) {
    	cout<<"\nContacto "<<i+1<<":\n";
        cout << "\nNombre: " << contactos[i].nombresCompletos << "\nSexo: " << contactos[i].sexo
             << "\nEdad: " << contactos[i].edad << "\nTelefono: " << contactos[i].telefono
             << "\nEmail: " << contactos[i].email << "\nNacionalidad: " << contactos[i].nacionalidad << endl;
             
    }
    if (numContactosRegistrados==0){
    	cout<<"NO TIENE CONTACTOS AGREGADOS.";
	}
}

void eliminarContacto() {
    string email;
    cout << "Digite el correo del contacto a eliminar: "; cin >> email; //Pedire numero.
    bool encontrado = false;
    
    for (int i = 0; i < numContactosRegistrados; ++i) {
        if (contactos[i].email == email) {
            for (int j = i; j < numContactosRegistrados - 1; ++j) {
                contactos[j] = contactos[j + 1];
            }
            numContactosRegistrados--;
            encontrado = true;
            cout << "El contacto digitado se a eliminado correctamente.\n";
            break;
        }
    }
    if (!encontrado) { //!encontrado: si no se encontro nada
        cout << "El contacto pedido a eliminar no existe.\n";
    }
}

int main() {
	SetConsoleOutputCP(CP_UTF8);
    char opcion;
    do {
    	
        cout << "\n\nBIENVENIDO A LA GESTION DE CONTACTOS.\n\n"
             << "a) Agregar un contacto\n"
             << "b) Eliminar un contacto\n"
             << "c) Mostrar listado general de contactos registrados hasta ese momento.\n"
             << "d) Mostrar listado de contactos existentes, ordenado por servidor de correo de las cuentas\n"
             << "e) Salir del programa\n"
             << "\nSelecciona una opción: "<< endl;
        cin >> opcion;
        switch(opcion) {
            case 'a':
            	system("cls");
                agregarContacto();
                break;
            case 'b':
            	eliminarContacto();
                break;
            case 'c':
            	system("cls");
            	mostrarContactos();
                break;
            case 'd':
                break;
            case 'e':
                break;
            default:
                cout << "Opcion invalida. Intente otra vez.\n\n";
                
                break;
        }
    } while(opcion != 'e');
    return 0;
}