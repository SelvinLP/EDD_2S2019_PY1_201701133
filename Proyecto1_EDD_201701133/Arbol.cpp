#include "Arbol.h"

Arbol::Arbol()
{
    this->Raiz=0;
}
//empiza metodos para raficar
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
Arbol::InsertarCubo(char ruta[]){
    Lista_Matriz *nuevo=new Lista_Matriz(ruta);
    Lista_Matriz *tem=Raiz;
    if(Raiz==0){
        Raiz=nuevo;
    }else{
        while(tem!=0){
            if(tem->NombreCubo.compare(ruta)>0){
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
Arbol::CargaTotal(char ruta[]){
    Lista_Matriz *Lista_M=new Lista_Matriz(ruta);
    int capa=-1;
    char archivoCapa[150];
    int primeralinea=0;


    std::fstream archivo(ruta);
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

                Lista_M->InsertarMatrizOrdenado(capa,archivoCapa);
            }
            //reinicia el contador de capa
            capa=-1;

        }
    }
    //temporal
    //Lista_M->MostrarLista(5);

}

Arbol::~Arbol()
{
    //dtor
}
