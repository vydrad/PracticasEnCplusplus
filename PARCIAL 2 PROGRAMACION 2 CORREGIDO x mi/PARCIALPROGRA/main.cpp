#include <iostream>
#include <cstdlib>
#include <cstring>
#include <ctime>

using namespace std;

#include "clases.h"
bool modificarArchivo(Cliente obj, int pos);
int contarmayores50();
void Punto1();
void punto2();
void punto3();


void MostrarVector(int *v,int tam);

void MostrarVector1(int *v,int tam);
int main(){

    int opc;
    bool a=true;
    int pos=0, pos1=0,pos2=0,pos3=0, pos4=0;
    Restaurante obj1;
    Reserva obj2;

    int i=0;
    int CantidadReservasXcodigo[10]={0};
    int CategoriaRestauranteXCodigo[10]={0};
    Restaurantecat2 obj3;
    while(a==true){
    system("cls");
    cout<<"1.Generar un archivo con la cantidad de reservas que cada restaurante de la categoría 2 tuvo este año"<<endl;
    cout<<"Cada registro debe tener el siguiente formato:"<<endl;
    cout<<" Código de restaurante, nombre de restaurante, y cantidad de reservas   "<<endl;
    cout<<"2.Modificar el archivo de clientes, pasando todos los clientes de medio de pago 4 a 3.    "<<endl;
    cout<<"3.Generar un vector dinámico para copiar y mostrar los registros de los clientes que sean mayores a 50 años"<<endl;
    cout<<"------------------------"<<endl;
    cout<<"0. FIN DEL PROGRAMA"<<endl;
    cout<<"********************"<<endl;
    cout<<"OPCION: ";
    cin>>opc;
    system("cls");

    switch(opc){

     case 1:
        Punto1();
         break;
     case 2:
        punto2();
        break;
     case 3:
        punto3();
        break;
     case 0:
         return 0;
        break;

    }///fin del switch

    system("pause");
    } ///fin del while


}




void MostrarVector1(int *v,int tam){

for(int i=0;i<tam;i++){
            cout<<"RESERVAS CON CODIGO(I+1):"<<(i+1)<<" HAY: "<<v[i]<<endl;

}

}

void MostrarVector(int *v,int tam){

for(int i=0;i<tam;i++){
            cout<<"EN LA CATEGORIA (I+1):"<<(i+1)<<" HAY: "<<v[i]<<" RESERVAS"<<endl;

}

}

void Punto1(){
    Fecha Actual;
    time_t tiempo;
    struct tm *tmPtr;
    tiempo = time(NULL);
    tmPtr = localtime(&tiempo);
    Actual.setAnio(1900+tmPtr->tm_year);


    int pos=0, pos1=0,pos2=0,pos3=0, pos4=0;
    Restaurante obj1;
    Reserva obj2;

    int CantidadReservasXcodigo[10]={0};
    int CategoriaRestauranteXCodigo[10]={0};
    Restaurantecat2 obj3;
    /*///CANTIDAD DE RESTAURANTES (10 categorias)
    while(obj1.leerDeDisco(pos++)==1){
        obj1.Mostrar();
        /// if(obj1.getCategoriaRestaurante)
    }*/

    cout<<"---------------------------------------------"<<endl;
    ///  int CantidadReservasXcategoria[10]={0}; /// HAY 10 CATEGORIAS EN EL RESTAURANTE
    while(obj2.leerDeDisco(pos1++)==1){

       // if(obj2.getFechaReserva().getAnio()==Actual.getAnio()-1){/// LE RESTO 1 XQ LOS REGISTROS TIENE SOLO DE 2022 Y 2021 sino no apareceria nada
            CantidadReservasXcodigo[obj2.getCodigoRestaurante()-1]++;   /// SIQUIERO ACUMULAR TODAS LAS RESERVAS X CODIGO, NO USO IF
          ///  obj2.Mostrar();
      //  }
    }
    MostrarVector1(CantidadReservasXcodigo,10);
    cout<<"-----------------------------------"<<endl;

    int i=0;
    while (obj1.leerDeDisco(pos2++)==1){
        if(CantidadReservasXcodigo!=0){///PARA QUE ACUMULE LOS QUE NO VALEN 0 XD
            CategoriaRestauranteXCodigo[obj1.getCategoriaRestaurante()-1]+=CantidadReservasXcodigo[i];///EN UN VECTOR  FILTRADO POR CATEGORIA, GUARDAMOS CUANTAS INFRACCIONES Q TUVO CADA CATEGORIA
        }
        i++;
    }

        MostrarVector(CategoriaRestauranteXCodigo,10);
          ///  cout<<"----------------------------"<<endl;

            while(obj1.leerDeDisco(pos3++)==1){ /// LEO  LOS RESTAURANTES
                if (obj1.getCategoriaRestaurante()==2){ ///LOS RETAURANTES CATEGORIA 2 QUIERO CREAR UN ARCHIVO CON
                     ///   obj1.Mostrar();                     /// LA CANTIDAD DE RESERVAS DE CADA CODIGO DE RESTAURANTE
                    obj3.setCantidadReservas(CantidadReservasXcodigo[pos3-1]); /// en la posicion del vector de respectivo codigo
                    obj3.setNombre(obj1.getNombre());
                    obj3.setCodigoRestaurante(obj1.getCodigoRestaurante());
                    obj3.grabarEnDisco();
                }

            }

            cout<<"LOS  RESTAURANTES DE CATEGORIA 2 CON TODAS LAS RESERVAS DE ESTE ANIO SON LOS SIGUIENTES:"<<endl;

            while(obj3.leerDeDisco(pos4++)==1){

                obj3.Mostrar();
            }

    system("pause");

}

void punto2(){
    int pos1=0,pos2=0,pos3=0;
     Cliente obj4;

         ///obj4.Cargar();
     /*   while(obj4.leerDeDisco(pos2++)==1){
            obj4.Mostrar();
            }*/
            /// PARA COPIAR LOS MISMOS REGISTRO EN EL MISMO ARCHIVO, CAMBIANDO LOS QUE TIENEN 3 POR 4 XD
          while(obj4.leerDeDisco(pos1++)==1){
                  obj4.Mostrar();
                if(obj4.getMedioPago()==7){
                      ///  obj4.Mostrar();
                    obj4.setMedioPago(12);
                    obj4.modificarRegistro2(pos1-1);

                }
                else{obj4.modificarRegistro2(pos1-1);}

            }
    cout<<"-------------------------------------------------------"<<endl;
        while(obj4.leerDeDisco(pos3++)==1){
            obj4.Mostrar();
            }
        cout<<" ------"<<endl;

}



void punto3(){
    Cliente obj;
    int pos=0,pos2=0,pos1=0, tam;
    tam=contarmayores50();
    if(tam==0) {
        cout<<"  \nNO HAY REGISTROS DE MAYORES DE 50 ANIOS"<<endl;
        system("pause");
        return;

    }
    Cliente *vecCliente;
    vecCliente=new Cliente [tam];

    if(vecCliente==NULL) {
        cout<<"  \nFallo al asignar memoria"<<endl;
        system("pause");
        return;

    }
   /* obj.Cargar();
    obj.grabarEnDisco();*/

    while(obj.leerDeDisco(pos1++)){
        obj.Mostrar();
    }
    int i=0;
    cout<<"---------------"<<endl;
    while(obj.leerDeDisco(pos++)){
        if(obj.getEdad()>50){  ///COPIO LOS CLIENTES >50 EN UN VEC de Clientes, de Tam ya contado.
            vecCliente[i].setDNI(obj.getDNI());
            vecCliente[i].setEdad(obj.getEdad());
            vecCliente[i].setEstado(obj.getEstado());
            vecCliente[i].setMedioPago(obj.getMedioPago());
            vecCliente[i].setNombre(obj.getNombre());
            vecCliente[i].setTipoCliente(obj.getTipoCliente());
            i++;///COMO YA TENGO LA CANTIDAD DE >50 QUE hay, Los voy acomodando desde el 0 de a 1.
        }

    }

    for(int i=0; i<tam; i++){
        vecCliente[i].Mostrar();
    }

  delete vecCliente;

}

int contarmayores50(){
    Cliente obj;
    int pos=0, cant=0;
    while(obj.leerDeDisco(pos++)){
        if (obj.getEdad()>50){cant++;}

            }
            return cant;
        }




/* Punto 4

bool Reserva::operator==(Reserva &obj){
   if(fecha==obj.fecha)return true;
   return false;
}

*/
