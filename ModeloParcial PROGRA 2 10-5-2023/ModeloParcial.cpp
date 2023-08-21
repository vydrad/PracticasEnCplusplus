#include <iostream>
#include <stdlib.h>
#include <cstring>

using namespace std;

#include "parcialm1.h"

void MostrarVector(int *v,int tam);
void Punto1();
void Punto2();


int main(){

bool a=false;
int opc;

while(a==false){
    cout<<"1.Generar un archivo con los materiales de electricidad cuyo estado sea activo."<<endl;
    cout<<"Cada registro debe tener código de material, el nombre y la marca. "<<endl;
    cout<<"2.El estado de ejecución de las obras con más cantidad de obras "<<endl;
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

class MaterialesElectricos{
private:
    int CodigoMaterial;
    char Nombre[30];
    char Marca[30];
public:

    void setCodigoMaterial(int c){CodigoMaterial=c;}
    void setNombre(const char *n) {strcpy(Nombre,n);}
    void setMarca(const char *m){strcpy(Marca,m);}

    void Mostrar(){
    cout<<"Codigo Material :"<<CodigoMaterial<<endl;
    cout<<"Nombre: "<<Nombre<<endl;
    cout<<"Marca: "<<Marca<<endl;
    cout<<"--------------------"<<endl;
    }

    bool grabarEnDisco(){
    FILE *p;
    p=fopen("MaterialesElectricos.dat","ab");
    if(p==NULL) return false;
    bool escribio = fwrite(this, sizeof (MaterialesElectricos), 1, p);
    fclose(p);
    return escribio;
    }

    bool leerDeDisco(int pos){ //pos es la posición que ocupa el registro en el archivo, empezando por 0
    FILE *p;
    p=fopen("MaterialesElectricos.dat","rb");
    if(p==NULL) return false;
    fseek(p, pos * sizeof (MaterialesElectricos), 0); ///sizeof (Empresa) es el tamaño en bytes de un objeto Empresa en memoria
    bool leyo = fread(this, sizeof (MaterialesElectricos), 1, p);
    fclose(p);
    return leyo;
}


};
//Generar un archivo con los materiales de electricidad cuyo estado sea activo.
//Cada registro debe tener código de material, el nombre y la marca.
/// TENGO QUE CREAR UNA CLASE

void Punto1(){
Material elec;
int Cantarch;
ArchivoMaterial Archivomat("materiales.dat");/// TENGO QUE PASARLE EL NOMBRE DEL ARCHIVO DONDE VA A BUSCAR
                            ///A TRAVES DEL CONSTRUCTOR DE ArchivosMaterial
Cantarch=Archivomat.contarRegistros();
bool grabo;

MaterialesElectricos mat;

for(int i=0;i<Cantarch;i++){
elec=Archivomat.leerRegistro(i);
    if(elec.getTipo()==6&&elec.getActivo()==true){
        mat.setCodigoMaterial(elec.getCodigoMaterial());
        mat.setNombre(elec.getNombre());
        mat.setMarca(elec.getMarca());
        grabo=mat.grabarEnDisco();
        ///HABRIA QUE CREAR UN LEER DE DISCO COMO METODO DE LA CLASE QUE CREE PARA VER SI SE GRABARON CORRECTAMENTE.
        if (!grabo){
            cout<<"HUBO UN ERROR EN EL GRABADO DE MATERIALES ELECTRICOS"<<endl;}

    }

}
MaterialesElectricos obj;
int pos=0;
while(obj.leerDeDisco(pos++)==1){
        obj.Mostrar();
}

}

//El estado de ejecución de las obras con más cantidad de obras
void Punto2(){
int vecEstadoEjecucion[5]={0};
Obra obraa;
ArchivoObras archObra("obras.dat");
int cantArch;
cantArch=archObra.contarRegistros();

for(int i=0;i<cantArch;i++){
    obraa=archObra.leerRegistro(i);
    if(obraa.getActivo()){
    vecEstadoEjecucion[obraa.getEstadoEjecucion()-1]++;}

}

MostrarVector(vecEstadoEjecucion,5);
}

/// SOLO PARA VER EL VECTOR
void MostrarVector(int *v,int tam){
int posmax=v[0];
int pos=0;
for(int i=1;i<tam;i++){
    if(v[i]>posmax){
        posmax=v[i];
        pos=i;
    }
 ///   cout<<"EL VECTOR EN LA POSICION I+1="<<(i+1)<<"VALE: "<<v[i]<<endl;
}

cout<<"-------------------------------"<<endl;
cout<<"EL ESTADO DE EJECUCION CON MAS OBRAS ES EL NUMERO:"<<(pos+1)<<" CON "<<posmax<<" OBRAS"<<endl;

}

