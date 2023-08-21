#include <iostream>
#include <stdlib.h>
#include <cstring>

using namespace std;

#include "parcial1.h"

void Punto1();
void Punto2();

// Alumno: David Thomas Vydra
// Legajo: 26191
// Materia: Laboratorio II

int main(){

bool a=false;
int opc;

while(a==false){
    cout<<"1. Generar un archivo con los proyectos en estado de desarrollo en estudio con presupuesto menor a $50.000."<<endl;
    cout<<"   Cada registro debe tener el siguiente formato:"<<endl;
    cout<<"   Codigo, nombre y  fecha."<<endl;
    cout<<"   ----"<<endl;
    cout<<"2. Listar las categorias de tareas con mas de 2 tareas."<<endl;
    cout<<" "<<endl;
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
case 0:///a=true;
    return 0;
    break;
}

system("pause");
system("cls");
}

///return 0;

}

class Proyecto50{
public:
    char Codigo[30];
    char Nombre[30];
    Fecha fecha;
private:

    void setCodigo(const char *c){strcpy(Codigo,c);}
    void setNombre(const char *n) {strcpy(Nombre,n);}
    void setfecha(Fecha f){fecha=f;}


        void Mostrar(){
        cout<<"CODIGO:"<<Codigo<<endl;
        cout<<"NOMBRE: "<<Nombre<<endl;
        cout<<"FECHA:"<<endl;
        fecha.Mostrar();
        cout<<endl;
        }

    bool grabarEnDisco(){
    FILE *p;
    p=fopen("proyectos1.dat","ab");
    if(p==NULL) return false;
    bool escribio = fwrite(this, sizeof (Proyecto50), 1, p);
    fclose(p);
    return escribio;
    }

    bool leerDeDisco(int pos){
	FILE *p;
    p=fopen("proyectos1.dat","rb");
    if(p==NULL) return false;
    fseek(p, pos * sizeof (Proyecto50), 0);
    bool leyo = fread(this, sizeof (Proyecto50), 1, p);
    fclose(p);
    return leyo;
    }

};



//    1. Generar un archivo con los proyectos en estado de desarrollo en estudio con presupuesto menor a $50.000
//   Cada registro debe tener el siguiente formato:"<<endl;
//  Codigo, nombre y  fecha."<<endl;
void Punto1(){
ArchivoProyecto archiProyect("proyectos.dat");
Proyecto proyec;
Proyecto50 proyect2;


int cant=archiProyect.contarRegistros();
for(int i=0; i<cant;i++){
    proyec=archiProyect.leerRegistro(i);
    if(proyec.getEstadoDesarrollo()==1){
        if(proyec.getPresupuesto()<50000 && proyec.getActivo()){
            proyect2.setCodigo(proyec.getCodigoProyecto());
            proyect2.setNombre(proyec.getNombre());
            proyect2.setfecha(proyec.getFechaInicio());
            proyect2.grabarEnDisco();
        }

    }
}


}

//Listar las categorías de tareas con más de 2 tareas.
void Punto2(){
ArchivoTarea archiTarea("tareas.dat");
Tarea tareita;

int cant1=archiTarea.contarRegistros();
int vecTareas[5]={0};
for(int i=0;i<cant1;i++){
    tareita=archiTarea.leerRegistro(i);
    vecTareas[tareita.getCategoria()-1]++; ///
}

int cont=0;
for(int e=0;e<5;e++){
    if(vecTareas[e]>2){
            cont++;
    cout<<"La categoria: "<<(e+1)<<" POSEE Mas de 2 tareas, posee: "<< vecTareas[e]<<endl;

    }
}

if(cont ==0){
    cout<<"NO SE ENCONTRO NINGUNA CATEGORIA CON MAS DE 2 TAREAS"<<endl;
}
}

