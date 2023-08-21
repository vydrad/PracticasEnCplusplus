#include <iostream>
#include <cstdlib>
#include <cstring>

using namespace std;

#include "parcialm1.h"
#include "Funciones.h"

int main(){

bool a=false;
int opc;

while(a==false){
    cout<<"1. a1) Para cada material la cantidad de compras que se hayan realizado entre todas las compras."<<endl;
    cout<<"2. a2) El nombre del proveedor que mayor importe haya obtenido entre todas las compras que se le realizaron."<<endl;
    cout<<"3. a3) Los numero de los proveedores a los que no se les compro nada el año pasado."<<endl;
    cout<<"4. a4) El gasto en obra gruesa para cada uno de las obras. (analizar bien. Es el punto mas complejo porque requiere del uso de 3 archivos)"<<endl;
    cout<<"5. a5) La/s provincia/s con mas de 22 proveedores"<<endl;
    cout<<"0. Para salir del programa"<<endl;
    cin>>opc;
    system("cls");
switch(opc){
case 1:
    Punto1();
    break;
case 2:
    Punto2();
    break;
case 3:
    Punto3();
    break;
case 4:
    Punto4();
    break;
case 5:
    Punto5();
    break;
case 6:
    break;

case 0:///a=true;
    return 0;
    break;
}

system("pause");
system("cls");
}
///return 0;

}
