#include "Nodo_Matriz.h"
#include <string>
#include <stdio.h>
Nodo_Matriz::Nodo_Matriz(int z,std::string NombreDoc){
    inicio=new Nodo_Color(-1,-1,"RAIZ");
    this->siguiente=0;
    this->anterior=0;
    this->Z=z;
    this->NombreDocumento=NombreDoc;
}

Nodo_Matriz::CargaColores(char ruta[]){
    int x=0;
    int y=0;
    std::fstream archivo(ruta);
    if(archivo.fail()){
        printf("El archivo el archivo de colores no se logro abrir \n");
        printf(ruta);
    }else{
        printf("El archivo el archivo de colores se abrio Correctamente \n");
        printf(ruta);
        for (std::string linea; std::getline(archivo, linea); )
        {
            std::stringstream registro(linea);
            for (std::string dato; std::getline(registro, dato, ';'); )
            {
                if(dato!="x" && dato!="X"){
                    InsertarCodigo(x,y,dato);
                    printf("Inserta %d\n",x);
                }

                x+=1;
            }
            y+=1;
            x=0;
        }
    }
}

Nodo_Matriz::GraficarMatriz(){
    std::ofstream file;
    file.open("Grafica.dot");
    Nodo_Color* tem=inicio;
    Nodo_Color* tem2=0;
    int a=1;
    int grup=1;

    std::string CadenaImprimir= "digraph Grafica { \n";
    CadenaImprimir += "size=\"9,9\" \n";
    CadenaImprimir += "node[shape=record,style=filled] \n" ;
    //creacion de nodos
    while(tem !=0){
        std::stringstream ss;
        std::string stconver;
        ss.str(std::string());
        ss.clear();
        ss<<grup;
        ss>>stconver;

        tem2=tem;
        CadenaImprimir +=  "\""+ tem->Color+"\"" +"[label ="+"\""+"{";
        CadenaImprimir +=  tem->Color+ "}\",group = "+stconver+"] \n" ;
        tem2=tem2->abajo;
        while(tem2!=0){
            CadenaImprimir +=  "\""+ tem2->Color+"\"" +"[label ="+"\""+"{";
            CadenaImprimir +=  tem2->Color+ "}\" ,group = "+stconver+" ] \n" ;
            tem2=tem2->abajo;
        }
        grup+=1;
        tem=tem->siguiente;
    }
    //cracion de relaciones
    tem=inicio;
    while(tem!=0){
        tem2=tem;
        CadenaImprimir+="{rank = same;";
        while(tem2!=0){
            CadenaImprimir+="\""+ tem2->Color+"\";";
            tem2=tem2->siguiente;
        }
        CadenaImprimir+="}\n";
        tem=tem->abajo;
    }
    //fon de posicionamiento
    tem=inicio;
    while(tem !=0){
        tem2=tem;
        while(tem2!=0){
            if(tem2->abajo!=0){
                CadenaImprimir+="\""+ tem2->Color+"\" -> \""+ tem2->abajo->Color+"\""+"\n";
                CadenaImprimir+="\""+ tem2->Color+"\" -> \""+ tem2->abajo->Color+"\""+"[dir=back]\n";
            }
            if(tem2->siguiente!=0){
                CadenaImprimir+="\""+ tem2->Color+"\" -> \""+ tem2->siguiente->Color+"\""+"\n";
                CadenaImprimir+="\""+ tem2->Color+"\" -> \""+ tem2->siguiente->Color+"\""+"[dir=back]\n";
            }

            tem2=tem2->abajo;

        }
        tem=tem->siguiente;
    }


    CadenaImprimir+="}";
    file<<CadenaImprimir;
    file.close();
    system("dot -Tpng Grafica.dot -o  Grafica.png");
    system("Start Grafica.png");
}

Nodo_Matriz::mostrartodox(){
    Nodo_Color* tem=inicio;
    Nodo_Color* tem2=0;
    tem=tem->siguiente;
    while(tem !=0){
        tem2=tem;
        while(tem2!=0){
            printf("Descripcion: %s\n",tem2->Color.c_str());
            printf("Fila %d\n",tem2->Y);
            printf("Columna %d\n",tem2->X);
            tem2=tem2->abajo;
        }
        tem=tem->siguiente;
    }
}
Nodo_Matriz::mostrartodoy(){
    Nodo_Color* tem=inicio;
    Nodo_Color* tem2=0;
    tem=tem->abajo;
    while(tem !=0){
        tem2=tem;
        while(tem2!=0){
            printf("Descripcion: %s\n",tem2->Color.c_str());
            printf("Fila %d\n",tem2->Y);
            printf("Columna %d\n",tem2->X);
            tem2=tem2->siguiente;
        }
        tem=tem->abajo;
    }
}



Nodo_Matriz::BuscarX(int x){
    Nodo_Color* tem=inicio;
    while(tem !=0){
        if(tem->X==x){
            return 1;
        }
        tem=tem->siguiente;
    }
    return 0;
}

Nodo_Matriz::BuscarY(int y){
    Nodo_Color* tem=inicio;
    while(tem !=0){
        if(tem->Y==y){
            return 1;
        }
        tem=tem->abajo;
    }
    return 0;
}

Nodo_Matriz::CrearColumnaX(int x){
    std::stringstream ss;
    std::string stconver;
    ss.str(std::string());
    ss.clear();
    ss<<x;
    ss>>stconver;

    Nodo_Color *RaizColumnaX=inicio;
    Nodo_Color *tem=inicio;
    Nodo_Color *fin=0;
    Nodo_Color *nuevo=new Nodo_Color(x,-1,("COLUMNA: "+stconver));
    bool bandera=false;
    while(RaizColumnaX!=0){
        if(RaizColumnaX->X > x){
            bandera=true;
            tem=RaizColumnaX;
        }
        if(RaizColumnaX->siguiente==0){
            fin=RaizColumnaX;
        }
        RaizColumnaX=RaizColumnaX->siguiente;
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

Nodo_Matriz::CrearFilaY(int y){
    std::stringstream ss;
    std::string stconver;
    ss.str(std::string());
    ss.clear();
    ss<<y;
    ss>>stconver;

    Nodo_Color* RaizFilaY=inicio;
    Nodo_Color* tem=inicio;
    Nodo_Color* fin=0;
    Nodo_Color* nuevo=new Nodo_Color(-1,y,("Fila: "+stconver));
    bool bandera=false;
    while(RaizFilaY!=0){
        if(RaizFilaY->Y > y){
            bandera=true;
            tem=RaizFilaY;
            break;
        }
        if(RaizFilaY->abajo==0){
            fin=RaizFilaY;
        }
        RaizFilaY=RaizFilaY->abajo;
    }
    if(bandera){
        //incertamos valores antes del temporal que es el encontrado
        nuevo->abajo=tem;
        tem->arriba->abajo=nuevo;
        nuevo->arriba=tem->arriba;
        tem->arriba=nuevo;
    }else{
        fin->abajo=nuevo;
        nuevo->arriba=fin;
    }
}

Nodo_Matriz::InsertarX(Nodo_Color* nuevo){
    Nodo_Color* RaizColumnaX=inicio;
    Nodo_Color* tem2=inicio;
    Nodo_Color* fin=0;
    bool bandera=false;
    while(RaizColumnaX !=0){
        if(RaizColumnaX->X==nuevo->X){
            if(RaizColumnaX->Y > nuevo->Y){
                bandera=true;
                tem2=RaizColumnaX;
                break;
            }
            if(RaizColumnaX->abajo==0){
                fin=RaizColumnaX;
            }
            RaizColumnaX=RaizColumnaX->abajo;
        }else{
            RaizColumnaX=RaizColumnaX->siguiente;
        }
    }
    if(bandera){
        nuevo->abajo=tem2;
        tem2->arriba->abajo=nuevo;
        nuevo->arriba=tem2->arriba;
        tem2->arriba=nuevo;
    }else{
        fin->abajo=nuevo;
        nuevo->arriba=fin;
    }

}
Nodo_Matriz::InsertarY(Nodo_Color* nuevo){
    Nodo_Color* RaizFilaY=inicio;
    Nodo_Color* tem=inicio;
    Nodo_Color* fin=0;
    bool bandera=false;
    while(RaizFilaY !=0){
        if(RaizFilaY->Y==nuevo->Y){
            if(RaizFilaY->X > nuevo->X){
                bandera=true;
                tem=RaizFilaY;
                break;
            }
            if(RaizFilaY->siguiente==0){
                fin=RaizFilaY;
            }
            RaizFilaY=RaizFilaY->siguiente;
        }else{
            RaizFilaY=RaizFilaY->abajo;
        }
    }
    if(bandera){
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

Nodo_Matriz::InsertarCodigo(int x,int y, std::string color){
    Nodo_Color* nuevo=new Nodo_Color(x,y,color);
    int columna=BuscarX(x);
    int fila=BuscarY(y);
    //casos de insercion
    //primer caso columna y fila no existe
    if(columna==0 && fila==0){
        CrearColumnaX(x);
        CrearFilaY(y);
        InsertarX(nuevo);
        InsertarY(nuevo);
    }else{
        if(columna!=0 && fila==0){
            CrearFilaY(y);
            InsertarX(nuevo);
            InsertarY(nuevo);
        }else{
            if(columna==0 && fila!=0){
                CrearColumnaX(x);
                InsertarX(nuevo);
                InsertarY(nuevo);
            }else{
                if(columna!=0 && fila!=0){
                    InsertarX(nuevo);
                    InsertarY(nuevo);
                }
            }
        }
    }
}




Nodo_Matriz::~Nodo_Matriz()
{
    //dtor
}
