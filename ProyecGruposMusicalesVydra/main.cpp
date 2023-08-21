#include <iostream>
#include <stdlib.h>
#include <cstring>
#include <ctime>

using namespace std;

#include "ClaseFecha.h"
#include "ClaseMusicos.h"
#include "MenuMusicos.h"
#include "ClaseGeneros.h"
#include "MenuGeneros.h"
#include "ClaseConfiguracion.h"
#include "MenuConfiguracion.h"
#include "reportes.h"
#include "MenuReportes.h"

/*     1º PARCIAL LABO II

    ALUMNO: David Thomas Vydra
    LEGAJO: 26191

*/

int main(){

bool a=false;
int opc;
do{
    cout<<"---------------------------------------------------------------- "<<endl;
    cout<<"--------------------->>> MENU PRINCIPAL <<<---------------------"<<endl;
    cout<<"---------------------------------------------------------------- "<<endl;
    cout<<" --- --- --- 1. MENU MUSICOS --- --- --- --- --- --- --- "<<endl;
    cout<<" --- --- --- 2. MENU GENEROS --- --- --- --- --- --- ---"<<endl;
    cout<<" --- --- --- 3. REPORTES --- --- --- --- --- --- --- --- "<<endl;
    cout<<" --- --- --- 4. CONFIGURACION --- --- --- --- --- --- ---"<<endl;
    cout<<" --- --- --- 0. SALIR DEL PROGRAMA --- --- --- --- --- --- "<<endl;
    cout<<"--------------------------------------------------------------- "<<endl;
    cout<<"           --- --- --- ELIJA UNA OPCION --- --- ---"<<endl;
    cout<<"--------------------------------------------------------------- "<<endl;
    cout<<"---> ";cin>>opc;
    system("cls");
    switch (opc){
        case 1:MenuMusicos();
            break;
        case 2:MenuGeneros();
            break;
        case 3:MenuReportes();
            break;
        case 4:MenuConfiguracion();
            break;
        case 0:
            cout<<"--- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- ---"<<endl;
            cout<<"--- MUCHAS GRACIAS POR HACER USO DE ESTE PROGRAMA, LE DESEO UNA BUENA JORNADA ---"<<endl;
            cout<<"--- --- --- --- --- --- --- 1ER PARCIAL LABO II --- --- --- --- --- --- --- --- ---"<<endl;
            cout<<"--- --- ALUMNO: DAVID THOMAS VYDRA -- --- --- --- --- --- ---"<<endl;
            cout<<"--- --- LEGAJO: 26191 --- --- --- --- --- --- --- --- --- ---"<<endl;
            cout<<"--- --- PROFESOR: DANIEL KLOSTER --- --- --- --- --- --- ---"<<endl;
            cout<<"--- --- PROF. AYUDANTE: MAXIMILIANO WENNER --- --- --- --- ---"<<endl;
            cout<<"--- --- --- --- --- --- --- --- --- --- --- --- --- --- PRIMER CUATRI 2023 --- ---"<<endl;
            cout<<"--- --- --- --- --- --- --- --- FIN DEL PROGRAMA --- --- --- --- --- --- --- ---"<<endl;
            return 0;
            break;
        default:
           cout<<"--- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- ---"<<endl;
            cout<<"--- USTED HA INGRESADO UNA OPCION INVALIDA, VUELVA A INTENTARLO ---"<<endl;
            cout<<"--- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- ---"<<endl;
            break;

    }

 ///system("pause");
 system("cls");
 }while(a==false);


}
