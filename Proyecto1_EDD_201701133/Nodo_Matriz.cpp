#include "Nodo_Matriz.h"

Nodo_Matriz::Nodo_Matriz(int z,std::string NombreDoc)
{
    //creacion de la raiz
    this->inicio=new Nodo_Color(-1,-1,"RAIZ",0,0,0);
    //para el cubo o lista
    this->Z=z;
    this->NombreDocumento=NombreDoc;
    this->anterior=0;
    this->siguiente=0;
}
//graficas de linealizacion
Nodo_Matriz::GraficaLinealFila(){
    std::ofstream file;

    file.open("GraficaLinealFila.dot");
    Nodo_Color* tem=inicio;
    Nodo_Color* tem2=0;

    std::string CadenaImprimir= "digraph GraficaLinealFila { \n";
    CadenaImprimir += "rankdir=LR \n";
    CadenaImprimir += "size=\"9,9\" \n";
    CadenaImprimir += "node[shape=record,style=filled] \n" ;
    CadenaImprimir +=  "\"INICIO\" [label =\"{INICIO}\" ] \n" ;
    //creacion de nodos
    tem=tem->abajo;
    while(tem !=0){
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
        tem2=tem2->siguiente;

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
            //para R
            std::stringstream sr;
            std::string tr;
            sr.str(std::string());
            sr.clear();
            sr<<tem2->R;
            sr>>tr;
            //para G
            std::stringstream sg;
            std::string tg;
            sg.str(std::string());
            sg.clear();
            sg<<tem2->G;
            sg>>tg;
            //para B
            std::stringstream sb;
            std::string tb;
            sb.str(std::string());
            sb.clear();
            sb<<tem2->B;
            sb>>tb;

            CadenaImprimir +=  "\""+ tem2->Color+stconverx+stconvery+"\"" +"[label ="+"\""+"{("+stconverx+","+stconvery+")";
            CadenaImprimir +=  tr+"-"+tg+"-"+tb+"}\" ] \n" ;

            tem2=tem2->siguiente;
        }
        tem=tem->abajo;
    }


    //creacion de realciones
    Nodo_Color* tem3=inicio;
    Nodo_Color* tem4=0;
    tem3=tem3->abajo;
    while(tem3 !=0){
        if(tem3->abajo==0){
            //validar el fin de la relaciones
            tem4=tem3;
            tem4=tem4->siguiente;
            while(tem4!=0){
                std::stringstream ssx;
                std::string stconverx;
                ssx.str(std::string());
                ssx.clear();
                ssx<<tem4->X;
                ssx>>stconverx;
                //para y
                std::stringstream ssy;
                std::string stconvery;
                ssy.str(std::string());
                ssy.clear();
                ssy<<tem4->Y;
                ssy>>stconvery;

                if(tem4->siguiente==0){
                    CadenaImprimir +=  "\""+ tem4->Color+stconverx+stconvery+"\" \n";

                }else{
                    CadenaImprimir +=  "\""+ tem4->Color+stconverx+stconvery+"\" -> ";
                }
                tem4=tem4->siguiente;
            }
        }else{
            tem4=tem3;
            tem4=tem4->siguiente;
            while(tem4!=0){
                std::stringstream ssx;
                std::string stconverx;
                ssx.str(std::string());
                ssx.clear();
                ssx<<tem4->X;
                ssx>>stconverx;
                //para y
                std::stringstream ssy;
                std::string stconvery;
                ssy.str(std::string());
                ssy.clear();
                ssy<<tem4->Y;
                ssy>>stconvery;

                CadenaImprimir +=  "\""+ tem4->Color+stconverx+stconvery+"\" -> ";
                tem4=tem4->siguiente;
            }
        }
        tem3=tem3->abajo;
    }



        std::stringstream ssx;
        std::string stconverx;
        ssx.str(std::string());
        ssx.clear();
        ssx<<inicio->abajo->siguiente->X;
        ssx>>stconverx;
        //para y
        std::stringstream ssy;
        std::string stconvery;
        ssy.str(std::string());
        ssy.clear();
        ssy<<inicio->abajo->siguiente->Y;
        ssy>>stconvery;
    CadenaImprimir+="\"INICIO\" ->\""+inicio->abajo->siguiente->Color+stconverx+stconvery+"\" \n";
    CadenaImprimir+="}";
    file<<CadenaImprimir;
    file.close();
    system("dot -Tpng GraficaLinealFila.dot -o  GraficaLinealFila.png");
    system("Start GraficaLinealFila.png");

}

Nodo_Matriz::GraficaLinealColumna(){
    std::ofstream file;

    file.open("GraficaLinealColumna.dot");
    Nodo_Color* tem=inicio;
    Nodo_Color* tem2=0;

    std::string CadenaImprimir= "digraph GraficaLinealColumna { \n";
    CadenaImprimir += "rankdir=LR \n";
    CadenaImprimir += "size=\"9,9\" \n";
    CadenaImprimir += "node[shape=record,style=filled] \n" ;
    CadenaImprimir +=  "\"INICIO\" [label =\"{INICIO}\" ] \n" ;
    //creacion de nodos
    tem=tem->siguiente;
    while(tem !=0){
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

                //para R
            std::stringstream sr;
            std::string tr;
            sr.str(std::string());
            sr.clear();
            sr<<tem2->R;
            sr>>tr;
            //para G
            std::stringstream sg;
            std::string tg;
            sg.str(std::string());
            sg.clear();
            sg<<tem2->G;
            sg>>tg;
            //para B
            std::stringstream sb;
            std::string tb;
            sb.str(std::string());
            sb.clear();
            sb<<tem2->B;
            sb>>tb;

            CadenaImprimir +=  "\""+ tem2->Color+stconverx+stconvery+"\"" +"[label ="+"\""+"{("+stconverx+","+stconvery+")";
            CadenaImprimir +=  tr+"-"+tg+"-"+tb+ "}\" ] \n" ;

            tem2=tem2->abajo;
        }
        tem=tem->siguiente;
    }


    //creacion de realciones
    Nodo_Color* tem3=inicio;
    Nodo_Color* tem4=0;
    tem3=tem3->siguiente;
    while(tem3 !=0){
        if(tem3->siguiente==0){
            //validar el fin de la relaciones
            tem4=tem3;
            tem4=tem4->abajo;
            while(tem4!=0){
                std::stringstream ssx;
                std::string stconverx;
                ssx.str(std::string());
                ssx.clear();
                ssx<<tem4->X;
                ssx>>stconverx;
                //para y
                std::stringstream ssy;
                std::string stconvery;
                ssy.str(std::string());
                ssy.clear();
                ssy<<tem4->Y;
                ssy>>stconvery;

                if(tem4->abajo==0){
                    CadenaImprimir +=  "\""+ tem4->Color+stconverx+stconvery+"\" \n";

                }else{
                    CadenaImprimir +=  "\""+ tem4->Color+stconverx+stconvery+"\" -> ";
                }
                tem4=tem4->abajo;
            }
        }else{
            tem4=tem3;
            tem4=tem4->abajo;
            while(tem4!=0){
                std::stringstream ssx;
                std::string stconverx;
                ssx.str(std::string());
                ssx.clear();
                ssx<<tem4->X;
                ssx>>stconverx;
                //para y
                std::stringstream ssy;
                std::string stconvery;
                ssy.str(std::string());
                ssy.clear();
                ssy<<tem4->Y;
                ssy>>stconvery;

                CadenaImprimir +=  "\""+ tem4->Color+stconverx+stconvery+"\" -> ";
                tem4=tem4->abajo;
            }
        }
        tem3=tem3->siguiente;
    }



        std::stringstream ssx;
        std::string stconverx;
        ssx.str(std::string());
        ssx.clear();
        ssx<<inicio->siguiente->abajo->X;
        ssx>>stconverx;
        //para y
        std::stringstream ssy;
        std::string stconvery;
        ssy.str(std::string());
        ssy.clear();
        ssy<<inicio->siguiente->abajo->Y;
        ssy>>stconvery;
    CadenaImprimir+="\"INICIO\" ->\""+inicio->siguiente->abajo->Color+stconverx+stconvery+"\" \n";
    CadenaImprimir+="}";
    file<<CadenaImprimir;
    file.close();
    system("dot -Tpng GraficaLinealColumna.dot -o  GraficaLinealColumna.png");
    system("Start GraficaLinealColumna.png");

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

                //para R
            std::stringstream sr;
            std::string tr;
            sr.str(std::string());
            sr.clear();
            sr<<tem2->R;
            sr>>tr;
            //para G
            std::stringstream sg;
            std::string tg;
            sg.str(std::string());
            sg.clear();
            sg<<tem2->G;
            sg>>tg;
            //para B
            std::stringstream sb;
            std::string tb;
            sb.str(std::string());
            sb.clear();
            sb<<tem2->B;
            sb>>tb;
            if(tem2->X==-1){
                CadenaImprimir +=  "\""+ tem2->Color+stconverx+stconvery+"\"" +"[label ="+"\""+"{";
                CadenaImprimir +=  tem2->Color+ "}\" ,group = "+stconver+" ] \n" ;
            }else{
                CadenaImprimir +=  "\""+ tem2->Color+stconverx+stconvery+"\"" +"[label ="+"\""+"{";
                CadenaImprimir +=  tr+" "+tg+" "+tb+ "}\" ,group = "+stconver+" ] \n" ;
            }

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

    std::string r="";
    std::string g="";
    std::string b="";


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
                    //InsertarColor(x,y,dato);
                    std::stringstream CodigoColor(dato);
                    //para separarlos por colores rgb
                    for (std::string datoColor; std::getline(CodigoColor, datoColor, '-'); )
                    {
                        if(r==""){
                            r=datoColor;
                        }else{
                            if(g==""){
                                g=datoColor;
                            }else{
                                if(b==""){
                                    b=datoColor;
                                }
                            }
                        }
                    }
                    //inserta los colores

                    InsertarColor(x,y,dato,atoi(r.c_str()),atoi(g.c_str()),atoi(b.c_str()));
                    r="";
                    g="";
                    b="";
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
    Nodo_Color* nuevo=new Nodo_Color(-1,valory,("Fila: "+stconver),-1,valory,0);
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
    Nodo_Color* nuevos=new Nodo_Color(valorx,-1,("COL: "+stconver),valorx,-1,0);
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
Nodo_Matriz::InsertarColor(int x,int y,std::string color,int r,int g,int b){
    //crecion de nuevo nodo con los datos
    Nodo_Color* nuevo=new Nodo_Color(x,y,color,r,g,b);
    int columna=BuscarX(x);
    int fila=BuscarY(y);
    //para sobre escribir si tienen la misma direccion
    Nodo_Color* Cabeza=inicio;
    bool insertado=false;
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
                        while(Cabeza!=0){
                            if(Cabeza->X==nuevo->X){
                                if(Cabeza->Y==nuevo->Y){
                                    Cabeza->R=nuevo->R;
                                    Cabeza->G=nuevo->G;
                                    Cabeza->B=nuevo->B;
                                    Cabeza->Color=nuevo->Color;
                                    insertado=true;

                                    break;
                                }
                                Cabeza=Cabeza->abajo;
                            }else{
                                Cabeza=Cabeza->siguiente;
                            }


                        }

                        //caso de inserion o sobre escribir daros
                    if(insertado){
                        printf("Se modificaron datos");
                    }else{
                        InsertarenX(nuevo);
                        InsertarenY(nuevo);
                    }


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
