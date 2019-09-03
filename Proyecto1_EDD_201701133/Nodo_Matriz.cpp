#include "Nodo_Matriz.h"

Nodo_Matriz::Nodo_Matriz(int z,std::string NombreDoc)
{
    //creacion de la raiz
    this->inicio=new Nodo_Color(-1,-1,"RAIZ");
    //para el cubo o lista
    this->Z=z;
    this->NombreDocumento=NombreDoc;
    this->anterior=0;
    this->siguiente=0;
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
        //para x
        std::stringstream ssx;
        std::string stconverx;
        ssx.str(std::string());
        ssx.clear();
        ssx<<tem->X;
        ssx>>stconverx;
        //para y
        std::stringstream ssy;
        std::string stconvery;
        ssy.str(std::string());
        ssy.clear();
        ssy<<tem->Y;
        ssy>>stconvery;

        tem2=tem;
        CadenaImprimir +=  "\""+ tem->Color+stconverx+stconvery+"\"" +"[label ="+"\""+"{";
        CadenaImprimir +=  tem->Color+ "}\",group = "+stconver+"] \n" ;
        tem2=tem2->abajo;
        while(tem2!=0){
            //para x
            std::stringstream ssx;
            std::string stconverx;
            ssx.str(std::string());
            ssx.clear();
            ssx<<tem2->X;
            ssx>>stconverx;
            //para y
            std::stringstream ssy;
            std::string stconvery;
            ssy.str(std::string());
            ssy.clear();
            ssy<<tem2->Y;
            ssy>>stconvery;

            CadenaImprimir +=  "\""+ tem2->Color+stconverx+stconvery+"\"" +"[label ="+"\""+"{";
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
            //para x
            std::stringstream ssx;
            std::string stconverx;
            ssx.str(std::string());
            ssx.clear();
            ssx<<tem2->X;
            ssx>>stconverx;
            //para y
            std::stringstream ssy;
            std::string stconvery;
            ssy.str(std::string());
            ssy.clear();
            ssy<<tem2->Y;
            ssy>>stconvery;

            CadenaImprimir+="\""+ tem2->Color+stconverx+stconvery+"\";";
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
            //para x
            std::stringstream ssx;
            std::string stconverx;
            ssx.str(std::string());
            ssx.clear();
            ssx<<tem2->X;
            ssx>>stconverx;
            //para y
            std::stringstream ssy;
            std::string stconvery;
            ssy.str(std::string());
            ssy.clear();
            ssy<<tem2->Y;
            ssy>>stconvery;

            if(tem2->abajo!=0){
                //para x
                std::stringstream ssx2;
                std::string stconverx2;
                ssx2.str(std::string());
                ssx2.clear();
                ssx2<<tem2->abajo->X;
                ssx2>>stconverx2;
                //para y
                std::stringstream ssy2;
                std::string stconvery2;
                ssy2.str(std::string());
                ssy2.clear();
                ssy2<<tem2->abajo->Y;
                ssy2>>stconvery2;

                CadenaImprimir+="\""+ tem2->Color+stconverx+stconvery+"\" -> \""+ tem2->abajo->Color+stconverx2+stconvery2+"\""+"\n";
                CadenaImprimir+="\""+ tem2->Color+stconverx+stconvery+"\" -> \""+ tem2->abajo->Color+stconverx2+stconvery2+"\""+"[dir=back]\n";
            }
            if(tem2->siguiente!=0){
                //para x
                std::stringstream ssx2;
                std::string stconverx2;
                ssx2.str(std::string());
                ssx2.clear();
                ssx2<<tem2->siguiente->X;
                ssx2>>stconverx2;
                //para y
                std::stringstream ssy2;
                std::string stconvery2;
                ssy2.str(std::string());
                ssy2.clear();
                ssy2<<tem2->siguiente->Y;
                ssy2>>stconvery2;
                CadenaImprimir+="\""+ tem2->Color+stconverx+stconvery+"\" -> \""+ tem2->siguiente->Color+stconverx2+stconvery2+"\""+"\n";
                CadenaImprimir+="\""+ tem2->Color+stconverx+stconvery+"\" -> \""+ tem2->siguiente->Color+stconverx2+stconvery2+"\""+"[dir=back]\n";
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
Nodo_Matriz::CargarColor(char ruta[]){
    int x=1;
    int y=1;
    std::fstream archivo(ruta);
    if(archivo.fail()){
        printf("Archivo Color No Cargado");
    }else{
        printf("Archivo Color Cargado");
        for (std::string linea; std::getline(archivo, linea); )
        {
            std::stringstream registro(linea);
            for (std::string dato; std::getline(registro, dato, ';'); )
            {
                if(dato!="x" && dato!="X"){
                    InsertarColor(x,y,dato);
                }

                x+=1;
            }
            y+=1;
            x=1;
        }
    }
}
Nodo_Matriz::MostrarTodo(){
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
Nodo_Matriz::BuscarY(int valory){
    Nodo_Color* tem=inicio;
    while(tem !=0){
        if(tem->Y==valory){
            return 1;
        }
        tem=tem->abajo;
    }
    return 0;
}
Nodo_Matriz::BuscarX(int valorx){
    Nodo_Color* tem=inicio;
    while(tem !=0){
        if(tem->X==valorx){
            return 1;
        }
        tem=tem->siguiente;
    }
    return 0;
}
Nodo_Matriz::CrearFilaY (int valory){
    std::stringstream ss;
    std::string stconver;
    ss.str(std::string());
    ss.clear();
    ss<<valory;
    ss>>stconver;

    Nodo_Color* raizFila=inicio;
    Nodo_Color* tem=inicio;
    Nodo_Color* fin=0;
    Nodo_Color* nuevo=new Nodo_Color(-1,valory,("Fila: "+stconver));
    bool bandera=false;
    while(raizFila!=0){
        if(raizFila->Y>valory){
            bandera=true;
            tem=raizFila;
            break;
        }
        if(raizFila->abajo==0){
            fin=raizFila;
        }
        raizFila=raizFila->abajo;
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
Nodo_Matriz::CrearColumnaX (int valorx){
    std::stringstream ss;
    std::string stconver;
    ss.str(std::string());
    ss.clear();
    ss<<valorx;
    ss>>stconver;

    Nodo_Color* raizColumna=inicio;
    Nodo_Color* tem=inicio;
    Nodo_Color* fin=0;
    Nodo_Color* nuevos=new Nodo_Color(valorx,-1,("COL: "+stconver));
    bool bandera=false;
    while(raizColumna!=0){
        if(raizColumna->X > valorx){
            bandera=true;
            tem=raizColumna;
            break;
        }
        if(raizColumna->siguiente==0){
            fin=raizColumna;
        }
        raizColumna=raizColumna->siguiente;
    }
    if(bandera){
        //incertamos valores antes del temporal que es el encontrado
        nuevos->siguiente=tem;
        tem->anterior->siguiente=nuevos;
        nuevos->anterior=tem->anterior;
        tem->anterior=nuevos;
        bandera=false;
    }else{
        fin->siguiente=nuevos;
        nuevos->anterior=fin;
    }

}
Nodo_Matriz::InsertarenX(Nodo_Color* nuevo){
    bool bandera=false;
    Nodo_Color* Cabeza=inicio;
    Nodo_Color* tem=Cabeza;
    Nodo_Color* fin=0;
    while(Cabeza!=0){
        if(Cabeza->X==nuevo->X){
            if(Cabeza->Y>nuevo->Y){
                bandera=true;
                tem=Cabeza;
                break;
            }
            if(Cabeza->abajo==0){
                fin=Cabeza;
            }
            Cabeza=Cabeza->abajo;
        }else{
            Cabeza=Cabeza->siguiente;
        }


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
Nodo_Matriz::InsertarenY(Nodo_Color* nuevo){
    bool bandera=false;
    Nodo_Color* Cabeza=inicio;
    Nodo_Color* tem=Cabeza;
    Nodo_Color* fin=0;
    while(Cabeza!=0){
        if(Cabeza->Y==nuevo->Y){
            if(Cabeza->X>nuevo->X){
                bandera=true;
                tem=Cabeza;
                break;
            }
            if(Cabeza->abajo==0){
                fin=Cabeza;
            }
            Cabeza=Cabeza->siguiente;
        }else{
            Cabeza=Cabeza->abajo;
        }


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
Nodo_Matriz::InsertarColor(int x,int y,std::string color){
    //crecion de nuevo nodo con los datos
    Nodo_Color* nuevo=new Nodo_Color(x,y,color);
    int columna=BuscarX(x);
    int fila=BuscarY(y);
    //casos de insercion
    //primer caso columna y fila no existe
    if(columna==0 && fila==0){
        CrearColumnaX(x);
        CrearFilaY(y);
        InsertarenX(nuevo);
        InsertarenY(nuevo);
    }else{
        if(columna!=0 && fila==0){
            //segundo caso si columna existe
            CrearFilaY(y);
            InsertarenX(nuevo);
            InsertarenY(nuevo);

        }
        else{
            if(columna==0 && fila!=0){
                //tercer caso si fila existe
                CrearColumnaX(x);
                InsertarenX(nuevo);
                InsertarenY(nuevo);

            }else{
                if(columna!=0 && fila!=0){
                    //si los dos existen
                    InsertarenX(nuevo);
                    InsertarenY(nuevo);

                }
            }
        }
    }
}

//no tocar
Nodo_Matriz::~Nodo_Matriz()
{
    //dtor
}
