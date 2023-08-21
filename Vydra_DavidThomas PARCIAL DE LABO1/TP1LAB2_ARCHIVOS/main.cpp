#include <iostream>
#include <cstdlib>
#include <cstring>
#include <ctime>

using namespace std;

#include "FuncionesCanciones.h"
#include "FuncionesInterpretes.h"
#include "FuncionesGeneros.h"
#include "FuncionesConfiguracion.h"
#include "reportes.h"
#include "clasesrec.h"
void submenuinterpretes();
void submenucanciones();
void submenugeneros();
void submenuconfiguracion();
void buscarYlistariDCanciones();



int main()
{
    int opc;
    bool a=true;

    while(a==true){
    system("cls");
    cout<<"    MENU PRINCIPAL"<<endl;
    cout<<"------------------------"<<endl;
    cout<<"1. MENU CANCIONES "<<endl;
    cout<<"2. MENU INTERPRETES"<<endl;
    cout<<"3. MENU GENEROS"<<endl;
    cout<<"4. REPORTES "<<endl;
    cout<<"5. CONFIGURACION" <<endl;
    cout<<"------------------------"<<endl;
    cout<<"0. FIN DEL PROGRAMA"<<endl;
    cout<<"********************"<<endl;
    cout<<"OPCION: ";
    cin>>opc;
    system("cls");

    switch(opc){

     case 1:

             submenucanciones();

         break;

     case 2:

             submenuinterpretes();

        break;

     case 3:

             submenugeneros();

        break;

     case 4:

             submenureportes();

        break;

     case 5:

            submenuconfiguracion();

        break;
     case 0:
         return 0;
        break;

    }///fin del switch


    } ///fin del while

}
///El ID de canción no debe repetirse en el archivo.
///El ID de intérprete debe existir en el archivo de intérpretes.
///La fecha debe ser una fecha válida, y anterior o igual a la fecha actual.
///El estado debe ser verdadero para que el sistema utilice el registro.
///La duración tiene que ser un valor positivo.
///El género musical debe ser un valor entero entre 1 y 10.
///Aclaraciones submenu CANCIONES:
///La opción AGREGAR CANCIÓN  deberá permitir ingresar de a un registro por vez.
///La opción LISTAR CANCIÓN POR ID deberá solicitar el ID y listar todos los campos del registro si éste existe, o informar si no existe.
///La opción LISTAR TODAS LAS CANCIONES  deberá listar todos los campos de todos los registros.
///La opción MODIFICAR FECHA DE ESTRENO deberá pedir un ID de canción y una fecha y cambiar la fecha de estreno de la canción con ese ID.
///La opción ELIMINAR CANCIÓN deberá solicitar el ID y realizar la baja lógica.

void submenucanciones(){

 ///Canciones vCan[5];
 ///FILE *vCan;

 int opc2;
 bool a2=true;
 while(a2==true){
 system("cls");
 cout<<"      MENU CANCIONES    "<<endl;
 cout<<"-------------------------"<<endl;
 cout<<"1. AGREGAR CANCION"<<endl; ///El ID de canción no debe repetirse en el archivo.
 cout<<"2. LISTAR CANCION POR ID "<<endl;
 cout<<"3. LISTAR TODAS LAS CANCIONES"<<endl;
 cout<<"4. MODIFICAR FECHA DE ESTRENO"<<endl;
 cout<<"5. ELIMINAR CANCION"<<endl;
 cout<<"-------------------------"<<endl;
 cout<<"0. VOLVER AL MENU PRINCIPAL"<<endl;
 cout<<"************************************"<<endl;
 cout<<"OPCION:";
 cin>>opc2;
system ("cls");
 switch(opc2){

case 1: Agregarcancion();
    break;
case 2:  buscarYlistariDCanciones();
    break;
case 3: Mostrarcancion();
    break;
case 4: ModificarFechaEstreno();
    break;
case 5: EliminarCancion();
    break;
case 0:
    a2=false;
    break;

 } /// fin del switch

 }///fin del while

}


///La opción AGREGAR INTÉRPRETE  deberá permitir ingresar de a un registro por vez.
///La opción LISTAR INTERPRETE POR ID deberá solicitar el ID y listar todos los campos del registro si éste existe.
///La opción LISTAR TODOS LOS INTÉRPRETES deberá listar todos los campos de todos los registros.
///La opción MODIFICAR GENERO MUSICAL PRINCIPAL deberá pedir un ID de intérprete y un valor de genero musical principal y reemplazar el genero musical principal en el registro con ese ID .
///La opción ELIMINAR INTÉRPRETE deberá solicitar un valor de ID y realizar la baja lógica.

void submenuinterpretes(){
 int opc3;
 bool a3=true;
 while(a3==true){
 system("cls");
 cout<<"      SUB MENU INTERPRETE    "<<endl;
 cout<<"-------------------------"<<endl;
 cout<<"1. AGREGAR INTERPRETE POR ID"<<endl;
 cout<<"2. LISTAR INTERPRETE POR ID "<<endl;
 cout<<"3. LISTAR TODOS LOS INTERPRETES "<<endl;
 cout<<"4. MODIFICAR GENERO MUSICAL PRINCIPAL"<<endl;
 cout<<"5. ELIMINAR INTERPRETE"<<endl;
 cout<<"-------------------------"<<endl;
 cout<<"0. VOLVER AL MENU PRINCIPAL"<<endl;
 cout<<"************************************"<<endl;
 cout<<"OPCIONES:";
 cin>>opc3;
system ("cls");
 switch(opc3){

    case 1:

        Agregarinterprete();

        break;

    case 2:

        buscarYlistariDinterprete();

        break;

    case 3:

        Mostrarinterprete();

        break;

    case 4:

       ModificarGeneroMusical();

        break;

    case 5:

       Eliminarinterprete();

        break;

    case 0:

        a3=false;

    break;

 }///fin switch

 }/// fin while


}

void submenugeneros(){
 int opc4;
 bool a4=true;
 while(a4==true){

 system("cls");
 cout<<"      SUB MENU GENEROS  "<<endl;
 cout<<"-------------------------"<<endl;
 cout<<"1) AGREGAR GENERO"<<endl;
 cout<<"2) LISTAR GENERO POR ID"<<endl;
 cout<<"3) LISTAR TODOS LOS GENEROS"<<endl;
 cout<<"4) MODIFICAR TIPO DE INSTRUMENTACIÓN"<<endl;
 cout<<"--------------------------------"<<endl;
cout<<"0) VOLVER AL MENU PRINCIPAL"<<endl;
cout<<"************************************"<<endl;
cout<<"OPCION:";
 cin>>opc4;
system ("cls");

 switch(opc4){

    case 1:

        Agregargenero();

        break;

    case 2:

        buscarYlistariDgenero();

        break;

    case 3:

        Mostrargenero();

        break;

    case 4:

       ModificarGeneroMusical();

        break;


    case 0:

        a4=false;

    break;

 }///fin switch
 } ///fin while

}

void submenuconfiguracion(){
     int opc5;
     bool a5=true;
     while(a5==true){

 system("cls");

    cout<<"MENU CONFIGURACION"<<endl;
    cout<<"------------------"<<endl;

    cout<<"1) COPIA DE SEGURIDAD DEL ARCHIVO DE CANCIONES"<<endl;
    cout<<"2) COPIA DE SEGURIDAD DEL ARCHIVO DE INTERPRETES"<<endl;
    cout<<"3) COPIA DE SEGURIDAD DEL ARCHIVO DE GENEROS"<<endl;
    cout<<"4) RESTAURAR EL ARCHIVO DE CANCIONES"<<endl;
    cout<<"5) RESTAURAR EL ARCHIVO DE INTERPRETES"<<endl;
    cout<<"6) RESTAURAR EL ARCHIVO DE GENEROS"<<endl;
    cout<<"7) ESTABLECER DATOS DE INICIO"<<endl;
    cout<<"--------------------------------"<<endl;
    cout<<"0) VOLVER AL MENU PRINCIPAL"<<endl;
    cout<<"************************************"<<endl;
    cout<<"OPCION:";
    cin>>opc5;

    system ("cls");

 switch(opc5){

    case 1:

        CopiarCanciones();

        break;

    case 2:

        CopiarInterpretes();

        break;

    case 3:

        CopiarGeneros();

        break;

    case 4:

        RestaurarCanciones();

        break;

    case 5:

        RestaurarInterpretes();

        break;

    case 6:

        RestaurarGeneros();

        break;

    case 7:

        DatosInicio();

        break;



    case 0:

        a5=false;

    break;

 }///fin switch
 } ///fin while
}

