#include <iostream>
#include <stdlib.h>
#include <string>
#include <fstream>
#include <sstream>

#include<Lista_Matriz.h>
#include<Arbol.h>


using namespace std;

int main()
{
    int ciclomenu=0;
    cout << "Proyecto 1 de estructura de datos 201701133" << endl;
    //temporal
    Arbol*arbol=new Arbol();
    //Lista_Matriz* lt=new Lista_Matriz();
    //lt->InsertarMatrizOrdenado(2,"body.csv");
    //lt->InsertarMatrizOrdenado(1,"hair.csv");
    //lt->InsertarMatrizOrdenado(5,"shirt.csv");
    //lt->InsertarMatrizOrdenado(3,"dungarees.csv");

    while(ciclomenu==0){
        cout << "################# MENU ##################" << endl;
        cout <<"    1.Insertar Imagen"<<endl;
        cout <<"    2.Seleccionar Imagen"<<endl;
        cout <<"    3.Aplicar Filtros"<<endl;
        cout <<"    4.Edicion Manual"<<endl;
        cout <<"    5.Exportar Imagen"<<endl;
        cout <<"    6.Reportes"<<endl;
        cout <<"    7.Salir"<<endl;
        cout <<"    Seleccione una opcion"<<endl;
        int opcionmenu;
        cin>>opcionmenu;
        if(opcionmenu==1){
            cout <<" Ingrese Nombre del Archivo "<<endl;
            char nombre[150];
            std::cin >> nombre;
            arbol->CargaTotal(nombre);

        }
        if(opcionmenu==7){
            ciclomenu=1;
        }

    }
    return 0;
}
