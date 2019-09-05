#include "Lista_Matriz.h"

Lista_Matriz::Lista_Matriz(char nombreC[])
{
    //para el arbol
    this->NombreCubo=nombreC;
    this->izquierda=0;
    this->derecha=0;
    this->image_height=0;
    this->image_width=0;
    this->pixel_height=0;
    this->pixel_width=0;
    //para el nodo
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
Lista_Matriz::InsertarConfiguracion(char NombreConfig[]){
    int primeralinea=0;
    std::string capa="no";
    int valor;

    std::fstream archivo(NombreConfig);
    if(archivo.fail()){
        printf("Archivo Configuracion No Cargado\n");
    }else{
        printf("Archivo Configuracion Cargado\n");
        for (std::string linea; std::getline(archivo, linea); )
        {
            std::stringstream registro(linea);
            for (std::string dato; std::getline(registro, dato, ';'); )
            {
                if(primeralinea==0){

                }else{
                    if(capa=="no"){
                        capa=dato;
                    }
                    else{
                        valor=atoi(dato.c_str());

                    }
                }

            }
            if(capa=="image_width"){
                this->image_width=valor;
            }
            if(capa=="image_height"){
                this->image_height=valor;
            }
            if(capa=="pixel_width"){
                this->pixel_width=valor;
            }
            if(capa=="pixel_height"){
                this->pixel_height=valor;
            }
            primeralinea+=1;
            capa="no";
        }
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
