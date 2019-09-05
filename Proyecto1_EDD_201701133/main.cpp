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
            cout <<" Ingrese Ruta del Archivo "<<endl;
            char ruta[150];
            std::cin >> ruta;
            //arbol->CargaTotal(nombre);
            arbol->InsertarCubo(nombre,ruta);

        }
        if(opcionmenu==2){
            arbol->MostrarInorden(arbol->Raiz);
            cout <<" Seleccione una imagen "<<endl;
            char seleccionado;
            std::cin>>seleccionado;
        }
        if(opcionmenu==6){
            cout <<"    1.Imported Imagen Report"<<endl;
            cout <<"    2.Image Layer Report"<<endl;
            cout <<"    3.Liner Matriz Report"<<endl;
            cout <<"    4.Traversal Report"<<endl;
            cout <<"    5.Filter Report"<<endl;
            int opcionmenu2;
            std::cin>>opcionmenu2;
            if(opcionmenu2==1){
                arbol->GraficarARBOL();
            }
            if(opcionmenu2==4){
                cout <<"    1.Inorden Traversal"<<endl;
                cout <<"    2.Preorden Traversal"<<endl;
                cout <<"    3.Postorden Traversal"<<endl;
                cout <<"    4.Salir"<<endl;
                int menuopc;
                std::cin>>menuopc;
                if(menuopc==1){
                    arbol->GraficaInorden();
                }
                if(menuopc==2){
                    arbol->GraficaProrden();
                }
                if(menuopc==3){
                    arbol->GraficaPsorden();
                }
            }
        }
        if(opcionmenu==7){
            ciclomenu=1;
        }

    }
    return 0;
}
