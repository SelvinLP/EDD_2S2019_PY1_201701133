#include "Arbol.h"

Arbol::Arbol()
{
    this->Raiz=0;
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
    if(lt->izquierda==0 && lt->derecha==0){
        CadenaGRAFICA += "\""+ lt->NombreCubo+"\"" +"[label =\"<C0>|<C1>"+lt->NombreCubo+ "|<C2>\"]; \n" ;
    }else{
        CadenaGRAFICA += "\""+ lt->NombreCubo+"\"" +"[label =\"<C0>|<C1>"+lt->NombreCubo+ "|<C2>\"]; \n" ;
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
Arbol::InsertarCubo(char Nombre[],char ruta[]){
    Lista_Matriz *nuevo=new Lista_Matriz(Nombre);
    char chartem[150];
    strcpy(chartem,ruta);
    CargaTotal(nuevo,strcat(strcat(chartem,Nombre),".csv"),ruta);


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
            for (std::string dato; std::getline(registro, dato, ';'); )
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

}

Arbol::~Arbol()
{
    //dtor
}
