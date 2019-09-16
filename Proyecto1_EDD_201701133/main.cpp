#include <iostream>
#include <stdlib.h>
#include <string>
#include <fstream>
#include <sstream>
#include <direct.h>

#include<Arbol.h>
#include<Lista_Filtros.h>
#include<Lista_Matriz.h>
#include<Nodo_Matriz.h>


using namespace std;
void RotarImagenCompletaX(Lista_Matriz *Cubo,Nodo_Matriz*matri){
    if(matri!=0){
            //inserccion de filtro
        char nombretem[200];
        int posz=matri->Z;
        strcpy(nombretem, matri->NombreDocumento.c_str());
        //llamamos al metodo recursivo
        RotarImagenCompletaX(Cubo,matri->siguiente);
        //creamos un nuevo nodo con los datos de la matriz
        Nodo_Matriz *nuevo=new Nodo_Matriz(posz,nombretem);
        matri->Xmirror(nuevo,Cubo->image_width);
        //eliminamos el nodo de la matrizdispesa
        Cubo->Eliminar(posz);
        //insertamos el nuevo nodo
        Cubo->InsertarMatrizSinCarga(posz,nombretem,nuevo);

    }
}
void RotarImagenCompletaY(Lista_Matriz *Cubo,Nodo_Matriz*matri){
    if(matri!=0){
            //inserccion de filtro
        char nombretem[200];
        int posz=matri->Z;
        strcpy(nombretem, matri->NombreDocumento.c_str());
        //llamamos al metodo recursivo
        RotarImagenCompletaY(Cubo,matri->siguiente);
        //creamos un nuevo nodo con los datos de la matriz
        Nodo_Matriz *nuevo=new Nodo_Matriz(posz,nombretem);
        matri->Ymirror(nuevo,Cubo->image_height);
        //eliminamos el nodo de la matrizdispesa
        Cubo->Eliminar(posz);
        //insertamos el nuevo nodo
        Cubo->InsertarMatrizSinCarga(posz,nombretem,nuevo);

    }
}
int main()
{
    int ciclomenu=0;
    cout << "Proyecto 1 de estructura de datos 201701133" << endl;
    //temporal
    Arbol*arbol=new Arbol();
    Lista_Filtros *Filtro=0;
    Lista_Matriz *Cuboseleccionado=0;


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
            Filtro=new Lista_Filtros();

            arbol->MostrarInorden(arbol->Raiz);
            cout <<" Seleccione una imagen "<<endl;
            string seleccionado;
            cin>>seleccionado;
            //primero buscar en el arbol
            Cuboseleccionado=0;
            Cuboseleccionado=arbol->BuscarSeleccion(seleccionado,arbol->Raiz,Cuboseleccionado);
            if(Cuboseleccionado!=0){
                cout <<" Imagen Seleccionada "<< Cuboseleccionado->NombreCubo<<endl;
            }else{
                cout <<" Imagen No Encontrada"<<endl;
            }

        }
        if(opcionmenu==3){
            cout <<"    Seleccione un Filtro"<<endl;
            cout <<"    1.Negative"<<endl;
            cout <<"    2.Grayscale"<<endl;
            cout <<"    3.Mirror"<<endl;
            cout <<"    4.Collage"<<endl;
            cout <<"    5.Mosaic"<<endl;
            int opcionfiltro;
            cin>>opcionfiltro;
            if(opcionfiltro==1){
                cout <<"    1. Capas"<<endl;
                cout <<"    2. Imagen Completa"<<endl;
                int opcionfiltro2;
                cin>>opcionfiltro2;
                if(opcionfiltro2==1){

                    Cuboseleccionado->MostrarLista(-1);
                    cout <<"Seleccione una Capa"<<endl;
                    int opcionfiltrocapa;
                    cin>>opcionfiltrocapa;

                    Nodo_Matriz*matriz=Cuboseleccionado->inicio;
                    matriz=matriz->siguiente;
                    while(matriz!=0){
                        if(matriz->Z==opcionfiltrocapa){
                            matriz->Negativo();
                            break;
                        }
                        matriz=matriz->siguiente;
                    }

                    Filtro->Insertar("Negative",opcionfiltrocapa);
                }
                if(opcionfiltro2==2){
                    Nodo_Matriz*matriz=Cuboseleccionado->inicio;
                    matriz=matriz->siguiente;
                    while(matriz!=0){
                        matriz->Negativo();
                        matriz=matriz->siguiente;
                    }
                    Filtro->Insertar("Negative",-1);
                }

                cout <<"Se Inserto Negative"<<endl;

                system("pause");
            }
            if(opcionfiltro==2){
                cout <<"    1. Capas"<<endl;
                cout <<"    2. Imagen Completa"<<endl;
                int opcionfiltro2;
                cin>>opcionfiltro2;
                if(opcionfiltro2==1){

                    Cuboseleccionado->MostrarLista(-1);
                    cout <<"Seleccione una Capa"<<endl;
                    int opcionfiltrocapa;
                    cin>>opcionfiltrocapa;

                    Nodo_Matriz*matriz=Cuboseleccionado->inicio;
                    matriz=matriz->siguiente;
                    while(matriz!=0){
                        if(matriz->Z==opcionfiltrocapa){
                            matriz->EscalaGris();
                            break;
                        }
                        matriz=matriz->siguiente;
                    }

                    Filtro->Insertar("Grayscale",opcionfiltrocapa);
                }
                if(opcionfiltro2==2){
                    Nodo_Matriz*matriz=Cuboseleccionado->inicio;
                    matriz=matriz->siguiente;
                    while(matriz!=0){
                        matriz->EscalaGris();
                        matriz=matriz->siguiente;
                    }

                    Filtro->Insertar("Grayscale",-1);
                }
                cout <<"Se Inserto Grayscale"<<endl;
                system("pause");
            }
            if(opcionfiltro==3){
                cout <<"    1.X-Mirror"<<endl;
                cout <<"    2.Y-Mirror"<<endl;
                cout <<"    3.Double-Mirror"<<endl;
                int opMirror;
                cin>>opMirror;
                if(opMirror==1){
                    //mirror en x

                    cout <<"    1. Capas"<<endl;
                    cout <<"    2. Imagen Completa"<<endl;
                    int opcionfiltro2;
                    cin>>opcionfiltro2;
                    if(opcionfiltro2==1){

                        Cuboseleccionado->MostrarLista(-1);
                        cout <<"Seleccione una Capa"<<endl;
                        int opcionfiltrocapa;
                        cin>>opcionfiltrocapa;

                        Nodo_Matriz*matriz=Cuboseleccionado->inicio;
                        matriz=matriz->siguiente;
                        while(matriz!=0){
                            if(matriz->Z==opcionfiltrocapa){
                                //nombre
                                char nombretem[200];
                                int posz=matriz->Z;
                                strcpy(nombretem, matriz->NombreDocumento.c_str());
                                //creamos un nuevo nodo con los datos de la matriz
                                Nodo_Matriz *nuevo=new Nodo_Matriz(posz,nombretem);
                                matriz->Xmirror(nuevo,Cuboseleccionado->image_width);
                                //eliminamos el nodo de la matrizdispesa
                                Cuboseleccionado->Eliminar(opcionfiltrocapa);
                                //insertamos el nuevo nodo
                                Cuboseleccionado->InsertarMatrizSinCarga(posz,nombretem,nuevo);

                                break;
                            }
                            matriz=matriz->siguiente;
                        }

                        Filtro->Insertar("X-Mirror",opcionfiltrocapa);
                    }

                    if(opcionfiltro2==2){
                        Nodo_Matriz*matriz=Cuboseleccionado->inicio;
                        matriz=matriz->siguiente;
                        //aplicamos el metodo de rotar completa
                        RotarImagenCompletaX(Cuboseleccionado,matriz);

                        Filtro->Insertar("X-Mirror",-1);
                    }

                    cout <<"Se Inserto X-Mirror"<<endl;
                    //Filtro->Insertar("X-Mirror");
                    system("pause");
                }


                if(opMirror==2){
                    //mirror en y

                    cout <<"    1. Capas"<<endl;
                    cout <<"    2. Imagen Completa"<<endl;
                    int opcionfiltro2;
                    cin>>opcionfiltro2;
                    if(opcionfiltro2==1){

                        Cuboseleccionado->MostrarLista(-1);
                        cout <<"Seleccione una Capa"<<endl;
                        int opcionfiltrocapa;
                        cin>>opcionfiltrocapa;

                        Nodo_Matriz*matriz=Cuboseleccionado->inicio;
                        matriz=matriz->siguiente;
                        while(matriz!=0){
                            if(matriz->Z==opcionfiltrocapa){
                                //nombre
                                char nombretem[200];
                                int posz=matriz->Z;
                                strcpy(nombretem, matriz->NombreDocumento.c_str());
                                //creamos un nuevo nodo con los datos de la matriz
                                Nodo_Matriz *nuevo=new Nodo_Matriz(posz,nombretem);

                                matriz->Ymirror(nuevo,Cuboseleccionado->image_height);
                                printf("Crea  Nuevo nodo");
                                //eliminamos el nodo de la matrizdispesa
                                Cuboseleccionado->Eliminar(opcionfiltrocapa);
                                //insertamos el nuevo nodo
                                Cuboseleccionado->InsertarMatrizSinCarga(posz,nombretem,nuevo);

                                break;
                            }
                            matriz=matriz->siguiente;
                        }

                        Filtro->Insertar("Y-Mirror",opcionfiltrocapa);
                    }

                    if(opcionfiltro2==2){
                        Nodo_Matriz*matriz=Cuboseleccionado->inicio;
                        matriz=matriz->siguiente;
                        //aplicamos el metodo de rotar completa
                        RotarImagenCompletaY(Cuboseleccionado,matriz);

                        Filtro->Insertar("Y-Mirror",-1);
                    }

                    //mirror en y
                    cout <<"Se Inserto Y-Mirror"<<endl;
                    //Filtro->Insertar("Y-Mirror");
                    system("pause");
                }
                if(opMirror==3){
                    //mirror de los dos

                    cout <<"    1. Capas"<<endl;
                    cout <<"    2. Imagen Completa"<<endl;
                    int opcionfiltro2;
                    cin>>opcionfiltro2;
                    if(opcionfiltro2==1){

                        Cuboseleccionado->MostrarLista(-1);
                        cout <<"Seleccione una Capa"<<endl;
                        int opcionfiltrocapa;
                        cin>>opcionfiltrocapa;

                        Nodo_Matriz*matriz=Cuboseleccionado->inicio;
                        matriz=matriz->siguiente;
                        while(matriz!=0){
                            if(matriz->Z==opcionfiltrocapa){
                                //nombre
                                char nombretem[200];
                                int posz=matriz->Z;
                                strcpy(nombretem, matriz->NombreDocumento.c_str());
                                //creamos un nuevo nodo con los datos de la matriz
                                Nodo_Matriz *nuevo=new Nodo_Matriz(posz,nombretem);

                                matriz->Xmirror(nuevo,Cuboseleccionado->image_width);
                                matriz->Ymirror(nuevo,Cuboseleccionado->image_height);
                                printf("Crea  Nuevo nodo");
                                //eliminamos el nodo de la matrizdispesa
                                Cuboseleccionado->Eliminar(opcionfiltrocapa);
                                //insertamos el nuevo nodo
                                Cuboseleccionado->InsertarMatrizSinCarga(posz,nombretem,nuevo);

                                break;
                            }
                            matriz=matriz->siguiente;
                        }

                        Filtro->Insertar("XY-Mirror",opcionfiltrocapa);
                    }

                    if(opcionfiltro2==2){
                        Nodo_Matriz*matriz=Cuboseleccionado->inicio;
                        matriz=matriz->siguiente;
                        //aplicamos el metodo de rotar completa
                        RotarImagenCompletaY(Cuboseleccionado,matriz);
                        RotarImagenCompletaX(Cuboseleccionado,matriz);

                        Filtro->Insertar("XY-Mirror",-1);
                    }

                    cout <<"Se Inserto Double-Mirror"<<endl;
                    //Filtro->Insertar("Double-Mirror");
                    system("pause");
                }
            }
            if(opcionfiltro==4){
                cout <<"Se Inserto Collage"<<endl;
                //Filtro->Insertar("Collage");
                system("pause");
            }
            if(opcionfiltro==5){
                cout <<"Se Inserto Mosaic"<<endl;
                //Filtro->Insertar("Mosaic");
                system("pause");
            }

        }

        if(opcionmenu==4){
            //edicion manual
            cout <<"EDICION MANUAL"<<endl;
            cout <<"    1.Imagen Original"<<endl;
            cout <<"    2.Filtros"<<endl;
            int opcionmenu4;
            std::cin>>opcionmenu4;
            if(opcionmenu4==1){
                arbol->MostrarInorden(arbol->Raiz);
                cout <<"Seleccione el nombre de una imagen"<<endl;
                string seleccionad;
                cin>>seleccionad;
                arbol->BuscarArbol(-1,seleccionad,arbol->Raiz);
                cout <<"Ingrese ID de la capa"<<endl;
                int id;
                cin>>id;
                cout <<"Ingrese Posicion X"<<endl;
                int idx;
                cin>>idx;
                cout <<"Ingrese Posicion Y"<<endl;
                int idy;
                cin>>idy;
                cout <<"Ingrese Color R"<<endl;
                int idr;
                cin>>idr;
                cout <<"Ingrese Color G"<<endl;
                int idg;
                cin>>idg;
                cout <<"Ingrese Color B"<<endl;
                int idb;
                cin>>idb;
                arbol->BuscayModifica(id,seleccionad,arbol->Raiz,idx,idy,idr,idg,idb);


            }
            if(opcionmenu4==2){
                if(Filtro==0){
                    cout <<"NO HAY IMAGEN SELECCIONADA"<<endl;
                }else{
                    if(Filtro->inicio==0){
                        cout <<"NO HAY FILTROS AGREGADOS"<<endl;
                        system("pause");
                    }else{
                        Filtro->MostrarFiltros(-1,Cuboseleccionado,0);
                        cout <<"Seleccione un filtro"<<endl;
                        int filtroselecci;
                        std::cin>>filtroselecci;
                        Filtro->MostrarFiltros(0,Cuboseleccionado,filtroselecci);
                        cout <<"Nota: Recomendado Colocar nodo ya existente o no crear nodo anterior en Y"<<endl;
                        cout <<"Ingrese ID de la capa"<<endl;
                        int id;
                        cin>>id;
                        cout <<"Ingrese Posicion X"<<endl;
                        int idx;
                        cin>>idx;
                        cout <<"Ingrese Posicion Y"<<endl;
                        int idy;
                        cin>>idy;
                        cout <<"Ingrese Color R"<<endl;
                        int idr;
                        cin>>idr;
                        cout <<"Ingrese Color G"<<endl;
                        int idg;
                        cin>>idg;
                        cout <<"Ingrese Color B"<<endl;
                        int idb;
                        cin>>idb;
                        Cuboseleccionado->BuscaryModificarMatriz(id,"Cambio",idx,idy,idr,idg,idb);

                    }
                }
            }


        }
        if(opcionmenu==5){
            if(Cuboseleccionado==0){
                cout <<" No se ha seleccionado una imagen "<<endl;
                }else{
                                //creacion de la carpeta con el nombre
                char rutaImagen[100]="Exports/";
                strcat(rutaImagen, Cuboseleccionado->NombreCubo.c_str());
                mkdir(rutaImagen);
                //creacion del html
                char rutahtml[100]="Exports/";
                strcat(rutahtml, Cuboseleccionado->NombreCubo.c_str());
                strcat(rutahtml, "/");
                strcat(rutahtml, Cuboseleccionado->NombreCubo.c_str());
                strcat(rutahtml, ".html");

                std::ofstream filehtml;
                filehtml.open(rutahtml);
                //creacion del codigo
                string cadena;
                cadena="<!DOCTYPE html> \n";
                cadena+="<html>\n<head>\n";
                cadena+="<link rel=\"stylesheet\" href=\""+Cuboseleccionado->NombreCubo +".css\">\n</head> \n";
                cadena+="<body>\n";
                cadena+="<div class=\"canvas\">\n";
                //creacion de todos los divs
                int numeroPix=Cuboseleccionado->image_width*Cuboseleccionado->image_height;
                for(int i=1;i<=numeroPix;i++){
                    cadena+="<div class=\"pixel\"></div>\n";
                }
                //fin de creacion de todos los divs
                cadena+="</div>\n";
                cadena+="</body>\n";
                cadena+="</html>\n";
                filehtml<<cadena;
                filehtml.close();


                //creacion del css
                char rutacss[100]="Exports/";
                strcat(rutacss, Cuboseleccionado->NombreCubo.c_str());
                strcat(rutacss, "/");
                strcat(rutacss, Cuboseleccionado->NombreCubo.c_str());
                strcat(rutacss, ".css");
                std::ofstream filecss;
                filecss.open(rutacss);
                string cadenacss;

                //creacion de datos
                int TamPixelW=Cuboseleccionado->image_width*Cuboseleccionado->pixel_width;
                int TamPixelH=Cuboseleccionado->image_height*Cuboseleccionado->pixel_height;
                std::stringstream ss;
                std::string sW;
                ss.str(std::string());
                ss.clear();
                ss<<TamPixelW;
                ss>>sW;
                //para el tamaño pixel altura
                std::stringstream ss2;
                std::string sH;
                ss2.str(std::string());
                ss2.clear();
                ss2<<TamPixelH;
                ss2>>sH;
                //para el tamaño imagen ancho
                std::stringstream sw;
                std::string siw;
                sw.str(std::string());
                sw.clear();
                sw<<Cuboseleccionado->pixel_width;
                sw>>siw;
                //para el tamaño imagen altura
                std::stringstream sh;
                std::string sih;
                sh.str(std::string());
                sh.clear();
                sh<<Cuboseleccionado->pixel_height;
                sh>>sih;


                cadenacss="body {\n";
                cadenacss+="background-color: rgba(0, 0, 0, 0);\n";
                cadenacss+="height: 100vh;\n";
                cadenacss+="display: flex;\n";
                cadenacss+="justify-content: center;\n";
                cadenacss+="align-items: center;\n ";
                cadenacss+="}\n";
                cadenacss+=".canvas {\n";
                cadenacss+="width:"+sW+"px;\n";
                cadenacss+="height:"+sH+"px;\n";
                cadenacss+="}\n";
                cadenacss+=".pixel {\n";
                cadenacss+="width:"+siw+"px;\n";
                cadenacss+="height:"+sih+"px;\n";
                cadenacss+="float: left;\n";
                cadenacss+="box-shadow: 0px 0px 1px #fff; }\n";

                //creacion de los nodos pixeles
                Nodo_Matriz*matriz=Cuboseleccionado->inicio;
                matriz=matriz->siguiente;
                while(matriz!=0){
                    //empieza a pintar por capas
                    Nodo_Color*tem=matriz->inicio;
                    Nodo_Color*tem2;
                    tem=tem->siguiente;
                    while(tem!=0){
                        tem2=tem;
                        tem2=tem2->abajo;
                        while(tem2!=0){
                            int resultado=((Cuboseleccionado->image_width)*(tem2->Y-1))+tem2->X;
                            std::stringstream s;
                            std::string rest;
                            s.str(std::string());
                            s.clear();
                            s<<resultado;
                            s>>rest;

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

                            cadenacss+=".pixel:nth-child("+rest+"){\n";
                            cadenacss+="background-color: rgba("+tr+","+tg+","+tb+", 1);\n";
                            cadenacss+="}\n";
                            tem2=tem2->abajo;
                        }
                        tem=tem->siguiente;
                    }

                    matriz=matriz->siguiente;
                }



                cadenacss+="";

                filecss<<cadenacss;
                filecss.close();
                char cadenaejecucion[200]="start Exports/";
                strcat(cadenaejecucion, Cuboseleccionado->NombreCubo.c_str());
                strcat(cadenaejecucion, "/");
                strcat(cadenaejecucion, Cuboseleccionado->NombreCubo.c_str());
                strcat(cadenaejecucion, ".html");
                system(cadenaejecucion);
            }

        }

        if(opcionmenu==6){
            cout <<"    1.Imorted Imagen Report"<<endl;
            cout <<"    2.Image Layer Report"<<endl;
            cout <<"    3.Liner Matriz Report"<<endl;
            cout <<"    4.Traversal Report"<<endl;
            cout <<"    5.Filter Report"<<endl;
            int opcionmenu2;
            std::cin>>opcionmenu2;
            if(opcionmenu2==1){
                cout <<"Se Grafico Arbol"<<endl;
                if(arbol->Raiz==0){
                    cout <<"No hay imagenes ingresadas"<<endl;
                }else{
                    arbol->GraficarARBOL();
                    system("pause");
                }

            }
            if(opcionmenu2==2){
                cout <<"Escriba el Nombre de la imagen a seleccionar"<<endl;
                arbol->MostrarInorden(arbol->Raiz);
                string name;
                cin>>name;

                //cout <<"    1.Graficar Todos"<<endl;
                cout <<"    1.Graficar Capa y Graficar Todos"<<endl;
                int opciontodos;
                cin>>opciontodos;
                if(opciontodos==1){
                    //variable del ciclo
                    int v=0;
                    while(v==0){
                        system("cls");
                        arbol->BuscarArbol(-1,name,arbol->Raiz);
                        cout <<"Ingrese ID de la capa"<<endl;
                        int id;
                        cin>>id;
                        arbol->BuscarArbol(id,name,arbol->Raiz);
                        cout <<"    Si desea salir presione -1 "<<endl;
                        cout <<"    Si NO desea salir presione 0 "<<endl;
                        int  finCiclo;
                        cin>>finCiclo;
                        if(finCiclo==-1){
                            v=1;
                            finCiclo=0;
                        }
                    }
                    //fin del ciclo
                }

            }
            if(opcionmenu2==3){
                cout <<"Escriba el Nombre de la imagen a seleccionar"<<endl;
                arbol->MostrarInorden(arbol->Raiz);
                string name;
                cin>>name;
                                    //variable del ciclo
                int v=0;
                while(v==0){
                    system("cls");
                    arbol->BuscarArbolLineal(0,-1,name,arbol->Raiz);
                    cout <<"Ingrese ID de la capa"<<endl;
                    int id;
                    cin>>id;

                    cout <<"1. Graficar Linealizacion por Filas"<<endl;
                    cout <<"2. Graficar Linealizacion por Columnas"<<endl;
                    int graf;
                    cin>>graf;
                    if(graf==1){
                        arbol->BuscarArbolLineal(1,id,name,arbol->Raiz);
                    }
                    if(graf==2){
                        arbol->BuscarArbolLineal(2,id,name,arbol->Raiz);
                    }



                    cout <<"    Si desea salir presione -1 "<<endl;
                    cout <<"    Si NO desea salir presione 0 "<<endl;
                    int  finCiclo;
                    cin>>finCiclo;
                    if(finCiclo==-1){
                        v=1;
                        finCiclo=0;
                    }
                }
                    //fin del ciclo
            }
            if(opcionmenu2==4){
                cout <<"    1.Inorden Traversal"<<endl;
                cout <<"    2.Preorden Traversal"<<endl;
                cout <<"    3.Postorden Traversal"<<endl;
                cout <<"    4.Salir"<<endl;
                int menuopc;
                std::cin>>menuopc;
                if(menuopc==1){
                    cout <<"Se Grafico Inorden Traversal"<<endl;
                    arbol->GraficaInorden();
                    system("pause");
                }
                if(menuopc==2){
                    cout <<"Se Grafico Preorden Traversal"<<endl;
                    arbol->GraficaProrden();
                    system("pause");
                }
                if(menuopc==3){
                    cout <<"Se Grafico Postorden Traversal"<<endl;
                    arbol->GraficaPsorden();
                    system("pause");
                }
            }
            if(opcionmenu2==5){
                cout <<"    1.All Filter Report"<<endl;
                cout <<"    2.Individual Filter Report"<<endl;
                int opcionfiltro;
                std::cin>>opcionfiltro;
                if(opcionfiltro==1){
                    if(Filtro==0){
                        cout <<"NO HAY IMAGEN SELECCIONADA"<<endl;
                    }else{
                        if(Filtro->inicio==0){
                            cout <<"NO HAY FILTROS AGREGADOS"<<endl;
                            system("pause");
                        }else{
                            cout <<"Se Grafico Lista Doble Filtro"<<endl;
                            Filtro->GraficarFiltro();
                            system("pause");
                        }
                    }
                }

                if(opcionfiltro==2){
                    //variable del ciclo
                    int v=0;
                    while(v==0){
                        system("cls");
                        //arbol->BuscarArbol(-1,name,arbol->Raiz);
                        Cuboseleccionado->MostrarLista(-1);
                        cout <<"Ingrese ID de la capa"<<endl;
                        int id;
                        cin>>id;
                        //arbol->BuscarArbol(id,name,arbol->Raiz);
                        cout <<"    Si desea salir presione -1 "<<endl;
                        cout <<"    Si NO desea salir presione 0 "<<endl;
                        Cuboseleccionado->MostrarLista(id);
                        int  finCiclo;
                        cin>>finCiclo;
                        if(finCiclo==-1){
                            v=1;
                            finCiclo=0;
                        }
                    }
                    //fin del ciclo
                }

            }
        }
        if(opcionmenu==7){
            ciclomenu=1;
        }

    }
    return 0;
}
