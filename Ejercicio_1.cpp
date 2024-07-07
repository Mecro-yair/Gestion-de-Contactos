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

int numContactosRegistrados = 0;
contactoEmail contactos[100];

void agregarContacto() {
    if (numContactosRegistrados < 100) {
        contactoEmail nuevoContacto;
        cin.ignore();
        cout << "Digite sus nombres y apellidos completos: "; getline(cin, nuevoContacto.nombresCompletos);
        cout << "Digite su sexo (masculino M, femenino F): "; cin >> nuevoContacto.sexo;
        cout << "Digite su edad: "; cin >> nuevoContacto.edad;
        cout << "Digite su telefono: "; getline(cin, nuevoContacto.telefono);
        cout << "Digite su correo: "; getline(cin, nuevoContacto.email);
        cout << "Digite su nacionalidad: "; getline(cin, nuevoContacto.nacionalidad);
        contactos[numContactosRegistrados+1] = nuevoContacto; //Desperdiciando memoria de indice 0
    } else {
        cout << "No es posible agregar más contactos,capacidad maxima.\n";
    }
}


int main() {
	SetConsoleOutputCP(CP_UTF8);
    char opcion;
    do {
        cout << "BIENVENIDO A LA GESTION DE CONTACTOS.\n\n"
             << "a) Agregar un contacto\n"
             << "b) Eliminar un contacto\n"
             << "c) Mostrar listado general de contactos registrados hasta ese momento.\n"
             << "d) Mostrar listado de contactos existentes, ordenado por servidor de correo de las cuentas\n"
             << "e) Salir del programa\n"
             << "Selecciona una opción: "<< endl;
        cin >> opcion;
        switch(opcion) {
            case 'a':
                agregarContacto();
                break;
            case 'b':
                break;
            case 'c':
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