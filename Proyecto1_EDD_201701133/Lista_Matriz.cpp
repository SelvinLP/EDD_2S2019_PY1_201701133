#include "Lista_Matriz.h"

Lista_Matriz::Lista_Matriz()
{
    this->inicio=new Nodo_Matriz(-1,"INICIO");
}

Lista_Matriz::MostrarLista(int posz){
    Nodo_Matriz *tem=inicio;
    while(tem!=0){
        printf("Descripcion: %s\n",tem->NombreDocumento.c_str());
        printf("Profundidad:  %d\n",tem->Z);
        if(tem->Z==posz){
                tem->GraficarMatriz();
        }
        tem=tem->siguiente;
    }
}

Lista_Matriz::InsertarMatrizOrdenado(int z,char NombreDoc []){
    Nodo_Matriz *nuevo=new Nodo_Matriz(z,NombreDoc);
    nuevo->CargarColor(NombreDoc);

    Nodo_Matriz* avance=inicio;
    Nodo_Matriz* tem=inicio;
    Nodo_Matriz* fin=0;
    bool bandera=false;
    while(avance!=0){
        if(avance->Z > z){
            bandera=true;
            tem=avance;
            break;
        }
        if(avance->siguiente==0){
            fin=avance;
        }
        avance=avance->siguiente;
    }
    if(bandera){
        //incertamos valores antes del temporal que es el encontrado
        nuevo->siguiente=tem;
        tem->anterior->siguiente=nuevo;
        nuevo->anterior=tem->anterior;
        tem->anterior=nuevo;
        bandera=false;
    }else{
        fin->siguiente=nuevo;
        nuevo->anterior=fin;
    }


}




Lista_Matriz::~Lista_Matriz()
{
    //dtor
}
