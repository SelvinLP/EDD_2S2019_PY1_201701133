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
    //arbol->MostrarInorden(arbol->Raiz);
    arbol->InsertarCubo("S");
    arbol->InsertarCubo("A");
    arbol->InsertarCubo("B");
    arbol->InsertarCubo("Z");
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
        system("cls");
        if(opcionmenu==1){
            cout <<" Ingrese Nombre del Archivo "<<endl;
            char nombre[150];
            std::cin >> nombre;
            //arbol->CargaTotal(nombre);
            arbol->InsertarCubo(nombre);

        }
        if(opcionmenu==2){
            arbol->MostrarInorden(arbol->Raiz);
            cout <<" Seleccione una imagen "<<endl;
            char seleccionado;
            cin>>seleccionado;
        }
        if(opcionmenu==3){
            cout <<"    1.Imported Imagen Report"<<endl;
            cout <<"    2.Image Layer Report"<<endl;
            cout <<"    3.Liner Matriz Report"<<endl;
            cout <<"    4.Traversal Report"<<endl;
            cout <<"    5.Filter Report"<<endl;
            int opcionmenu2;
            cin>>opcionmenu2;
            if(opcionmenu2==4){
                int menuopc=0;
                system("cls");
                while(menuopc!=4){
                    cout <<"    1.Inorden Traversal"<<endl;
                    cout <<"    2.Preorden Traversal"<<endl;
                    cout <<"    3.Postorden Traversal"<<endl;
                    cout <<"    4.Salir"<<endl;
                    cin>>menuopc;
                    if(menuopc==1){

                    }
                    if(menuopc==2){

                    }
                    if(menuopc==3){

                    }
                }
            }
        }
        if(opcionmenu==7){
            ciclomenu=1;
        }

    }
    return 0;
}
