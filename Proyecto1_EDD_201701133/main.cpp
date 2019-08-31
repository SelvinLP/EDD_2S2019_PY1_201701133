#include <iostream>
#include <stdlib.h>
#include <string>
#include <fstream>
#include <sstream>


#include <Nodo_Matriz.h>
#include<Lista_Matrices.h>
#include<Arbol.h>
using namespace std;

int main()
{
    int ciclomenu=0;
    cout << "Proyecto 1 de estructura de datos 201701133" << endl;
    Arbol *ArbolInicial=new Arbol();
    //temporal
    //Nodo_Matriz *Matriz=new Nodo_Matriz(1,"hola");
    //Matriz->InsertarCodigo(1,1,"si");
    //Matriz->InsertarCodigo(1,3,"si3");
    //Matriz->InsertarCodigo(1,2,"si2");
    //Matriz->InsertarCodigo(2,3,"no3");
    //Matriz->InsertarCodigo(5,1,"no");
    //Matriz->InsertarCodigo(3,1,"no2");
    //Matriz->mostrartodoy();
    //Matriz->mostrartodo();
    //fin temporal
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
        if(opcionmenu==7){
            ciclomenu=1;
        }

    }
    return 0;
}
