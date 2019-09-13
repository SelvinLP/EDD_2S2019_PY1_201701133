#include <iostream>
#include <stdlib.h>
#include <string>
#include <fstream>
#include <sstream>
#include <direct.h>

#include<Arbol.h>
#include<Lista_Filtros.h>
#include<Lista_Matriz.h>


using namespace std;

int main()
{
    int ciclomenu=0;
    cout << "Proyecto 1 de estructura de datos 201701133" << endl;
    //temporal
    Arbol*arbol=new Arbol();
    Lista_Filtros *Filtro=0;
    Lista_Matriz *Cuboseleccionado;


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
            Cuboseleccionado=arbol->BuscarSeleccion(seleccionado,arbol->Raiz);

            cout <<" Imagen Seleccionada "<< Cuboseleccionado->NombreCubo<<endl;
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
                cout <<"Se Inserto Negative"<<endl;
                Filtro->Insertar("Negative");
                system("pause");
            }
            if(opcionfiltro==2){
                cout <<"Se Inserto Grayscale"<<endl;
                Filtro->Insertar("Grayscale");
                system("pause");
            }
            if(opcionfiltro==3){
                cout <<"    1.X-Mirror"<<endl;
                cout <<"    2.Y-Mirror"<<endl;
                cout <<"    3.Double-Mirror"<<endl;
                int opMirror;
                cin>>opMirror;
                if(opcionfiltro==1){
                    //mirror en x
                    cout <<"Se Inserto X-Mirror"<<endl;
                    Filtro->Insertar("X-Mirror");
                    system("pause");
                }
                if(opcionfiltro==2){
                    //mirror en y
                    cout <<"Se Inserto Y-Mirror"<<endl;
                    Filtro->Insertar("Y-Mirror");
                    system("pause");
                }
                if(opcionfiltro==3){
                    //mirror de los dos
                    cout <<"Se Inserto Double-Mirror"<<endl;
                    Filtro->Insertar("Double-Mirror");
                    system("pause");
                }
            }
            if(opcionfiltro==4){
                cout <<"Se Inserto Collage"<<endl;
                Filtro->Insertar("Collage");
                system("pause");
            }
            if(opcionfiltro==5){
                cout <<"Se Inserto Mosaic"<<endl;
                Filtro->Insertar("Mosaic");
                system("pause");
            }

        }

        if(opcionmenu==5){


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
            //para el tama�o pixel altura
            std::stringstream ss2;
            std::string sH;
            ss2.str(std::string());
            ss2.clear();
            ss2<<TamPixelH;
            ss2>>sH;
            //para el tama�o imagen ancho
            std::stringstream sw;
            std::string siw;
            sw.str(std::string());
            sw.clear();
            sw<<Cuboseleccionado->pixel_width;
            sw>>siw;
            //para el tama�o imagen altura
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
            cadenacss+="}\n";
            cadenacss+=".pixel:nth-child(1){\n";
            cadenacss+="background-color: rgba(0, 220, 0, 1);\n";
            cadenacss+="}\n";
            cadenacss+="";

            filecss<<cadenacss;
            filecss.close();

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
                cout <<"Se Grafico Arbol"<<endl;
                arbol->GraficarARBOL();
                system("pause");
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

                }

            }
        }
        if(opcionmenu==7){
            ciclomenu=1;
        }

    }
    return 0;
}
