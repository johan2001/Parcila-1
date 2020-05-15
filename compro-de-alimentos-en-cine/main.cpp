#include <iostream>
#include "funciones.h"

using namespace std;


int main()
{
    int modo=5,lonc=0;
    string usuario,contrasena;
    string archivo_con_usuarios_y_contrasenas;
    map<string,string>usuario_y_contrasenas;
    while (modo!=0) {
        cout << "*************************************" << endl;
        cout << "*************BIENVENIDO**************" << endl;
        cout << "*************************************" << endl;
        cout << "Para salir del programa ingrese 0" << endl;
        cout << "Para ingresar como administrativo presiones 1" << endl;
        cout << "Para ingresar como usuario presiones 2" << endl;
        cin >> modo;
        //sacos las contraseñas del archivo donde se encuetra
        archivo_con_usuarios_y_contrasenas=abrir_archivo_y_extraer_datos("usuarios.txt");
        usuario_y_contrasenas=guardar_usuarios_claves(usuario_y_contrasenas,archivo_con_usuarios_y_contrasenas);
        //menu del programa
        switch (modo) {
        case 1 :{
            int opciones =2;
            cout<< "Ingrese su nombre de usuario: ";
            cin >> usuario;
            cout<< endl << "Ingrese su contrasena: ";
            cin >> contrasena;
            cout << endl;
            char *_contrasena = &contrasena[0];
            lonc =int(contrasena.size());
            contrasena = archivo_en_binario(_contrasena,lonc);
            char *_contrasena2 = &contrasena[0];
            lonc =int(contrasena.size());
            contrasena = codificar(_contrasena2,lonc);
            if (comparar_usuario_clave(usuario_y_contrasenas,usuario,contrasena)){
                while (opciones != 0) {
                    cout << "*************************************" << endl;
                    cout << "******BIENVENIDO ADMINISTRADOR********" << endl;
                    cout << "*************************************" << endl;
                    cout << "para agregar productos al invetraio ingrese 1" << endl;
                    cout << "para registrar nuevos usuarios ingrese 2 " << endl;
                    cout << "Para armar combos ingrese 3" << endl;
                    cout << "para salir ingrese 0 " << endl;
                    cin >> opciones;
                    switch (opciones) {
                    case 1:{
                    break;
                        }
                    case 2:{
                    break;
                    }
                    case 3:{
                        break;
                    }
                    default: cout<<endl<< "opcion no valido" <<endl;
                    }

                }
            }
            else{cout <<endl<< "usuarios o clave no valida"<<endl;}
        }
        break;
        case 2 :{
            break;
        }

        default:
            cout<< "modo no disonible" <<endl;

        }
    }
    return 0;
}


