#include "Arbol.h"

Arbol::Arbol()
{
    this->Raiz=0;
}
//buscar y modificar
Arbol::BuscayModifica(int posz,std::string dato, Lista_Matriz*lt,int dx,int dy,int dr,int dg,int db){
    if(lt!=0){
        BuscayModifica(posz,dato,lt->izquierda,dx,dy,dr,dg,db);
        if(dato==lt->NombreCubo){
            printf("Encontrado");
            lt->BuscaryModificarMatriz(posz,dato,dx,dy,dr,dg,db);
        }
        BuscayModifica(posz,dato,lt->derecha,dx,dy,dr,dg,db);
    }
}

//seleccion de nodo
Lista_Matriz* Arbol::BuscarSeleccion(std::string dato, Lista_Matriz*lt,Lista_Matriz *rt){
    if(lt==0){

    }else{
        rt=BuscarSeleccion(dato,lt->izquierda,rt);


        if(dato==lt->NombreCubo){
            //se compia el cubo
            char name[100];
            strcpy(name, dato.c_str());
            Lista_Matriz *nuevo=new Lista_Matriz(name);
            nuevo->image_height=lt->image_height;
            nuevo->image_width=lt->image_width;
            nuevo->pixel_height=lt->pixel_height;
            nuevo->pixel_width=lt->pixel_width;
            //recorremos la lista y la copiamos

                Nodo_Matriz *tem=lt->inicio;
                tem=tem->siguiente;
                while(tem!=0){
                    char nm[200];
                    strcpy(nm, tem->NombreDocumento.c_str());
                    Nodo_Matriz*nuevoNodo=new Nodo_Matriz(tem->Z,nm);
                    tem->CopiarMatriz(nuevoNodo);

                    nuevo->InsertarMatrizSinCarga(tem->Z,nm,nuevoNodo);
                    tem=tem->siguiente;
                }
            //fin de recorrer la lista
            printf("Encontrado");
            rt=nuevo;
            return rt;
        }


        rt=BuscarSeleccion(dato,lt->derecha,rt);
    }
    return rt;
}

//empiza metodos para raficar
Arbol::GraficarARBOL(){
        std::ofstream file;
    file.open("GraficaARBOL.dot");
    Lista_Matriz* tem=Raiz;

    //datos de grafica
    CadenaGRAFICA = "digraph GraficaARBOL { \n";
    CadenaGRAFICA += "size=\"9,9\" \n";
    CadenaGRAFICA += "rankdir=TB \n" ;
    CadenaGRAFICA += "node[shape=record,style=filled]\n" ;
    //creacion de nodos
    Nomb.clear();
    DatosGraficaARBOL(Raiz);
    //creacion de relaciones

    CadenaGRAFICA+="}";
    file<<CadenaGRAFICA;
    file.close();
    system("dot -Tpng GraficaARBOL.dot -o  GraficaARBOL.png");
    system("Start GraficaARBOL.png");
}
Arbol::DatosGraficaARBOL(Lista_Matriz* lt){
    //altura imagen
    std::stringstream ss;
    std::string mgh;
    ss.str(std::string());
    ss.clear();
    ss<<lt->image_height;
    ss>>mgh;
    //ancho de la imagen
    std::stringstream ss2;
    std::string mgwd;
    ss2.str(std::string());
    ss2.clear();
    ss2<<lt->image_width;
    ss2>>mgwd;
    //altura pixel
    std::stringstream ss3;
    std::string mghp;
    ss3.str(std::string());
    ss3.clear();
    ss3<<lt->pixel_height;
    ss3>>mghp;
    //ancho del pixel
    std::stringstream ss4;
    std::string mgwdp;
    ss4.str(std::string());
    ss4.clear();
    ss4<<lt->pixel_width;
    ss4>>mgwdp;

    if(lt->izquierda==0 && lt->derecha==0){
        CadenaGRAFICA += "\""+ lt->NombreCubo+"\"" +"[label =\"<C0>|<C1>"+lt->NombreCubo+": Altura y Ancho:Cubo("+mgh+","+ mgwd+") Pixel("+mghp+","+mgwdp+")|<C2>\"]; \n" ;
    }else{
        CadenaGRAFICA += "\""+ lt->NombreCubo+"\"" +"[label =\"<C0>|<C1>"+lt->NombreCubo+": Altura y Ancho:Cubo("+mgh+","+mgwd+ ") Pixel("+mghp+","+mgwdp+")|<C2>\"]; \n" ;
    }
    if(lt->izquierda!=0){
        DatosGraficaARBOL(lt->izquierda);
        CadenaGRAFICA += "\""+ lt->NombreCubo+"\":C0->"+"\""+lt->izquierda->NombreCubo+"\"; \n" ;
    }
    if(lt->derecha!=0){
        DatosGraficaARBOL(lt->derecha);
        CadenaGRAFICA += "\""+ lt->NombreCubo+"\":C2->"+"\""+lt->derecha->NombreCubo+"\"; \n" ;
    }
}

Arbol::GraficaInorden(){
    std::ofstream file;
    file.open("GraficaArbolINORDEN.dot");
    Lista_Matriz* tem=Raiz;

    //datos de grafica
    CadenaGRAFICA = "digraph GraficaINORDEN { \n";
    CadenaGRAFICA += "size=\"9,9\" \n";
    CadenaGRAFICA += "rankdir=LR \n" ;
    CadenaGRAFICA += "node[shape=circle,style=filled]\n" ;
    //creacion de nodos
    Nomb.clear();
    DatosGraficaI(Raiz);
    //creacion de relaciones
    for(int i=0;i<Nomb.size();i++){

        if(i+1<Nomb.size()){
            CadenaGRAFICA+="\""+Nomb[i]+"\"->";
        }
    }
    CadenaGRAFICA+="\""+Nomb[Nomb.size()-1]+"\"";
    CadenaGRAFICA+="}";
    file<<CadenaGRAFICA;
    file.close();
    system("dot -Tpng GraficaArbolINORDEN.dot -o  GraficaArbolINORDEN.png");
    system("Start GraficaArbolINORDEN.png");
}
Arbol::DatosGraficaI(Lista_Matriz* lt){
    if(lt==0){
        //no imprime nada
    }else{
        DatosGraficaI(lt->izquierda);

        CadenaGRAFICA += "\""+ lt->NombreCubo+"\"" +"[label ="+"\""+lt->NombreCubo+ "\"] \n" ;
        Nomb.push_back(lt->NombreCubo);
        DatosGraficaI(lt->derecha);
    }

}
Arbol::GraficaPsorden(){
    std::ofstream file;
    file.open("GraficaArbolPOSORDEN.dot");
    Lista_Matriz* tem=Raiz;

    //datos de grafica
    CadenaGRAFICA = "digraph GraficaPOSORDEN { \n";
    CadenaGRAFICA += "size=\"9,9\" \n";
    CadenaGRAFICA += "rankdir=LR \n" ;
    CadenaGRAFICA += "node[shape=circle,style=filled]\n" ;
    //creacion de nodos
    Nomb.clear();
    DatosGraficaPOS(Raiz);
    //creacion de relaciones
    for(int i=0;i<Nomb.size();i++){

        if(i+1<Nomb.size()){
            CadenaGRAFICA+="\""+Nomb[i]+"\"->";
        }
    }
    CadenaGRAFICA+="\""+Nomb[Nomb.size()-1]+"\"";
    CadenaGRAFICA+="}";
    file<<CadenaGRAFICA;
    file.close();
    system("dot -Tpng GraficaArbolPOSORDEN.dot -o  GraficaArbolPOSORDEN.png");
    system("Start GraficaArbolPOSORDEN.png");
}
Arbol::DatosGraficaPOS(Lista_Matriz* lt){
    if(lt==0){
        //no imprime nada
    }else{
        DatosGraficaPOS(lt->izquierda);
        DatosGraficaPOS(lt->derecha);
        CadenaGRAFICA += "\""+ lt->NombreCubo+"\"" +"[label ="+"\""+lt->NombreCubo+ "\"] \n" ;
        Nomb.push_back(lt->NombreCubo);

    }

}
Arbol::GraficaProrden(){
    std::ofstream file;
    file.open("GraficaArbolPREORDEN.dot");
    Lista_Matriz* tem=Raiz;

    //datos de grafica
    CadenaGRAFICA = "digraph GraficaPRESORDEN { \n";
    CadenaGRAFICA += "size=\"9,9\" \n";
    CadenaGRAFICA += "rankdir=LR \n" ;
    CadenaGRAFICA += "node[shape=circle,style=filled]\n" ;
    //creacion de nodos
    Nomb.clear();
    DatosGraficaPRE(Raiz);
    //creacion de relaciones
    for(int i=0;i<Nomb.size();i++){

        if(i+1<Nomb.size()){
            CadenaGRAFICA+="\""+Nomb[i]+"\"->";
        }
    }
    CadenaGRAFICA+="\""+Nomb[Nomb.size()-1]+"\"";
    CadenaGRAFICA+="}";
    file<<CadenaGRAFICA;
    file.close();
    system("dot -Tpng GraficaArbolPREORDEN.dot -o  GraficaArbolPREORDEN.png");
    system("Start GraficaArbolPREORDEN.png");
}
Arbol::DatosGraficaPRE(Lista_Matriz* lt){
    if(lt==0){
        //no imprime nada
    }else{
        CadenaGRAFICA += "\""+ lt->NombreCubo+"\"" +"[label ="+"\""+lt->NombreCubo+ "\"] \n" ;
        Nomb.push_back(lt->NombreCubo);
        DatosGraficaPRE(lt->izquierda);
        DatosGraficaPRE(lt->derecha);

    }
}
//termina metodos para graficar
Arbol::MostrarInorden(Lista_Matriz* lt){
    if(lt==0){
        //no imprime nada
    }else{
        MostrarInorden(lt->izquierda);
        printf("Img: %s\n",lt->NombreCubo.c_str());
        MostrarInorden(lt->derecha);
    }
}
//metodo para seleccion de arbol
Arbol::BuscarArbol(int posz,std::string dato, Lista_Matriz*lt){
    if(lt!=0){
        BuscarArbol(posz,dato,lt->izquierda);
        if(dato==lt->NombreCubo){
            lt->MostrarLista(posz);
        }
        BuscarArbol(posz,dato,lt->derecha);
    }
}
//Busqueda para la linealizacion
Arbol::BuscarArbolLineal(int filaycolumna,int posz,std::string dato, Lista_Matriz*lt){
    if(lt!=0){
        BuscarArbolLineal(filaycolumna,posz,dato,lt->izquierda);
        if(dato==lt->NombreCubo){
            lt->MostrarListaLineal(filaycolumna,posz);
        }
        BuscarArbolLineal(filaycolumna,posz,dato,lt->derecha);
    }
}

Arbol::InsertarCubo(char Nombre[],char ruta[]){
    Lista_Matriz *nuevo=new Lista_Matriz(Nombre);
    char chartem[150];
    strcpy(chartem,ruta);
    CargaTotal(nuevo,strcat(chartem,"inicial.csv"),ruta);
    printf("%s\n",chartem);


    Lista_Matriz *tem=Raiz;
    if(Raiz==0){
        Raiz=nuevo;
    }else{
        while(tem!=0){
            if(tem->NombreCubo.compare(Nombre)>0){
                //inserta lado izquierdo
                if(tem->izquierda==0){
                    tem->izquierda=nuevo;
                    break;
                }

                tem=tem->izquierda;
            }else{
                //inserta lado derecho
                if(tem->derecha==0){
                    tem->derecha=nuevo;
                    break;
                }
                tem=tem->derecha;
            }
        }

    }
}
Arbol::CargaTotal(Lista_Matriz*nuevo,char rutaA[], char ruta[]){
    int capa=-1;
    char archivoCapa[150];
    int primeralinea=0;


    std::fstream archivo(rutaA);
    if(archivo.fail()){
       printf("El archivo T no se logro abrir \n");
    }else{
        for (std::string linea; std::getline(archivo, linea); )
        {
            std::stringstream registro(linea);
            for (std::string dato; std::getline(registro, dato, ','); )
            {

                if(primeralinea==0){
                    //no toma en cuenta la primera linea
                }else{
                    if(capa==-1){
                        capa=atoi(dato.c_str());
                    }
                    else{
                        dato.copy(archivoCapa, dato.size() + 1);
                        archivoCapa[dato.size()] = '\0';
                    }
                }

            }
            //iteracion para que no tome en cuenta la primera linea
            primeralinea+=1;
            //if para ver si es el archivo de configuracion o no
            if(capa==0||capa==-1){
                //archivo de configuracion
                if(capa==0){
                    char chartem[150];
                    strcpy(chartem,ruta);
                    nuevo->InsertarConfiguracion(strcat(chartem,archivoCapa));


                }
            }else{
                char chartem[150];
                strcpy(chartem,ruta);
                nuevo->InsertarMatrizOrdenado(capa,strcat(chartem,archivoCapa));
            }
            //reinicia el contador de capa
            capa=-1;

        }
    }
    //temporal
    //nuevo->MostrarLista(5);
    //printf("image_heigh: %d\n",nuevo->image_height);
    //printf("image_width: %d\n",nuevo->image_width);
    //printf("pixel_height: %d\n",nuevo->pixel_height);
    //printf("pixel_width: %d\n",nuevo->pixel_width);

}

Arbol::~Arbol()
{
    //dtor
}
